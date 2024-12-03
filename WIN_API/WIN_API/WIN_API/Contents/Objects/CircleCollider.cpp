#include "framework.h"
#include "RectangleCollider.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector center, float radius)
	: _radius(radius)
{
	_type = Collider::Type::CIRCLE;
	_center = center;
	_colors[0] = CreatePen(3, 3, RED);
	_colors[1] = CreatePen(3, 3, GREEN);
	SetGreen();
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Update()
{
}

void CircleCollider::Render(HDC hdc)
{
	int left = _center.x - _radius;
	int right = _center.x + _radius;
	int top = _center.y - _radius;
	int bottom = _center.y + _radius;

	SelectObject(hdc, _colors[_curColor]);
	Ellipse(hdc, left, top, right, bottom);
}

bool CircleCollider::IsCollision(const Vector& pos) const
{
	float length = (pos - _center).Length();
	return length < _radius;
}
bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other) const
{
	float length = (other->Center() - _center).Length() - other->Radius();
	return length<_radius;
}
bool CircleCollider::IsCollision(shared_ptr<RectangleCollider> other) const
{	
	RectangleCollider::OBB_INFO a = other->GetOBB();
	Vector aTob = _center - a.position;
	float d = sqrtf(a.length[0] * a.length[0] + a.length[1] * a.length[1]) + _radius;

	if (d < aTob.Length()) {
		return false;
	}

	Vector normal_ea1 = a.direction[0].NormalVector();
	Vector ea1 = a.direction[0];
	Vector normal_ea2 = a.direction[1].NormalVector();
	Vector ea2 = a.direction[1];
	
	float length = abs(normal_ea1.Dot(aTob)); 
	float lengthB = _radius;
	float lengthA = a.length[0];
	if (length > lengthB + lengthA) {
		return false;
	}
	
	length = abs(normal_ea2.Dot(aTob));
	lengthB = _radius;
	lengthA = a.length[1];
	if (length > lengthB + lengthA) {
		return false;
	}
	return true;
}






