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
			// �ϴ� ���ٰ����� �߽����� ���
			// ��ǥ���� �Է¹��� ���� �״�� �̿�

			verticies.emplace_back(
				0 - cos(angle) * size,
				0 + sin(angle) * size,
				1,
				1,
				1
			);
			// ���⼭�� X, Y�� ����� ������
			// �������� size�̰� �߽����� x,y�� �� ������
			// x��� ������ �� angle��ŭ�� ���� ������ �ִ� �ִ� � ���� ��ǥ��
			// �ﰢ�Լ��� ���� ����� ��

			// -> ���� �����ϴ� ���ٰ����� �ϳ��� ��������
			// �ﰢ�Լ��� �̿��ؼ� �� ��ǥ�� ���� ��

			angle -= 2 * M_PI / (float)vertex_count;
			// �ϳ��� �������� ���ߴٸ� �� ���� �������� ���ϱ� ���� ���� ������ ����

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

			// �� ���� �������� �߰��� ������� �Ѵٴ� ���� ���� ��������θ� ���������� �߰��ϸ� ��
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
