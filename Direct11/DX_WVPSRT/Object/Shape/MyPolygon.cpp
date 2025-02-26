#include "framework.h"

MyPolygon::MyPolygon(float s, int v, D3D11_PRIMITIVE_TOPOLOGY t)
	: size(s), vertex_count(v), type(t)
{

	float angle = 2 * M_PI;


	switch (type)
	{
	case D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST:
	{
		for (int i = 0; i < vertex_count; i++)
		{
			verticies.emplace_back(0, 0, 0, 0, 0);
			// 일단 정다각형의 중심점을 등록
			// 좌표값은 입력받은 값을 그대로 이용

			verticies.emplace_back(
				0 - cos(angle) * size,
				0 + sin(angle) * size,
				1,
				1,
				1
			);
			// 여기서의 X, Y를 계산한 수식은
			// 반지름이 size이고 중심점이 x,y인 원 위에서
			// x축과 비교했을 때 angle만큼의 각을 가지고 있는 있는 어떤 점의 좌표를
			// 삼각함수를 통해 계산한 것

			// -> 원에 내접하는 정다각형의 하나의 꼭지점을
			// 삼각함수를 이용해서 그 좌표를 구한 것

			angle -= 2 * M_PI / (float)vertex_count;
			// 하나의 꼭지점을 구했다면 그 다음 꼭지점을 구하기 위해 현재 각도를 조절

			verticies.emplace_back(
				- cos(angle) * size,
				+ sin(angle) * size,
				1,
				1,
				1
			);
		}
	}
	break;
	case D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP:
	{
		for (int i = 0; i <= vertex_count; i++)
		{
			verticies.emplace_back(
				 - cos(angle) * size,
				 + sin(angle) * size,
				(angle) / (2.0 * M_PI),
				1 - (angle) / (2.0 * M_PI),
				0
			);
			angle -= 2 * M_PI / (float)vertex_count;

			// 이 쪽은 종료점만 추가로 적어줘야 한다는 점을 빼면 꼭지점들로만 순차적으로 추가하면 끝
		}
	}
	break;

	default:
		break;
	}

	DWORD flags = D3DCOMPILE_ENABLE_STRICTNESS | D3DCOMPILE_DEBUG;
	VS = new VertexShader(L"Shader/VertexShader/VertexShader.hlsl", flags);
	PS = new PixelShader(L"Shader/PixelShader/PixelShader.hlsl", flags);

	VB = new VertexBuffer(verticies.data(), sizeof(Vertex), verticies.size());
	CB = new ColourBuffer();
}

MyPolygon::~MyPolygon()
{
}

void MyPolygon::Render()
{
	CB->SetPS(0);

	VB->Set(type);
	VS->Set();
	PS->Set();
	DVC->Draw(verticies.size(), 0);
}
