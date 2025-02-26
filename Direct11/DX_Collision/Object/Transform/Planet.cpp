#include "framework.h"

Planet::Planet(Vector2 p, Vector2 s, float a, float size, 
	int vertex_count, float r_s, D3D11_PRIMITIVE_TOPOLOGY t)
	: Transform(p,s,a), rotation_speed(r_s)
{
	shape = new MyPolygon(size, vertex_count, t);
}

Planet::~Planet()
{
	delete shape;
}

void Planet::Update(Matrix* parent)
{
	rot.z += rotation_speed;


	if (this->parent != parent)
		this->parent = parent;
	WorldUpdate();
}

void Planet::Render()
{
	WB->SetVS(0);

	shape->Render();
}
