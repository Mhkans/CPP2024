#pragma once
class SRTTriangle : public Transform
{
private:
	Triangle* shape;

public:
	SRTTriangle(Vector2 p, Vector2 s, float a, Vector2 size,
		D3D11_PRIMITIVE_TOPOLOGY t = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	~SRTTriangle();

	void Update(Matrix* parent = NULL);
	void Render();

	void SetColor(Float4 colour)
	{
		shape->SetColor(colour);
	}
};