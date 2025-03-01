// framework.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일

#include "framework.h"

// 미리 컴파일된 헤더를 사용하는 경우 컴파일이 성공하려면 이 소스 파일이 필요합니다.
// + 설정에서 C/C++ -> 미리 컴파일된 헤더 -> 미리 컴파일된 헤더 항이 
// 만들기(/Yc)라는 설정으로 되어있어야 함

/*
오늘 진행할 작업 : ImGui라는 외부 라이브러리를 설치하는 과정

ImGui : 프로그램의 각종 패러미터 등을 손쉽게 출력할 수 있게 만들어주는 GUI,
		Graphic User Interface
		우리는 디버그용으로만 사용할 것이지만,
		이 GUI 자체가 제공해주는 기능은 매우 다양하므로 여러가지 방면에서 사용할 수 있음

설치하는 방법 

1) GitHub의 ocornut/imgui를 찾아가서 모든 파일을 받아, 적당한 위치에 풀기

2) master 폴더 내에 있는 Backend 폴더 안에 들어가,
지금 우리가 만들고자 하는 프로젝트의 환경과 일치하는 헤더와 코드 파일을 master 폴더에 복사
(지금 프로젝트 기준으로는 dx11, win32)

3) 솔루션->추가->새 프로젝트->윈도우 데스크톱 마법사를 선택하여 새 프로젝트를 만들고,
설정은 정적 라이브러리, 빈 프로젝트 체크

그 후 master 폴더 안에 있는 모든 헤더, 코드 파일을 저 새로 만들어진 빈 프로젝트에 복사 후
탐색기에서 모든 파일을 프로젝트에 포함

4) 현재 작업 중인 프로젝트 우클릭->추가->참조 -> ImGui 체크

5) 미리 컴파일된 헤더에 위 라이브러리를 사용하기 위한 아래 구문을 추가
추가하는 위치는 DirectXTex를 추가했던 곳 바로 아래 정도면 적절

#include"../ImGui/imgui.h"
#include"../ImGui/imgui_impl_dx11.h"
#include"../ImGui/imgui_impl_win32.h"

6) 만들어진 새 프로젝트의 속성값에 이상한 값이 들어가지 않았는지 체크
ex | 미리 컴파일된 헤더 - 사용 안함





*/
