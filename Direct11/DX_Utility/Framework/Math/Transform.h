#pragma once
/*
Trnasform(Ʈ������) : ��ǻ�� �׷��ȿ��� �� ������Ʈ�� �����ϴ� �⺻ ����

Ʈ�������� �ٷ� �� ��ǥ, ũ��, ȸ���� ���� �����ϰ� �����ϴ� �⺻ ������ �������� Ī�ϴ� ����
-> ������Ʈ�� ǥ���ϱ� ���� �ݵ�� �ϳ����� ������ �ִ� ���� ���� ����

������ �츮�� DX���� ������ ���� ��,
3D �������� �� ������Ʈ�� ��� ��ġ, ��� �������� ��� ũ�⸦ ������ �ִ��� 
SRT ��ȯ �� WVP ��ȯ �̷��� ���� ������ �� Ʈ�������� �̿��� ������ ����

*/

class Transform
{
protected: 
	Matrix world; 
	// �� ������Ʈ(=Ʈ������)�� ���� ���带 ����ϴ� ��� = �� ������Ʈ�� ���� ���
	// ������Ʈ�� �ٷ� �� ��� ���������� �� �������� ����� ���·� ������
	// �̸� ���� ���̴��� ���� ��ȯ�� ����ϵ��� �ѱ�� ����

	MatrixBuffer* WB; 
	// ���� ���� ����� ���̴��� �ѱ� �� �԰ݿ� �°� ������ ����� ��� ����

	Vector2 pivot;
	// ���� ������ �ٷ��� ���� ����
	// ���߿� ����� �����̶�� �����ϸ� OK

	Matrix* parent;
	// �� ������Ʈ�� �ٸ� ������Ʈ�� �� ��ġ ���� �����ϰ� ���� ���
	// �� �����ϴ� ������Ʈ�� ���� ����� �����ϴ� �뵵�� ����ϴ� ���

	Matrix S, R, T, P, IP; 
	// SRT ��� ��ȯ�� ���� ��ȯ ��ĵ��� ������ ���
	// P�� IP�� ���� pivot�� �̿��� �� ����ϴ� ����̴� ������ �����ص� OK

	XMFLOAT4X4 mat_world; 

	Vector2 global_scale;

	Vector2 right;
	Vector2 up;

public:
	bool is_active; // �� ������Ʈ�� Ȱ��ȭ�Ǿ��ִ����� ���θ� �����ϴ� �÷���

	Vector2 pos; // �� ������Ʈ�� ������ �ִ� ��ǥ
	Vector2 scale; //         ''			ũ��
	Float3 rot;  //			  ''			ȸ����
	// �� Transform�� ��ġ���ִ� ������ ���� �� ȸ���� x/y/z�� ��������
	// ���� 0���� �������� �Ͽ� �󸶳� ȸ�����ִ°��� �����ϴ� ���
	
	// �� ���������� XY��� �ϳ����� �̿��ϰ� �ֱ� ������,
	// X�� ȸ���� Y�� ȸ���� �츮�� �ٷ� ���� ����
	// ���� XY��鿡�� ��ȿ�� Z�� ȸ������ �ٷ�� �ǹǷ� �츮�� Float3�� rot�� �� �� z���� �̿��� ��


	Transform(Vector2 p = Vector2(0, 0), Vector2 s = Vector2(1, 1), float a = 0,
			Matrix* parent = NULL);
	~Transform();

	float GetAngle() { return rot.z; } // ����ߵ� 2D�� �ٷ�� �ִ� �� ������Ʈ����
	// z�� ȸ������ �̿��ϰ� �ǹǷ� �װ͸� �ٷ�� ��
	void SetAngle(float a) { rot.z = a; }

	void SetActive(bool active) { is_active = active; }
	bool GetActive() { return is_active; }

	void SetParent(Matrix* parent) { this->parent = parent; }

	void WorldUpdate();
	// ������Ʈ�� ���α׷� �󿡼� ������Ʈ�ϴ� ����
	// �׷��� ������Ʈ�� �����Ͱ� ���̴� �ʿ� �Ѿ �� �ֵ��� �����͸� �������ϴ� ������ �ʿ���
	// ����, ������Ʈ �������� ����� �з����͸� ���� ��Ŀ� �ݿ���Ű�� ����,
	// �׻� ������Ʈ �� ���������� �ϴ� SRT ��ȯ ����� ���ϴ� �Լ�

	Matrix* GetWorld() { return &world; };
	// �׷��� ��������� ������Ʈ�� ���� ����� Ʈ������ �ܺο��� ����ؾ� �ϴ� ��찡 �ſ� ���� ������,
	// �̸� ���� ������ �����ڸ� ������

	Vector2 GlobalPos()
	{
		return Vector2(mat_world._41, mat_world._42);
	}
	Vector2 GlobalScale() 
	{
		return global_scale;
	}

	Vector2 Right() { return right.Normalized(); }
	Vector2	Left() { return right.Normalized() * -1.0f; }
	Vector2 Up() { return up.Normalized(); }
	Vector2 Down() { return up.Normalized() * -1.0f; }

};

