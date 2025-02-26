#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
	// 셰이더를 생성하는 데 필요한 플래그를 미리 설정
	VS = new VertexShader(L"Shader/VertexShader/VertexShader.hlsl", flags);
	PS = new PixelShader(L"Shader/PixelShader/PixelShader.hlsl", flags);
	// 셰이더 주소가 있는 파일을 입력하여 정점 셰이더와 픽셀 셰이더를 만든다

	vector<Vertex> vx_triangle_list =
	{
		Vertex(-0.1f, +0.1f, 0.17f, 0.8f, 0.8f),
		Vertex(-0.8f, +0.1f, 0.17f, 0.8f, 0.8f),
		Vertex(-0.8f, +0.8f, 0.17f, 0.8f, 0.8f),
		Vertex(-0.8f, +0.8f, 0.17f, 0.8f, 0.8f),
		Vertex(-0.1f, +0.8f, 0.17f, 0.8f, 0.8f),
		Vertex(-0.1f, +0.1f, 0.17f, 0.8f, 0.8f),
	};

	list_triangle = new Triangle(vx_triangle_list);

	vector<Vertex> vx_triangle_strip =
	{
		Vertex(-0.8f, -0.8f, 0.8f, 0.17f, 0.17f),
		Vertex(-0.8f, -0.1f, 0.1f, 0.1f, 0.17f),
		Vertex(-0.1f, -0.8f, 0.1f, 0.1f, 0.17f),
		Vertex(-0.4f, -0.1f, 0.8f, 0.17f, 0.17f),
	};

	strip_triangle = new Triangle(vx_triangle_strip,
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	// D3D11_PRIMITIVE_TOPOLOGY : 장치가 어떤 도형을 그릴 것인지를 알리는 역할을 맡는 열거형
	// TRIANGLELIST : 묻지도 따지지도 않고 3개 단위로 점을 끊어서 삼각형을 만들라는 것
	// TRIANGLESTRIP : 마지막에 사용했던 2의 점을 재활용해서
	//				   그 뒤에 추가로 들어오는 점과 합쳐 삼각형을 출력하라는 것

	// LINELIST 
	// LINESTRIP
	// 등의 다른 것들도 있음
}

TutorialScene::~TutorialScene()
{
	delete list_triangle;
	delete VS;
	delete PS;
}

void TutorialScene::Update()
{
}

void TutorialScene::Render()
{
	/*
	DX의 메인 루프에서 그래픽이 출력될 떄까지 거쳐가게 되는 단계는 다음과 같다 : 
	1) Update()를 통해 현재 실행되고 있는 Scene에서 새로 고쳐져야 할 내용들이 결정됨
	2) Program에서 Render()를 실행해서 제일 먼저 화면을 배경색으로 전부 칠함
	3) Scene()의 Render로 들어와서, 그 Scene 안에 있는 오브젝트들의 출력을 시작함
	 * 그 오브젝트들 각각의 출력은 다음과 같이 진행됨
	 A) DX의 그래픽 출력을 담당하는 장치인 deviceContext에
	    지금부터 출력하기 위해 어떤 세팅을 해야 하는지를 알리고 필요한 데이터들을 보냄
		(어떤 셰이더를 쓸 것인지, 입력받는 꼭지점의 정보는 어떻게 구성되었는지의 명세서,
		실제 꼭지점들이 저장되어 있는 버퍼, 이 꼭지점들을 어떤 도형으로서 출력할 것인지 모드 설정)
	 B) 모든 데이터가 세팅되었으면, 앞에서부터 총 몇 개의 꼭지점들을 이용해 도형을 출력할 것인지 입력받고
	    이를 그래픽(백버퍼)에 출력
	4) Scene의 모든 그래픽을 다 그리는 대 성공했으면 이 백버퍼를 메인 화면과 교체
	*/

	UINT stride = sizeof(Vertex);	// 꼭지점 하나하나하가 차지하는 용량
	UINT offset = 0;
	

	Device::Get()->GetDeviceContext()->VSSetShader(VS->GetVertexShader(), nullptr, 0);
	Device::Get()->GetDeviceContext()->PSSetShader(PS->GetPixelShader(), nullptr, 0);
	// 다음 그림을 그리기 위해 어떤 셰이더를 사용할 것인지를 위 함수들을 통해 세팅
	// 실수로라도 Set이 아닌 Get으로 자동완성되었는지를 반드시 체크할 것

	Device::Get()->GetDeviceContext()->IASetInputLayout(VS->GetInputLayout());
	// 다음에는 VS 쪽에 들어갈 꼭지점이 어떻게 구성되어있는지 그 명세표를 장치에 전달

	Device::Get()->GetDeviceContext()->IASetVertexBuffers
	(0, 1, list_triangle->GetBuffer(), &stride, &offset);
	// 해당 도형이 가지고 있는, 꼭지점들이 저장된 버퍼를 이 함수를 통해 장치에 세팅

	Device::Get()->GetDeviceContext()->IASetPrimitiveTopology(list_triangle->GetType());
	// 장치가 이제부터 꼭지점을 이용해 그릴 도형이 어떤 도형인지를
	// 열거형을 통해 설정

	Device::Get()->GetDeviceContext()->Draw(list_triangle->GetVertexSize(), 0);
	// 마지막엔 그 도형이 가지고 있는 꼭지점들의 개수를 입력하여
	// 그 개수만큼을 이용해 도형을 만들도록 하면 실제 그래픽에 도형이 그려지는 것


	Device::Get()->GetDeviceContext()->IASetVertexBuffers
	(0, 1, strip_triangle->GetBuffer(), &stride, &offset);

	Device::Get()->GetDeviceContext()->IASetPrimitiveTopology(strip_triangle->GetType());

	Device::Get()->GetDeviceContext()->Draw(strip_triangle->GetVertexSize(), 0);

}


/*

과제)

1. 위에서 LINELIST와 LINESTRIP은 써보지 않았는데,
이것들을 이용해서 각각 오각형과 오망성을 만들어볼 것
새로 Triangle을 만들어서 이용해보면 될 것

2. 꼭지점의 개수를 입력하면
그 개수에 맞는 정다각형을 출력하는 도형을 클래스로서 만들어볼 것
5라고 적으면 오각형을 만들고, 12라고 적으면 십이각형 등

생성자의 서식은 다음과 같음 :

Polygon(float x, float y, int vertex_count, 대충 프리미티브 토폴로지)
x,y : 이 도형의 화면상에서의 좌표
vertex_count : 이 도형의 꼭지점 개수

이를 통해서 초기 위치까지 지정하는 도형을 만들어볼 것



*/