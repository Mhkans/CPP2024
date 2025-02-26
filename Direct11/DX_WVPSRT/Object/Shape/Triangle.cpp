#include "framework.h"

Triangle::Triangle(Vector2 size, D3D11_PRIMITIVE_TOPOLOGY t)
	: type(t)
{
	Vector2 half_size = Vector2(size.x / 2.0f, size.y / 2.0f);
	// �Է¹��� ����� ���� �ﰢ���� �׸��� ���� ����ؾ� �� �������� ��ġ�� �̸� ���
	

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
	// ���̴��� �����ϴ� �� �ʿ��� �÷��׸� �̸� ����
	VS = new VertexShader(L"Shader/VertexShader/VertexShader.hlsl", flags);
	PS = new PixelShader(L"Shader/PixelShader/PixelShader.hlsl", flags);
	// ���̴� �ּҰ� �ִ� ������ �Է��Ͽ� ���� ���̴��� �ȼ� ���̴��� �����

	VB = new VertexBuffer(verticies.data(), sizeof(Vertex), verticies.size());
	CB = new ColourBuffer();
	// ���̴��� �� �����͵��� �����ߴٰ� �ѱ� �뵵�� ���۵��� ����

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
	// �ȼ� ���̴��� 0�� ���Կ� �� ���۸� ����� �����͸� ����

	VB->Set(type); // ���� ������ �����Ͱ� ����ִ� ���۸� ����,
	// ���ݺ��� ����ϰ��� �ϴ� �����Ͱ� � ������ ����� ������
	// �� �Լ��� ���ؼ� ȣ��
	VS->Set();
	PS->Set();
	DVC->Draw(verticies.size(), 0);

}
