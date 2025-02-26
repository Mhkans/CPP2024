#pragma once
class Triangle : public Shape
// ���� ������Ʈ�� Triangle�� �Ȱ��� �ﰢ���� ����ϴ� Ŭ����
// ��, �̹��� Transform�� ���ؼ� SRT ��ȯ ����� �����Ų ����
{
private:
	D3D11_PRIMITIVE_TOPOLOGY type;
	Vector2 size;

public:
	Triangle(Vector2 size,
		D3D11_PRIMITIVE_TOPOLOGY t = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	~Triangle();


	D3D11_PRIMITIVE_TOPOLOGY GetType() { return type; };

	// Inherited via Shape
	virtual void Render() override;

};