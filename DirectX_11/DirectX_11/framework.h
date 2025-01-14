// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<wrl/client.h>

#include<d3d11.h>
#include<d3dcompiler.h>
#include<DirectXMath.h>

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")

using namespace std;
using namespace DirectX;

//프로젝트 참조
#include"../DirectXTex/DirectXTex.h"


//정적 라이브러리 A에서 B에 있는 함수들을 쓰고 싶다. 어지간하면 고치면 안될때
//B를 정적 라이브러리로 만든다
//B를 실행시켜서 빌드파일을 만들고 A에게 전달해준다 
//.lib <- 정적 라이브러리

//동적 라이브러리 A에서 B에 있는 함수들을 쓰고 싶다. 에러가 있거나 소스를 바꿀 여지가 있다
//B를 동적라이브러리로 만들면 .dll 이 나온다
//실행할때 같이 실행된다