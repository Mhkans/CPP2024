// DX_FirstStep.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "DX_FirstStep.h"

#define MAX_LOADSTRING 100

struct Vertex   // Vertex : 정점 = 3차원 공간에서의 한 점
{
    XMFLOAT3 position;
};

// Global Variables:
HWND hWnd;
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

ID3D11Device* device;    // CPU의 연산, 리소스 로딩 등 출력 외 다른 기능들을 종합적으로 하는 기본 장치
ID3D11DeviceContext* deviceContext; // GPU에서 하는 일을 여기서 담당

IDXGISwapChain* swapChain;  // 더블버퍼링에 사용되는 객체
ID3D11RenderTargetView* renderTargetView;   // 후면버퍼에서 사용할 메모리

ID3D11VertexShader* vertexShader;
ID3D11PixelShader* pixelShader;

ID3D11InputLayout* inputLayout;
ID3D11Buffer* vertexBuffer;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void InitDevice();      // DirectX와 관련된 각종 기능들을 초기화하는 함수
void Render();          // DirectX 관련 기능들을 이용해 화면을 그리는 함수
                        // WM_PAINT 대신 이 함수가 관련 기능을 수행하는 것
void ReleaseDevice();   // 프로그램이 종료될 때 DirectX와 관련된 기능들을 종료하는 함수



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DXFIRSTSTEP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DXFIRSTSTEP));

    MSG msg = {};

    InitDevice();

    // Main message loop:
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

        Render();
    }

    ReleaseDevice();

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DXFIRSTSTEP));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_DXFIRSTSTEP);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   RECT rect = { 0, 0, WIN_WIDTH, WIN_HEIGHT };
   AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

   hWnd = CreateWindowW(szWindowClass,
       L"DirectX 2D WITH 3D",
       WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT,
       0,
       rect.right - rect.left,
       rect.bottom - rect.top,
       nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


void InitDevice() // 장치 초기화 : DirectX를 이용해 화면을 출력하기 위해 필요한 초기화를 여기서 거침
{
    UINT width = WIN_WIDTH;
    UINT height = WIN_HEIGHT;

    DXGI_SWAP_CHAIN_DESC sd = {};
    sd.BufferCount = 1;

    sd.BufferDesc.Width = width;
    sd.BufferDesc.Height = height;

    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;

    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;

    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;

    sd.Windowed = true;
    // 더블 버퍼링과 관련된 설정들을 지정해주는 파트

    D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        0,
        D3D11_CREATE_DEVICE_DEBUG,
        nullptr,
        0,
        D3D11_SDK_VERSION,
        &sd,
        &swapChain,
        &device,
        nullptr,
        &deviceContext
    );
    // 그 설정들을 통해 더블버퍼링을 실현하는 주체인 "스왑 체인"을 만드는 함수

    ID3D11Texture2D* backBuffer = nullptr;
    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
    device->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView);
    backBuffer->Release();
    // 더블 버퍼링에 사용될 백버퍼를 초기화

    deviceContext->OMSetRenderTargets(1, &renderTargetView, nullptr);

    D3D11_VIEWPORT viewPort;
    viewPort.Width = width;
    viewPort.Height = height;
    viewPort.MinDepth = 0.0f;
    viewPort.MaxDepth = 1.0f;
    viewPort.TopLeftX = 0.0f;
    viewPort.TopLeftY = 0.0f;
    deviceContext->RSSetViewports(1, &viewPort);


    // 여기서부터는 "셰이더"라는 것을 다룸

    DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

    ID3DBlob* vertexBlob;
    D3DCompileFromFile(L"Shader/VertexShader.hlsl", nullptr, nullptr, "VS",
        "vs_5_0", flags, 0, &vertexBlob, nullptr);
    // 셰이더 파일이 있는 위치를 어떤 셰이더인지를 알려주는 값들과 함께 DirectX 엔진에 전달해서
    // 해당 파일을 토대로 DX 엔진이 컴파일하라고 요청하는 함수

    device->CreateVertexShader(vertexBlob->GetBufferPointer(),
        vertexBlob->GetBufferSize(), nullptr, &vertexShader);
    // 컴파일에 성공했으면 그 내용대로 VertexShader = 꼭지점(정점) 셰이더를 담당하는 객체를 만듦

    D3D11_INPUT_ELEMENT_DESC layouts[] =
    {
        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
        D3D11_INPUT_PER_VERTEX_DATA, 0}
    };

    UINT layoutSize = ARRAYSIZE(layouts);

    device->CreateInputLayout(layouts, layoutSize, vertexBlob->GetBufferPointer(),
        vertexBlob->GetBufferSize(), &inputLayout);
    vertexBlob->Release();

    // 여기까지 "꼭지점 셰이더"를 다루는 부분

    ID3DBlob* pixelBlob;
    D3DCompileFromFile(L"Shader/VertexShader.hlsl", nullptr, nullptr, "PS",
        "ps_5_0", flags, 0, &pixelBlob, nullptr);

    device->CreatePixelShader(pixelBlob->GetBufferPointer(),
        pixelBlob->GetBufferSize(), nullptr, &pixelShader);
    pixelBlob->Release();

    // 여기까지 "픽셀 셰이더"를 다루는 부분

    // 아래의 배열은 "이번 프로그램에서 출력하고자 하는 도형의 꼭지점들을 정리해둔 것"
    Vertex vertices[] =
    {
        // DX에서 특별히 설정해주지 않으면 좌표계는 왼쪽 아래를 -1, -1, 오른쪽 위를 +1, +1이라고 가정하여
        // 화면 중앙을 원점으로 삼음

        XMFLOAT3(-0.5f, -0.5f, 0.0f), // XMFLOAT3 : DirectX 네임스페이스에서 제공하는 float 3개를 저장하는 구조체
        XMFLOAT3(+0.5f, +0.5f, 0.0f),
        XMFLOAT3(+0.5f, -0.5f, 0.0f),
        // 여기까지 첫번째 삼각형

        XMFLOAT3(+0.5f, +0.5f, 0.0f),
        XMFLOAT3(-0.5f, -0.5f, 0.0f),
        XMFLOAT3(-0.5f, +0.5f, 0.0f),
        // 여기까지 두번쨰 삼각형
       
        // 폴리곤(Polygon) : 정점 3개로 이뤄진 삼각형
        /*
        3D는 기본적으로 모든 그래픽을 나타낼 떄 그 그래픽을 구성하는 최소 단위로서 폴리곤을 이용함
        이 폴리곤의 집합을 통해 3D 물체를 화면에 나타내는 것

        회전 등으로 인해 뒷면이 노출되는 걸 막기 위해,
        DX에서는 이 폴리곤을 출력할 때 꼭지점들이 시점을 기준으로 시계방향인지 아닌지를 통해
        앞면인지 뒷면인지를 구분함
        앞면이면 화면에 출력, 뒷면이면 화면에 출력하지 않음
        
        */
    };

    // 아래는 꼭지점들의 데이터를 DX 장치에 전달하기 위해 필요한 버퍼를 정의하는 과정

    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.ByteWidth = sizeof(vertices);
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = vertices;

    device->CreateBuffer(&bd, &initData, &vertexBuffer);
}

void Render()
{
    float clearColor[4] = { 0.2f, 0.125f, 0.3f, 1.0f };
    deviceContext->ClearRenderTargetView(renderTargetView, clearColor);
    // 배경색을 지정해서 그걸로 화면을 일단 다 칠하는 코드

    UINT stride = sizeof(Vertex);
    UINT offset = 0;

    deviceContext->IASetInputLayout(inputLayout);

    deviceContext->IASetVertexBuffers(0,
        1,
        &vertexBuffer,
        &stride,
        &offset
    );
    // 꼭지점 셰이더를 사용하기 위해 필요한,
    // 꼭지점 그 자체가 저장되어있는 버퍼를 장치에다가 전달해주는 함수

    deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    // DX 장치에 "어떤 도형을 그릴 것인가"를 알리는 함수
    // D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST : 꼭지점을 3개 단위르 끊어서
    //                                         각각의 3개를 이용해 삼각형=폴리곤을 출력하는 것을
    //                                         주어진 점의 개수를 이용해 반복해라

    deviceContext->VSSetShader(vertexShader, nullptr, 0);
    deviceContext->PSSetShader(pixelShader, nullptr, 0);
    // DX 장치에 지금 사용할 셰이더들을 등록

    deviceContext->Draw(3, 0);
    // DX 장치에 지금까지 전달된 모든 데이터를 이용해서 
    // 주어진 꼭지점들 중 0번 인덱스의 꼭지점부터 6개의 꼭지점을 이용해 도형을 그려보라

    swapChain->Present(0, 0);
    // 그리는 작업이 다 끝났다면
    // 더블버퍼링을 담당하는 객체인 스왑체인에 "화면 교체해주세요"라고 요청
}

void ReleaseDevice()
{
    device->Release();
    deviceContext->Release();

    swapChain->Release();
    renderTargetView->Release();

    vertexShader->Release();
    pixelShader->Release();

    inputLayout->Release();
    vertexBuffer->Release();
}

/*
과제 : 
1) 사각형 외의 좀 복잡한 도형을 만들어볼 것
(단, 지금 시점에서는 도형마다 색을 넣는 것은 불가능하므로 단색으로서 가능한 도형을 만들어볼 것)

2) 지금 이 프로젝트 안에 있는 파일들 중 단 하나의 코드를 건드리는 것만으로
그려지는 모든 도형의 색을 바꿀 수 있음
배경색 다루는 방식을 통해 색이 어떻게 관리되는지 그 구조는 알 수 있으니,
어떻게 하면 그 단색을 바꿀 수 있는지 찾아서 흰색 외의 색으로 도형들의 색상을 바꿀 것
*/