// DX_FirstStep.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "DX_FirstStep.h"

#define MAX_LOADSTRING 100

struct Vertex   // Vertex : ���� = 3���� ���������� �� ��
{
    XMFLOAT3 position;
};

// Global Variables:
HWND hWnd;
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

ID3D11Device* device;    // CPU�� ����, ���ҽ� �ε� �� ��� �� �ٸ� ��ɵ��� ���������� �ϴ� �⺻ ��ġ
ID3D11DeviceContext* deviceContext; // GPU���� �ϴ� ���� ���⼭ ���

IDXGISwapChain* swapChain;  // ������۸��� ���Ǵ� ��ü
ID3D11RenderTargetView* renderTargetView;   // �ĸ���ۿ��� ����� �޸�

ID3D11VertexShader* vertexShader;
ID3D11PixelShader* pixelShader;

ID3D11InputLayout* inputLayout;
ID3D11Buffer* vertexBuffer;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void InitDevice();      // DirectX�� ���õ� ���� ��ɵ��� �ʱ�ȭ�ϴ� �Լ�
void Render();          // DirectX ���� ��ɵ��� �̿��� ȭ���� �׸��� �Լ�
                        // WM_PAINT ��� �� �Լ��� ���� ����� �����ϴ� ��
void ReleaseDevice();   // ���α׷��� ����� �� DirectX�� ���õ� ��ɵ��� �����ϴ� �Լ�



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


void InitDevice() // ��ġ �ʱ�ȭ : DirectX�� �̿��� ȭ���� ����ϱ� ���� �ʿ��� �ʱ�ȭ�� ���⼭ ��ħ
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
    // ���� ���۸��� ���õ� �������� �������ִ� ��Ʈ

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
    // �� �������� ���� ������۸��� �����ϴ� ��ü�� "���� ü��"�� ����� �Լ�

    ID3D11Texture2D* backBuffer = nullptr;
    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
    device->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView);
    backBuffer->Release();
    // ���� ���۸��� ���� ����۸� �ʱ�ȭ

    deviceContext->OMSetRenderTargets(1, &renderTargetView, nullptr);

    D3D11_VIEWPORT viewPort;
    viewPort.Width = width;
    viewPort.Height = height;
    viewPort.MinDepth = 0.0f;
    viewPort.MaxDepth = 1.0f;
    viewPort.TopLeftX = 0.0f;
    viewPort.TopLeftY = 0.0f;
    deviceContext->RSSetViewports(1, &viewPort);


    // ���⼭���ʹ� "���̴�"��� ���� �ٷ�

    DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;

    ID3DBlob* vertexBlob;
    D3DCompileFromFile(L"Shader/VertexShader.hlsl", nullptr, nullptr, "VS",
        "vs_5_0", flags, 0, &vertexBlob, nullptr);
    // ���̴� ������ �ִ� ��ġ�� � ���̴������� �˷��ִ� ����� �Բ� DirectX ������ �����ؼ�
    // �ش� ������ ���� DX ������ �������϶�� ��û�ϴ� �Լ�

    device->CreateVertexShader(vertexBlob->GetBufferPointer(),
        vertexBlob->GetBufferSize(), nullptr, &vertexShader);
    // �����Ͽ� ���������� �� ������ VertexShader = ������(����) ���̴��� ����ϴ� ��ü�� ����

    D3D11_INPUT_ELEMENT_DESC layouts[] =
    {
        {"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,
        D3D11_INPUT_PER_VERTEX_DATA, 0}
    };

    UINT layoutSize = ARRAYSIZE(layouts);

    device->CreateInputLayout(layouts, layoutSize, vertexBlob->GetBufferPointer(),
        vertexBlob->GetBufferSize(), &inputLayout);
    vertexBlob->Release();

    // ������� "������ ���̴�"�� �ٷ�� �κ�

    ID3DBlob* pixelBlob;
    D3DCompileFromFile(L"Shader/VertexShader.hlsl", nullptr, nullptr, "PS",
        "ps_5_0", flags, 0, &pixelBlob, nullptr);

    device->CreatePixelShader(pixelBlob->GetBufferPointer(),
        pixelBlob->GetBufferSize(), nullptr, &pixelShader);
    pixelBlob->Release();

    // ������� "�ȼ� ���̴�"�� �ٷ�� �κ�

    // �Ʒ��� �迭�� "�̹� ���α׷����� ����ϰ��� �ϴ� ������ ���������� �����ص� ��"
    Vertex vertices[] =
    {
        // DX���� Ư���� ���������� ������ ��ǥ��� ���� �Ʒ��� -1, -1, ������ ���� +1, +1�̶�� �����Ͽ�
        // ȭ�� �߾��� �������� ����

        XMFLOAT3(-0.5f, -0.5f, 0.0f), // XMFLOAT3 : DirectX ���ӽ����̽����� �����ϴ� float 3���� �����ϴ� ����ü
        XMFLOAT3(+0.5f, +0.5f, 0.0f),
        XMFLOAT3(+0.5f, -0.5f, 0.0f),
        // ������� ù��° �ﰢ��

        XMFLOAT3(+0.5f, +0.5f, 0.0f),
        XMFLOAT3(-0.5f, -0.5f, 0.0f),
        XMFLOAT3(-0.5f, +0.5f, 0.0f),
        // ������� �ι��� �ﰢ��
       
        // ������(Polygon) : ���� 3���� �̷��� �ﰢ��
        /*
        3D�� �⺻������ ��� �׷����� ��Ÿ�� �� �� �׷����� �����ϴ� �ּ� �����μ� �������� �̿���
        �� �������� ������ ���� 3D ��ü�� ȭ�鿡 ��Ÿ���� ��

        ȸ�� ������ ���� �޸��� ����Ǵ� �� ���� ����,
        DX������ �� �������� ����� �� ���������� ������ �������� �ð�������� �ƴ����� ����
        �ո����� �޸������� ������
        �ո��̸� ȭ�鿡 ���, �޸��̸� ȭ�鿡 ������� ����
        
        */
    };

    // �Ʒ��� ���������� �����͸� DX ��ġ�� �����ϱ� ���� �ʿ��� ���۸� �����ϴ� ����

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
    // ������ �����ؼ� �װɷ� ȭ���� �ϴ� �� ĥ�ϴ� �ڵ�

    UINT stride = sizeof(Vertex);
    UINT offset = 0;

    deviceContext->IASetInputLayout(inputLayout);

    deviceContext->IASetVertexBuffers(0,
        1,
        &vertexBuffer,
        &stride,
        &offset
    );
    // ������ ���̴��� ����ϱ� ���� �ʿ���,
    // ������ �� ��ü�� ����Ǿ��ִ� ���۸� ��ġ���ٰ� �������ִ� �Լ�

    deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    // DX ��ġ�� "� ������ �׸� ���ΰ�"�� �˸��� �Լ�
    // D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST : �������� 3�� ������ ���
    //                                         ������ 3���� �̿��� �ﰢ��=�������� ����ϴ� ����
    //                                         �־��� ���� ������ �̿��� �ݺ��ض�

    deviceContext->VSSetShader(vertexShader, nullptr, 0);
    deviceContext->PSSetShader(pixelShader, nullptr, 0);
    // DX ��ġ�� ���� ����� ���̴����� ���

    deviceContext->Draw(3, 0);
    // DX ��ġ�� ���ݱ��� ���޵� ��� �����͸� �̿��ؼ� 
    // �־��� �������� �� 0�� �ε����� ���������� 6���� �������� �̿��� ������ �׷�����

    swapChain->Present(0, 0);
    // �׸��� �۾��� �� �����ٸ�
    // ������۸��� ����ϴ� ��ü�� ����ü�ο� "ȭ�� ��ü���ּ���"��� ��û
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
���� : 
1) �簢�� ���� �� ������ ������ ���� ��
(��, ���� ���������� �������� ���� �ִ� ���� �Ұ����ϹǷ� �ܻ����μ� ������ ������ ���� ��)

2) ���� �� ������Ʈ �ȿ� �ִ� ���ϵ� �� �� �ϳ��� �ڵ带 �ǵ帮�� �͸�����
�׷����� ��� ������ ���� �ٲ� �� ����
���� �ٷ�� ����� ���� ���� ��� �����Ǵ��� �� ������ �� �� ������,
��� �ϸ� �� �ܻ��� �ٲ� �� �ִ��� ã�Ƽ� ��� ���� ������ �������� ������ �ٲ� ��
*/