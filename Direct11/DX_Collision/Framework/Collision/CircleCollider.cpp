#include "framework.h"

void CircleCollider::CreateLine()
{
	float angle = 2 * M_PI;

	for (int i = 0; i <= 50; i++)
	{
		vertices.emplace_back(
			cos(angle) * radius,
			sin(angle) * radius);
		angle -= 2.0f * M_PI / 50.0f;
	}

	VB = new VertexBuffer(vertices.data(), sizeof(VertexPos), vertices.size());
}

CircleCollider::CircleCollider(float rad)
	:	radius(rad)
{
	type = TYPE::CIRCLE;
	CreateLine();
}

CircleCollider::~CircleCollider()
{
	delete VB;
}

bool CircleCollider::isPointCollision(Vector2 point)
{
	float distance = (this->pos - point).GetLength();
	if (distance < radius)
		return true;
	else
	    return false;
}

bool CircleCollider::isCircleCollision(CircleCollider* collider)
{
	float distance = (this->pos - collider->pos).GetLength();
	if (distance < radius + collider->GetRadius())
		return true;
	else
		return false;
}

bool CircleCollider::isRectCollision(RectCollider* collider, Vector2* overwrap)
/*
�簢���� ��� �� �� ���� ���� ����� ���� ��������� ���
�� ���� �� �ȿ� ����ִ��� �ƴ����� ���� �浹 ���θ� Ȯ���ϴ� ���

��, �׳� �̴�θ� ����ϸ� �簢���� ȸ���� �������� ���ϴ� �����
�� ȸ���� �����ϱ� ����-

�ƿ� �浹���θ� ����� ���� �����Ͽ� "ȭ�� ��ü�� ���������� ��"���� �����ϴ� ������ �ʿ���
��, ���� ��ü�� "�簢���� ȭ������ ���� ���·� ����"�Ͽ�
������Ʈ ���� ����ϴ� ��ġ�� �簢���� �߾������� ��Ƽ� �� �������� ����ϴ� ���
*/
{

	Matrix T = XMMatrixTranslation(pos.x - collider->pos.x, pos.y - collider->pos.y, 0.0f);
	// �簢���� ȸ���� ���� ������ ���Ͽ�
	// ���⼭�� ����� �ӽ� �d�忡 ������ T ��ȯ ���
	// ���⼭�� �簢���� ��ǥ�� �������� ����ϴ� ��

	// �������� �̹� �浹������ ����� ������ ����� �� ���̹Ƿ�
	// �� ������Ʈ = �� �浹������ Ʈ����ǻ�Ǥ��� ������ �ִ� T����� �ǵ���� �� ��
	// ���� ���� ���� �ۼ�

	Matrix circle_world = S * R * T;
	// S,R�� �� ���� ���� Ʈ���������� ���� ������Ʈ�� �� ����ߴ� ���� �״�� �̿�,
	// T ��ĸ� ���� ��ķ� ��ü�Ͽ� �߾���(=����)�� �簢���� �߽������� �̵�

	circle_world *= XMMatrixRotationZ(-collider->rot.z);
	// �׷��� ���� ���ο� ���� ��Ŀ� �簢���� ȸ�����ִ� ��ŭ �ݴ�������� ȸ����Ŵ

	// �� �Ϸ��� �۾����� ���� "�簢���� ȸ������ �ʾҴ� �������� ��"�� �簢���� ���� ��ġ��
	// �ӽ÷� ������

	XMFLOAT4X4 temp_matrix;
	XMStoreFloat4x4(&temp_matrix, circle_world);
	// ������ ���� ����� ����ϱ� ���� ������ Float4x4 ��Ŀ� ����,

	Vector2 circle_obb_center = Vector2(temp_matrix._41, temp_matrix._42));
	// ���� ��Ŀ��� pos �������� ����
	// �׷��� ����� �����Ͱ� ���� "�� ������������� ��ǥ"

	// �� �����͸� �̿��ؼ� ����� �˰����� ����

	Vector2 half = collider->Size() * 0.5f;
	Vector2 closest; // ���� ���� ����� �簢���� ��


	if (circle_obb_center.x < -half.x)
		closest.x = -half.x;
	else if (circle_obb_center.x > half.x)
		closest.x = half.x;
	else
		closest.x = circle_obb_center.x;

	if (circle_obb_center.y < -half.y)
		closest.y = -half.y;
	else if (circle_obb_center.y > half.y)
		closest.y = half.y;
	else
		closest.y = circle_obb_center.y;

	return (circle_obb_center - closest).GetLength() < GetRadius();
}

/*

���� :

������ �̷��� ���� ��-�簢�� �浹 �Լ���
�簢�� �������� �簢��-�� �浹 �Լ��μ� �����غ� ��

*/