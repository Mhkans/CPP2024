#include "framework.h"

bool Collider::debug_mode = true;

Collider::Collider()
{
	is_active = false;

	VS = new VertexShader(L"Shader/VertexShader/VertexPos.hlsl", 2);
	PS = new PixelShader(L"Shader/PixelShader/PixelPos.hlsl");

	CB = new ColourBuffer();
	CB->data.colour = { 0,1,0,1 };
}

Collider::~Collider()
{
	delete CB;
}

void Collider::Render()
{
	if (!is_active || !debug_mode) return;
	// �� �浹������ Ȱ��ȭ�Ǿ����� �ʰų�,
	// �ƴϸ� �浿���� ��ü�� ������� �ʴ� ���� �����Ǿ��ٸ� ������� �ʰ� ����

	WB->Set(world);
	WB->SetVS(0);
	CB->SetPS(0);

	VB->Set(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

	VS->Set();
	PS->Set();
	DVC->Draw(vertices.size(), 0);

	// �� Ŭ�������� ���ǵ� �� ���� ���� ����/������ ���� ���� ������ ���� �ִµ�,
	// �̴� �� �θ� Ŭ������ �߻� Ŭ�����̱� ������ �ν��Ͻ��� ���� ���� ���� ����
	// -> ������ �� �Լ��� ������ ����� ���� �̷� ������� ���� ���ǵ� �ڽ� Ŭ�����̱� ������
	// �ű⼭ ������ ���� �ƹ��� ������ ���� ��
}

bool Collider::isCollision(Collider* collider, Vector2* overwrap)
{
	if (!is_active || !(collider->is_active)) 
		return false;

	switch (collider->type)
	// �� Ŭ������ �ּ� 2���� �̻��� �ڽ� Ŭ������ ���� �߻� Ŭ����
	// ���� ���� ������ ���� Ŭ������ �����̳Ŀ� ����
	// ����ؾ� �� �浹 �˰����� �޶����� ������ �̸� �б⹮�� ���� �и�
	{
	case TYPE::RECT:
		return isRectCollision((RectCollider*)collider, overwrap);

	case TYPE::CIRCLE:
		return isCircleCollision((CircleCollider*)collider);
		
	default:
		break;
	}
	

}
