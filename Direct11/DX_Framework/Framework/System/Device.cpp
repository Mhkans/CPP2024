#include "framework.h"
#include "Device.h"

Device* Device::instance = nullptr;

UINT width = WIN_WIDTH;
UINT height = WIN_HEIGHT;

Device::Device() 
{
    // DX의 기본 환경을 세팅해주는 함수들을 순차적으로 호출
    CreateDeviceAndSwapChain(); // DX의 디바이스, 디바이스 컨텍스트, 스왑체인을 생성하는 함수
    CreateBackBuffer(); // 전용 백버퍼를 생성하는 함수
    SetViewPoint(); // 뷰포트를 세팅하는 함수 - 지금 당장 이게 무엇인지 이해할 필요는 없음
}

Device::~Device()
{
    device->Release();
    device_context->Release();

    swap_chain->Release();
    render_target_view->Release();
}

void Device::CreateDeviceAndSwapChain()
// 더블 버퍼링 관련 설정을 초기화하는 동시에,
// Device 그 자체도 초기화하는 함수
{
    DXGI_SWAP_CHAIN_DESC sd = {};
    // 백버퍼 관련 설정을 저장해두는 인스턴스
    // 이렇게 선언해둔 뒤 아래의 내용들을 입력하여 백버퍼를 동적 할당할 떄 사용하는 옵션 데이터

    sd.BufferCount = 1; // 사용할 백버퍼의 개수 - 2D에선 웬만하면 1으로 고정

    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    // 백버퍼가 다룰 화면의 크기

    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    // 백버퍼가 다룰 그래픽이 사용하는 색상의 규격을 정리한 것
    // R8G8B8A8 = Red 8비트, Green 8bit, Blue 8bit, Alpha값 8bit로 총 32비트의 값을 이용해 출력하는 것
    // 뒤의 UNORM은 저 데이터가 저장되어있는 형식(int인지 float인지 등등)

    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    // 초당 프레임과 관련된 설정, 정확히는 초당 주사율과 관련된 설정
    // 다만, 화면 주사율을 60hz에서 바꿀 일이 없기 떄문에 그냥 이 값으로 유지한다 생각할 것

    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    // 이 버퍼가 어디에 사용될 것인지 그 용도를 기억하는 값

    sd.OutputWindow = hWnd;
    // 이 백버퍼가 그림을 출력할 창이 어느 창인지 정의하는 부분
    // 이것만큼은 프로젝트 메인 코드에서 선언된 걸 가져와 써야 하므로,
    // 반드시 해당 변수를 extern으로서 선언하여 여기서 쓸 수 있게 만들어야 함

    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    // 3D 쪽에서 사용하는 기능이라 우리는 쓸 일 없는 기능

    sd.Windowed = true;
    // 창모드 여부를 결정하는 멤버

    D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        0,
        D3D11_CREATE_DEVICE_DEBUG,
        nullptr,
        0,
        D3D11_SDK_VERSION,
        &sd,
        &swap_chain,
        &device,
        nullptr,
        &device_context
    );
    // 그렇게 설정된 sd를 이용해서 더블 버퍼링 용 스왑체인, DX를 활용하기 위한 device와 device_context를
    // 한 번에 초기화
}

void Device::CreateBackBuffer()
// 더블버퍼링 용 백버퍼를 초기화하고, 이를 디바이스에 등록하는 함수
{
    ID3D11Texture2D* backBuffer = nullptr;

    swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
    device->CreateRenderTargetView(backBuffer, nullptr, &render_target_view);
    // 여기까지 스왑체인과 디바이스 각각에 백버퍼를 설정해주는 코드

    backBuffer->Release();

    device_context->OMSetRenderTargets(1, &render_target_view, nullptr);
    // 설정된 백버퍼를 실제로 그림 그리는 부분을 총괄하는 device_context에 등록

    // API 쪽에선 우리가 직접 백버퍼를 이런저런 매개변수를 동원해서 교체해줘야 했으나,
    // DX에서는 처음에 실행할 때만 이거저거 설정해주고
    // 나중에 백버퍼를 교체할 때는 간단한 함수 하나만 호출해주는 것으로 끝낼 수 있음
    // 그게 밑에 있는 Present
}

void Device::SetViewPoint()
// 뷰포트를 설정하는 함수
{
    // 2D보다는 3D에서 더 자주 사용할 내용이므로
    // 여기서는 그냥 이런 게 있다 정도로만 기억해도 별 문제 X
    D3D11_VIEWPORT viewPort;
    viewPort.Width = width;
    viewPort.Height = height;
    viewPort.MinDepth = 0.0f;
    viewPort.MaxDepth = 1.0f;
    viewPort.TopLeftX = 0.0f;
    viewPort.TopLeftY = 0.0f;
    device_context->RSSetViewports(1, &viewPort);

}

void Device::Clear()
// API에서 백버퍼를 그릴 떄 먼저 다 지우고 그리기 시작했던 것처럼,
// 백버퍼의 화면을 초기화하는 함수
{
    float clear_color[4] = { 0.0f, 0.125f, 0.3f, 1.0f };
    // 배경색을 여기서 지정 - DX에서의 색은 0.0~1.0까지로 표현된 RGBA 값을 이용해
    // 최종적으로 출력되는 색을 결정하는 구조

    device_context->ClearRenderTargetView(render_target_view, clear_color);
    // 지정됀 배경색으로 화면의 모든 내용을 채워, 기존에 그려졌던 것을 지우라고
    // device_context에 요청

}

void Device::Present()
// 화면을 출력하는 함수 -> 더블버퍼링을 실행하는 함수
{
    swap_chain->Present(0, 0);
    // 스왑체인에 화면을 바꾸라고 요청하는 함수를 호출함으로서, 백버퍼와 현재 화면을 교체
}
