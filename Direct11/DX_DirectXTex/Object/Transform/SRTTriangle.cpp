#include "framework.h"
#include "SRTTriangle.h"

SRTTriangle::SRTTriangle(Vector2 p, Vector2 s, float a, Vector2 size, D3D11_PRIMITIVE_TOPOLOGY t)
	: Transform(p,s,a)
{
	shape = new Triangle(size, t);
}

SRTTriangle::~SRTTriangle()
{
	delete shape;
}

void SRTTriangle::Update(Matrix* parent)
{
	if (this->parent != parent)
		this->parent = parent;


	WorldUpdate();
}

void SRTTriangle::Render()
{
	WB->SetVS(0);

	shape->Render();
}
