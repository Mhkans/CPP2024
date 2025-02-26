#pragma once
/* 
���� �浹 ������ �ٸ� ������Ʈ�� ��� �浹 ������ �ұ�?

�� �߿��� ��-�簢�������� ���� ���̵��� ������ �н�
��-��, ��-�� ���̰� �浹�ߴ����� �Ǵ��ϴ� ���� ��� �ϴ� ���ϱ�

�� - �� : ���̶�� ���� �������� ��Ȯ�� ���� �Ÿ� ������ ���� �����̹Ƿ�
		  �˻��ϰ��� �ϴ� ���� ���� ���� ������ �Ÿ��� ���������� �۴ٸ� �浹�� ��
�� - �� : �� ���� �������� �պ��� �� ���� �߽ɳ��� �Ÿ��� �� ������
		  ������ �������� ��������ŭ �׾��� �� ��ġ�� �κ��� ����, �� �浹�� ��
*/

class CircleCollider : public Collider
{
private:
	float radius;
	// ���⼱ Ÿ���� ������� �ʰ� ���� �ۼ�
	virtual void CreateLine() override;

public:
	CircleCollider(float rad);
	~CircleCollider();

	float GetRadius()
	{
		return radius;
	}

	// Inherited via Collider
	virtual bool isPointCollision(Vector2 point) override;
	virtual bool isCircleCollision(CircleCollider* collider) override;
	virtual bool isRectCollision(RectCollider* collider, Vector2* overwrap = NULL) override;
};