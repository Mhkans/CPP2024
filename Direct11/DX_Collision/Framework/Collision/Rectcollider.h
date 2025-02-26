#pragma once
class RectCollider : public Collider
{
public:
	struct ObbDesc // OBB �浹 �� �����,
		// ���� �� �浹������ ȸ����Ȳ�� �ݿ��ؼ�
		// ������ ����� �� �̿��� �����͸� ������ ����ü
	{
		Vector2 pos; // ��ǥ(=�߾���)
		Vector2 Axis[2]; // ȸ���� �浹������ ���� ���� ����صδ� �迭
		Vector2 half_size; // �� ȸ���� �浹������ ����/�¿� ũ��
	};

private:
	Vector2 size;
	ObbDesc obb_desc;

	virtual void CreateLine() override;

	bool isAABB(RectCollider* rect, Vector2* overwrap = NULL);
	bool isAABB(class CircleCollider* circle, Vector2* overwrap = NULL);
	bool isOBB(RectCollider* rect);
	bool isOBB(class CircleCollider* circle);
	// ������ �˰��� ���� �簢��/���� �浹������ ��ġ������ ���θ� ����ϴ� �Լ���

	float separateAxis(Vector2 seperate, Vector2 e1, Vector2 e2);
	// OBB �浹ó���� ������� ���� ����� �Լ�
	// �� �Լ��� ���������� OBB �˰����� ���� �� �����ϸ鼭 ����

public:
	RectCollider(Vector2 size);
	~RectCollider();

	RectCollider::ObbDesc GetObbDesc(); // ȣ��� �������� �� �浹������ ȸ���� �ݿ���,
	// ���� �浹���� �����͸� �� �ڸ����� ����� ��ȯ�ϴ� �ڵ�

	// Inherited via Collider
	virtual bool isPointCollision(Vector2 point) override;

	virtual bool isCircleCollision(class CircleCollider* collider) override;

	virtual bool isRectCollision(RectCollider* collider, Vector2* overwrap = NULL) override;

	// �� �浹������ ȭ�� �������� ������ �󸶸�ŭ�� ����� ������ �ִ���
	// ��ü ȭ�� ������ ���̷� ȯ���� ��ȯ
	Vector2 Size() { return size * GlobalScale(); }

	float RightVX() { return GlobalPos().x + Size().x * 0.5f; }
	float LeftVX() { return GlobalPos().x - Size().x * 0.5f; }
	float TopVX() { return GlobalPos().y - Size().y * 0.5f; }
	float BottomVX() { return GlobalPos().y + Size().y * 0.5f; }
	// �̻��� 4�� �Լ����� AABB �浹 ó���������� ���Ǵ�,
	// �� �浹������ ��/��/��/�� ������ ���ڶ��� ��ǥ�� ����ϴ� �Լ�

};