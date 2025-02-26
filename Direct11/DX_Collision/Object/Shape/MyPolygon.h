#pragma once
class MyPolygon : public Shape
{
private:
	D3D11_PRIMITIVE_TOPOLOGY type;
	int vertex_count; // 이 도형이 가지고 있는 꼭지점의 개수
	float size; // 이 도형의 반지름

public:
	MyPolygon(float size, int vertex_count,
		D3D11_PRIMITIVE_TOPOLOGY t = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	~MyPolygon();

	D3D11_PRIMITIVE_TOPOLOGY GetType() { return type; }

	void Render();
};