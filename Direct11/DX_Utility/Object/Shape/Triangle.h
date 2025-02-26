#pragma once
class Triangle : public Shape
// 저번 프로젝트의 Triangle과 똑같이 삼각형을 담당하는 클래스
// 단, 이번엔 Transform을 통해서 SRT 변환 행렬을 적용시킨 상태
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