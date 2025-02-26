#include "framework.h"
#include "Quad.h"

void Quad::Create()
{
	VS = new VertexShader(L"Shader/VertexShader/VertexUV.hlsl", 1);
	PS = new PixelShader(L"Shader/PixelShader/PixelUV.hlsl");

	VB = new VertexBuffer(vertices_uv.data(), sizeof(VertexUV), vertices_uv.size());
	CB = new ColourBuffer();
}

Quad::Quad(Vector2 size, Vector2 scale, Vector2 StartUV, Vector2 EndUV)
	: Transform(Vector2(0,0), scale)
{
	Vector2 half_size = Vector2(size.x / 2.0f, size.y / 2.0f);
	// 입력받은 사이즈를 토대로 삼각형을 그리기 위해 계산해야 할 꼭지점의 위치를 미리 계산

	Vector2& hf = half_size;
	// 레퍼런스 기능을 통해 기존 함수의 이름을 축약시켜 가리키도록 하는 역할
	// 간단히 말해 hf라는 별명을 붙여준 것

	vertices_uv.emplace_back(-hf.x, -hf.y, StartUV.x, StartUV.y);
	vertices_uv.emplace_back(+hf.x, -hf.y, EndUV.x, StartUV.y);
	vertices_uv.emplace_back(-hf.x, +hf.y, StartUV.x, EndUV.y);
	vertices_uv.emplace_back(-hf.x, +hf.y, StartUV.x, EndUV.y);
	vertices_uv.emplace_back(+hf.x, -hf.y, EndUV.x, StartUV.y);
	vertices_uv.emplace_back(+hf.x, +hf.y, EndUV.x, EndUV.y);
	// 이 UV라는 값에 대한 설명은 VertexUV에서 설명


	Create();
}

Quad::~Quad()
{
	delete VS;
	delete PS;
	delete VB;
	delete CB;
}

void Quad::Render()
{
	if (!is_active)
		return;
	// 자기 자신이 현재 비활성화도니 상태면 출력하지 않고 함수 종료

	WB->Set(world);
	WB->SetVS(0);
	CB->SetPS(0);

	VB->Set();
	
	VS->Set();
	PS->Set();
	
	DVC->Draw(vertices_uv.size(), 0);
}
