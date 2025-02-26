#pragma once
class MyPolygon : public Shape
{
private:
	D3D11_PRIMITIVE_TOPOLOGY type;
	int vertex_count; // �� ������ ������ �ִ� �������� ����
	float size; // �� ������ ������

public:
	MyPolygon(float size, int vertex_count,
		D3D11_PRIMITIVE_TOPOLOGY t = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	~MyPolygon();

	D3D11_PRIMITIVE_TOPOLOGY GetType() { return type; }

	void Render();
};