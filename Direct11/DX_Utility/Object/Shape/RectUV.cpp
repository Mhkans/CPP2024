#include "framework.h"
// �׳� �簢�� �ϳ��� ����ϴ� �뵵�� ���� �Ǵµ�,
// ��� ������ ��ü�� ������ ������ �ƴ϶� "�̹���"�� ������ �ִ� �� �ȼ��� ������ ����ϵ��� �ϴ� Ŭ����

RectUV::RectUV(Vector2 size, Vector2 StartUV, Vector2 EndUV, 
	D3D11_PRIMITIVE_TOPOLOGY t)
	: type(type)
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

	VS = new VertexShader(L"Shader/VertexShader/VertexUV.hlsl", 1);
	PS = new PixelShader(L"Shader/PixelShader/PixelUV.hlsl");

	VB = new VertexBuffer(vertices_uv.data(), sizeof(VertexUV), vertices_uv.size());
	CB = new ColourBuffer();
}

RectUV::~RectUV()
{
	delete VS;
	delete PS;
	delete VB;
	delete CB;
}

void RectUV::Render()
{
	CB->SetPS(0);

	VB->Set(type);
	VS->Set();
	PS->Set();
	DVC->Draw(vertices_uv.size(), 0);
}
