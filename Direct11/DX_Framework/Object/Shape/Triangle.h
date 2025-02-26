#pragma once
class Triangle : public Shape
// Shape를 상속받은 한 종류의 도형을 담당하는 클래스
{
private:
	D3D11_PRIMITIVE_TOPOLOGY type;
	// D3D11_PRIMITIVE_TOPOLOGY는 열거형이므로
	// 매번 번거롭게 치지 않게 아예 변수로서 저장

public:
	Triangle(vector<Vertex> v,
		D3D11_PRIMITIVE_TOPOLOGY t = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);


	D3D11_PRIMITIVE_TOPOLOGY GetType() { return type; };
};