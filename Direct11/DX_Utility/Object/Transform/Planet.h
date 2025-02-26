#pragma once
class Planet : public Transform
{
private:
	Shape* shape;
	float rotation_speed;

public:
	Planet(Vector2 p, Vector2 s, float a,
		float size, int vertex_count, float r_s,
		D3D11_PRIMITIVE_TOPOLOGY t = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	~Planet();

	void Update(Matrix* parent = NULL);
	void Render();

	void SetColor(Float4 colour)
	{
		shape->SetColor(colour);
	}
};