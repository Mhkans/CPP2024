#pragma once
class Collider : public Transform
/*
�׷��� ���α׷��ֿ��� ������Ʈ�� ������Ʈ�� �浹�ߴ��� �Ǵ��� ����
�� ������Ʈ���� "�浹����"�� �����صΰ�,
�� �� ������Ʈ�� �浹������ Ư�� �˰����� ���� ���ؼ�
�� �˰����� ��� ���ο� ���� �浹���θ� �˻�

�� Ŭ������ �ٷ� �� ������Ʈ�� �浹���� �� ��ü�� �����ϴ� �θ� Ŭ����
�� Ŭ������ ������ ��ӹ޾� ������ ���� ������ �ڽ� Ŭ������ ���� ��
*/
{
public:
	enum class TYPE
	{
		RECT,
		CIRCLE
	};
	// � �浹������ �ٷ���� ǥ���ϴ� �� ����� ������ Ŭ����
	// 2D ȯ�濡�� �ַ� ���Ǵ� �浹 ������ �� ��(�簢��, ����)�̱� ������,
	// �� ���������� �� �Ѹ� �ٷ� 
	// - �ٸ��� ���� �������� ���� �� �������� �����ؼ� ����� ��찡 ��κ�

protected:	
	TYPE type;

	VertexShader* VS;
	PixelShader* PS;

	VertexBuffer* VB;
	ColourBuffer* CB;

	vector<VertexPos> vertices;

	static bool debug_mode; // ���� ���߿� �ٷ� ����̹Ƿ� ������ ���� ����

public:
	Collider();
	virtual ~Collider();

	void Render();

	TYPE GetType() { return type; }

	static void SetDebugMode() { debug_mode = !debug_mode; }

	virtual bool isCollision(Collider* collider, Vector2* overwrap = NULL);
	// �������� �浹������ �ٷ�� �Լ���...�ε�,
	// ��Ȯ���� ���� �浹 �˻��Լ����� �θ��� ����

	// �Ʒ��� 3�� ���� �����Լ��鿡 �θ� Ŭ�������� �����ϴ� ������ �ô´�, ��� ����

	virtual bool isPointCollision(Vector2 point) = 0;
	virtual bool isCircleCollision(class CircleCollider* collider) = 0;
	virtual bool isRectCollision(class RectCollider* collider,
		Vector2* overwrap = NULL) = 0;
	// �ڽ� Ŭ���� �� ��ü�� �θ� Ŭ�������� ����ؾ� �ϴ� ��Ȳ�� �� ���,
	// �׳� ����� �Ǹ� �θ� Ŭ������ �����ϴ� �������� �ڽ� Ŭ�������� ����Ǿ����� �ʾ�
	// � ���� ȣĪ�ϴ� �̸����� �����Ϸ��� �ν����� ����
	// �׷��� "���� ���� �ϴ� Ŭ������"��� ������ �صθ�
	// ���߿� �������� �� �� �����Ϸ��� �ϴ� Ŭ������� �ν��� �صΰ�
	// ������ �� ������ ã�ư� ���� �� Ŭ�������� ����� �κ��� ã�ư� �����ϰ� �ǵ��� �ϴ� ��
	
	void SetColor(float r, float g, float b)
	{
		CB->data.colour = Float4(r, g, b, 1);
	}

protected:
	virtual void CreateLine() = 0; // �������� �����ϴ� �Լ�

};