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

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

// Windows Header Files
#include <windows.h>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

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

// Framework Header
#include"Framework/System/Device.h"
#include"Framework/Shader/VertexShader.h"
#include"Framework/Shader/PixelShader.h"

// Object Header
#include"Object/Shape/Vertex.h"
#include"Object/Shape/Shape.h"
#include"Object/Shape/Triangle.h"

// Program & Scene Header
#include"Scenes/Scene.h"
#include"Scenes/TutorialScene.h"
#include"Program/Program.h"

extern HWND hWnd;

#endif //PCH_H