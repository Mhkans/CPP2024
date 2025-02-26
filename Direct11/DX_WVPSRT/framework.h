// pch.h: 미리 컴파일된 헤더 파일입니다.
// 아래 나열된 파일은 한 번만 컴파일되었으며, 향후 빌드에 대한 빌드 성능을 향상합니다.
// 코드 컴파일 및 여러 코드 검색 기능을 포함하여 IntelliSense 성능에도 영향을 미칩니다.
// 그러나 여기에 나열된 파일은 빌드 간 업데이트되는 경우 모두 다시 컴파일됩니다.
// 여기에 자주 업데이트할 파일을 추가하지 마세요. 그러면 성능이 저하됩니다.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// 각종 매크로 상수를 선언하는 구간

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define WIN_CENTER_X (WIN_WIDTH * 0.5f)
#define WIN_CENTER_Y (WIN_HEIGHT * 0.5f)

// 각종 매크로 단축문을 선언하는 구간
#define DEVICE Device::Get()->GetDevice()
#define DVC Device::Get()->GetDeviceContext()

// Windows Header Files
#include <windows.h>
// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

using namespace std;
using namespace DirectX;


// 이제부턴 이 (미리 컴파일된) 헤더에 여러 라이브러리 및 프레임워크를 계속해서 추가할 것인데,
// 추가하는 순서에 따라서 에러가 발생하는 경우가 앞으로 빈발할 것
// 따라서, 각 헤더가 어디에 추가되는지,
// 어떤 헤더가 포함된 뒤에 포함되는지 등을 정확히 파악하고 넣어줘야 함

typedef XMFLOAT4 Float4;
typedef XMFLOAT3 Float3;
typedef XMFLOAT2 Float2;
// XMFLOATN : DX에서 사용하는, 실수를 N개만큼 묶어놓은 구조체

typedef XMMATRIX Matrix;
// XMMATRIX : DX에서 사용되는, 행렬 아니면 4차원 벡터를 저장할 수 있는 유니온 구조체


// Framework Header

/// Buffer Header - DirectX 곳곳에서 셰이더에 정보를 넘길 때 사용하게 될 버퍼를 정의한 헤더들
#include"Framework/Buffer/VertexBuffer.h"
#include"Framework/Buffer/ConstBuffer.h"
#include"Framework/Buffer/GlobalBuffer.h"

/// Math Header - DX를 넘어서 3D 공간과 관련된 수학적 연산을 담당하는 파트
#include"Framework/Math/Vector2.h"
#include"Framework/Math/Transform.h"

/// System Header
#include"Framework/System/Device.h"

/// Shader Header
#include"Framework/Shader/VertexShader.h"
#include"Framework/Shader/PixelShader.h"

// Object Header

/// Shape Header
#include"Object/Shape/Vertex.h"
#include"Object/Shape/Shape.h"
#include"Object/Shape/Triangle.h"
#include"Object/Shape/MyPolygon.h"

/// Transform Header
#include"Object/Transform/SRTTriangle.h"
#include"Object/Transform/Planet.h"

// Program & Scene Header
#include"Scenes/Scene.h"
//#include"Scenes/TutorialScene.h"
#include"Scenes/SRTScene.h"
#include"Scenes/SolarSystemScene.h"
#include"Program/Program.h"

extern HWND hWnd;

#endif //PCH_H