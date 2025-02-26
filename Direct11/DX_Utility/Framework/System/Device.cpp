#include "framework.h"
#include "Device.h"

Device* Device::instance = nullptr;

UINT width = WIN_WIDTH;
UINT height = WIN_HEIGHT;

Device::Device() 
{
    // DX�� �⺻ ȯ���� �������ִ� �Լ����� ���������� ȣ��
    CreateDeviceAndSwapChain(); // DX�� ����̽�, ����̽� ���ؽ�Ʈ, ����ü���� �����ϴ� �Լ�
    CreateBackBuffer(); // ���� ����۸� �����ϴ� �Լ�
    SetViewPoint(); // ����Ʈ�� �����ϴ� �Լ� - ���� ���� �̰� �������� ������ �ʿ�� ����
}

Device::~Device()
{
    device->Release();
    device_context->Release();

    swap_chain->Release();
    render_target_view->Release();
}

void Device::CreateDeviceAndSwapChain()
// ���� ���۸� ���� ������ �ʱ�ȭ�ϴ� ���ÿ�,
// Device �� ��ü�� �ʱ�ȭ�ϴ� �Լ�
{
    DXGI_SWAP_CHAIN_DESC sd = {};
    // ����� ���� ������ �����صδ� �ν��Ͻ�
    // �̷��� �����ص� �� �Ʒ��� ������� �Է��Ͽ� ����۸� ���� �Ҵ��� �� ����ϴ� �ɼ� ������

    sd.BufferCount = 1; // ����� ������� ���� - 2D���� �����ϸ� 1���� ����

    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;
    // ����۰� �ٷ� ȭ���� ũ��

    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    // ����۰� �ٷ� �׷����� ����ϴ� ������ �԰��� ������ ��
    // R8G8B8A8 = Red 8��Ʈ, Green 8bit, Blue 8bit, Alpha�� 8bit�� �� 32��Ʈ�� ���� �̿��� ����ϴ� ��
    // ���� UNORM�� �� �����Ͱ� ����Ǿ��ִ� ����(int���� float���� ���)

    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    // �ʴ� �����Ӱ� ���õ� ����, ��Ȯ���� �ʴ� �ֻ����� ���õ� ����
    // �ٸ�, ȭ�� �ֻ����� 60hz���� �ٲ� ���� ���� ������ �׳� �� ������ �����Ѵ� ������ ��

    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    // �� ���۰� ��� ���� ������ �� �뵵�� ����ϴ� ��

    sd.OutputWindow = hWnd;
    // �� ����۰� �׸��� ����� â�� ��� â���� �����ϴ� �κ�
    // �̰͸�ŭ�� ������Ʈ ���� �ڵ忡�� ����� �� ������ ��� �ϹǷ�,
    // �ݵ�� �ش� ������ extern���μ� �����Ͽ� ���⼭ �� �� �ְ� ������ ��

    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    // 3D �ʿ��� ����ϴ� ����̶� �츮�� �� �� ���� ���

    sd.Windowed = true;
    // â��� ���θ� �����ϴ� ���

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
    // �׷��� ������ sd�� �̿��ؼ� ���� ���۸� �� ����ü��, DX�� Ȱ���ϱ� ���� device�� device_context��
    // �� ���� �ʱ�ȭ
}

void Device::CreateBackBuffer()
// ������۸� �� ����۸� �ʱ�ȭ�ϰ�, �̸� ����̽��� ����ϴ� �Լ�
{
    ID3D11Texture2D* backBuffer = nullptr;

    swap_chain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
    device->CreateRenderTargetView(backBuffer, nullptr, &render_target_view);
    // ������� ����ü�ΰ� ����̽� ������ ����۸� �������ִ� �ڵ�

    backBuffer->Release();

    device_context->OMSetRenderTargets(1, &render_target_view, nullptr);
    // ������ ����۸� ������ �׸� �׸��� �κ��� �Ѱ��ϴ� device_context�� ���

    // API �ʿ��� �츮�� ���� ����۸� �̷����� �Ű������� �����ؼ� ��ü����� ������,
    // DX������ ó���� ������ ���� �̰����� �������ְ�
    // ���߿� ����۸� ��ü�� ���� ������ �Լ� �ϳ��� ȣ�����ִ� ������ ���� �� ����
    // �װ� �ؿ� �ִ� Present
}

void Device::SetViewPoint()
// ����Ʈ�� �����ϴ� �Լ�
{
    // 2D���ٴ� 3D���� �� ���� ����� �����̹Ƿ�
    // ���⼭�� �׳� �̷� �� �ִ� �����θ� ����ص� �� ���� X
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
// API���� ����۸� �׸� �� ���� �� ����� �׸��� �����ߴ� ��ó��,
// ������� ȭ���� �ʱ�ȭ�ϴ� �Լ�
{
    float clear_color[4] = { 0.0f, 0.125f, 0.3f, 1.0f };
    // ������ ���⼭ ���� - DX������ ���� 0.0~1.0������ ǥ���� RGBA ���� �̿���
    // ���������� ��µǴ� ���� �����ϴ� ����

    device_context->ClearRenderTargetView(render_target_view, clear_color);
    // ������ �������� ȭ���� ��� ������ ä��, ������ �׷����� ���� ������
    // device_context�� ��û

}

void Device::Present()
// ȭ���� ����ϴ� �Լ� -> ������۸��� �����ϴ� �Լ�
{
    swap_chain->Present(0, 0);
    // ����ü�ο� ȭ���� �ٲٶ�� ��û�ϴ� �Լ��� ȣ�������μ�, ����ۿ� ���� ȭ���� ��ü
}
