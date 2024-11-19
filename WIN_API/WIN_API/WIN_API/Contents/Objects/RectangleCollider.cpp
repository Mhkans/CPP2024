#include "framework.h"
#include "RectangleCollider.h"

RectangleCollider::RectangleCollider(Vector center, Vector size)
	: _center(center), _halfSize(size * 0.5f)
{
}

RectangleCollider::~RectangleCollider()
{
}

void RectangleCollider::Update()
{
}

void RectangleCollider::Render(HDC hdc)
{
	Rectangle(hdc, Left(), Top(), Right(), Bottom());
}
