// pch.h: �̸� �����ϵ� ��� �����Դϴ�.
// �Ʒ� ������ ������ �� ���� �����ϵǾ�����, ���� ���忡 ���� ���� ������ ����մϴ�.
// �ڵ� ������ �� ���� �ڵ� �˻� ����� �����Ͽ� IntelliSense ���ɿ��� ������ ��Ĩ�ϴ�.
// �׷��� ���⿡ ������ ������ ���� �� ������Ʈ�Ǵ� ��� ��� �ٽ� �����ϵ˴ϴ�.
// ���⿡ ���� ������Ʈ�� ������ �߰����� ������. �׷��� ������ ���ϵ˴ϴ�.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// ���� ��ũ�� ����� �����ϴ� ����

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define WIN_CENTER_X (WIN_WIDTH * 0.5f)
#define WIN_CENTER_Y (WIN_HEIGHT * 0.5f)

// ���� ��ũ�� ���๮�� �����ϴ� ����
#define DEVICE Device::Get()->GetDevice()
#define DVC Device::Get()->GetDeviceContext()
#define DELTA Timer::Get()->GetDeltaTime()

#define	KEY_PRESS(key) Control::Get()->Press(key)
#define	KEY_UP(key) Control::Get()->Up(key)
#define	KEY_DOWN(key) Control::Get()->Down(key)
// �̷� ������ ��ũ�ι��� �ۼ��� �� �Լ�ó�� ����� �͵� ����
// �� ��� �Լ� ���� �ڷ����� ���� �ʰ� �Լ��� ���,
// �������� ���� ���� ����� ���� �̸��� ��ġ�� �ش� ���� ���� ��


// Windows Header Files
#include <windows.h>
#include <windowsx.h>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

#pragma comment(lib, "dxguid.lib")
#include "../DirectXTex/DirectXTex.h"
// DirectXTex�� ����ϱ� ���� �߰��ϴ� ���̺귯��
// ���⼭�� ..�� "���� ����(=�� ������Ʈ�� �⺻ ����)���� �� �ܰ� ���� ������ �ö󰡶�� �ǹ�"

// �⺻������ ���� �ַ���̶� �ϴ��� �ٸ� ������Ʈ��� �ش� ������ ����� �� ���� ����
// => �� ������Ʈ ���ο� ��ġ�� ������ �ƴ϶� �ش� ������ VS���� ���� �о���̷� ���� �ʱ� ����
// ����, ���� ������ ���־ �ش� ������Ʈ�� �ִ� ���뵵 �ν��� �� �ְ� ��������
// �� ������ ���������� ������

#include"../ImGui/imgui.h"
#include"../ImGui/imgui_impl_dx11.h"
#include"../ImGui/imgui_impl_win32.h"

using namespace std;
using namespace DirectX;


// �������� �� (�̸� �����ϵ�) ����� ���� ���̺귯�� �� �����ӿ�ũ�� ����ؼ� �߰��� ���ε�,
// �߰��ϴ� ������ ���� ������ �߻��ϴ� ��찡 ������ ����� ��
// ����, �� ����� ��� �߰��Ǵ���,
// � ����� ���Ե� �ڿ� ���ԵǴ��� ���� ��Ȯ�� �ľ��ϰ� �־���� ��

typedef XMFLOAT4 Float4;
typedef XMFLOAT3 Float3;
typedef XMFLOAT2 Float2;
// XMFLOATN : DX���� ����ϴ�, �Ǽ��� N����ŭ ������� ����ü

typedef XMMATRIX Matrix;
// XMMATRIX : DX���� ���Ǵ�, ��� �ƴϸ� 4���� ���͸� ������ �� �ִ� ���Ͽ� ����ü


// Framework Header

/// Utility Header - ���α׷� �������⼭ ����� �������� ���(=��ƿ��Ƽ)���� �����ϴ� �����
#include"Framework/Utility/Singleton.h"
#include"Framework/Utility/Control.h"
#include"Framework/Utility/Timer.h"

/// Buffer Header - DirectX �������� ���̴��� ������ �ѱ� �� ����ϰ� �� ���۸� ������ �����
#include"Framework/Buffer/VertexBuffer.h"
#include"Framework/Buffer/ConstBuffer.h"
#include"Framework/Buffer/GlobalBuffer.h"

/// Math Header - DX�� �Ѿ 3D ������ ���õ� ������ ������ ����ϴ� ��Ʈ
#include"Framework/Math/Vector2.h"
#include"Framework/Math/Transform.h"
#include"Object/Shape/Vertex.h" // ���� ��ü�� �ٸ�����, �������̶�� ������ �ٷ�Ƿ�
// �̸� ���Խ��ѵδ� ���� �ٷ�� ����



/// System Header
#include"Framework/System/Device.h"

/// Shader Header
#include"Framework/Shader/VertexShader.h"
#include"Framework/Shader/PixelShader.h"

/// Collider Header - �浹ó���� �ٷ�� �����ӿ�ũ
#include"Framework/Collision/Collider.h"
#include"Framework/Collision/RectCollider.h"
#include"Framework/Collision/CircleCollider.h"

// Object Header

/// Shape Header
#include"Object/Shape/Shape.h"
#include"Object/Shape/RectUV.h"
#include"Object/Shape/Quad.h"
#include"Object/Shape/Triangle.h"
#include"Object/Shape/MyPolygon.h"

/// Transform Header
#include"Object/Transform/SRTTriangle.h"
#include"Object/Transform/Planet.h"
#include"Object/Transform/ImageRect.h"
#include"Object/Transform/ScrollingBG.h"

// Program & Scene Header
#include"Scenes/Scene.h"
#include"Scenes/SceneList.h"
#include"Program/Program.h"

extern HWND hWnd;
extern Vector2 mouse_pos;

#endif //PCH_H