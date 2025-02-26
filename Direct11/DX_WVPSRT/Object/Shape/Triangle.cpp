#include "framework.h"

Triangle::Triangle(Vector2 size, D3D11_PRIMITIVE_TOPOLOGY t)
	: type(t)
{
	Vector2 half_size = Vector2(size.x / 2.0f, size.y / 2.0f);
	// 입력받은 사이즈를 토대로 삼각형을 그리기 위해 계산해야 할 꼭지점의 위치를 미리 계산
	

	switch (type)
	{
	case D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST:
		verticies.emplace_back(0, -half_size.y, 1.0f, 0.0f, 0.0f);
		verticies.emplace_back(half_size.x, half_size.y, 0.0f, 1.0f, 0.0f);
		verticies.emplace_back(-half_size.x, half_size.y, 0.0f, 0.0f, 1.0f);

		break;
	default:
		break;
	}

	DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
	// 셰이더를 생성하는 데 필요한 플래그를 미리 설정
	VS = new VertexShader(L"Shader/VertexShader/VertexShader.hlsl", flags);
	PS = new PixelShader(L"Shader/PixelShader/PixelShader.hlsl", flags);
	// 셰이더 주소가 있는 파일을 입력하여 정점 셰이더와 픽셀 셰이더를 만든다

	VB = new VertexBuffer(verticies.data(), sizeof(Vertex), verticies.size());
	CB = new ColourBuffer();
	// 셰이더에 들어갈 데이터들을 보관했다가 넘길 용도의 버퍼들을 생성

}

Triangle::~Triangle()
{
	delete VS;
	delete PS;
	delete VB;
	delete CB;
}

void Triangle::Render()
{
	CB->SetPS(0);
	// 픽셀 셰이더의 0번 슬롯에 이 버퍼를 등록해 데이터를 보냄

	VB->Set(type); // 현재 꼭지점 데이터가 들어있는 버퍼를 통해,
	// 지금부터 출력하고자 하는 데이터가 어떤 도형을 출력할 것인지
	// 저 함수를 통해서 호출
	VS->Set();
	PS->Set();
	DVC->Draw(verticies.size(), 0);

}
