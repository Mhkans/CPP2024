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
	// �Է¹��� ����� ���� �ﰢ���� �׸��� ���� ����ؾ� �� �������� ��ġ�� �̸� ���

	Vector2& hf = half_size;
	// ���۷��� ����� ���� ���� �Լ��� �̸��� ������ ����Ű���� �ϴ� ����
	// ������ ���� hf��� ������ �ٿ��� ��

	vertices_uv.emplace_back(-hf.x, -hf.y, StartUV.x, StartUV.y);
	vertices_uv.emplace_back(+hf.x, -hf.y, EndUV.x, StartUV.y);
	vertices_uv.emplace_back(-hf.x, +hf.y, StartUV.x, EndUV.y);
	vertices_uv.emplace_back(-hf.x, +hf.y, StartUV.x, EndUV.y);
	vertices_uv.emplace_back(+hf.x, -hf.y, EndUV.x, StartUV.y);
	vertices_uv.emplace_back(+hf.x, +hf.y, EndUV.x, EndUV.y);
	// �� UV��� ���� ���� ������ VertexUV���� ����


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
	// �ڱ� �ڽ��� ���� ��Ȱ��ȭ���� ���¸� ������� �ʰ� �Լ� ����

	WB->Set(world);
	WB->SetVS(0);
	CB->SetPS(0);

	VB->Set();
	
	VS->Set();
	PS->Set();
	
	DVC->Draw(vertices_uv.size(), 0);
}
