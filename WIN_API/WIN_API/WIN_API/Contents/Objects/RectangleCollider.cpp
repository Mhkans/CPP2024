#include "framework.h"
#include "RectangleCollider.h"

RectangleCollider::RectangleCollider(Vector center, Vector size)
	:_halfSize(size * 0.5f)
{
	_type = Collider::Type::RECT;
	_center = center;
	_colors[0] = CreatePen(3, 3, RED);
	_colors[1] = CreatePen(3, 3, GREEN);

	SetGreen();
	
}

RectangleCollider::~RectangleCollider()
{
}

void RectangleCollider::Update()
{
}

void RectangleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _colors[_curColor]);
	Rectangle(hdc, Left(), Top(), Right(), Bottom());
}

bool RectangleCollider::IsCollision(const Vector& pos) const
{
	//x가로축기준 사이에 있다
	if (pos.x < Right() && pos.x > Left()) {

		//y세로축 기준 사이에 있다
		if (pos.y<Bottom() && pos.y > Top()) {
			return true;
		}
	}
	return false;
}

bool RectangleCollider::IsCollision(shared_ptr<CircleCollider> other) const
{
	OBB_INFO a = GetOBB();
	Vector aTob = other->Center() - a.position;

	float d = sqrtf(a.length[0] * a.length[0] + a.length[1] * a.length[1]) + other->Radius();
	if (d < aTob.Length())
		return false;

	Vector normal_ea1 = a.direction[0].NormalVector();
	Vector ea1 = a.direction[0];
	Vector normal_ea2 = a.direction[1].NormalVector();
	Vector ea2 = a.direction[1];

	// nea1 기준으로 투영
	float length = abs(normal_ea1.Dot(aTob)); // a To b 길이의 절대값
	float lengthB = other->Radius();
	float lengthA = a.length[0];
	if (length > lengthB + lengthA)
		return false;

	// nea2 기준으로 투영
	length = abs(normal_ea2.Dot(aTob));
	lengthB = other->Radius();
	lengthA = a.length[1];
	if (length > lengthB + lengthA)
		return false;

	return true;
}
bool RectangleCollider::IsCollision(shared_ptr<RectangleCollider> other) const
{
	OBB_INFO a = GetOBB();
	OBB_INFO b = other -> GetOBB();

	Vector aTob = b.position - a.position;

	Vector normal_ea1 = a.direction[0].NormalVector();
	Vector ea1 = a.direction[0];
	Vector normal_ea2 = a.direction[1].NormalVector();
	Vector ea2 = a.direction[1];

	Vector normal_eb1 = b.direction[0].NormalVector();
	Vector eb1 = b.direction[0];
	Vector normal_eb2 = b.direction[1].NormalVector();
	Vector eb2 = b.direction[1];

	//normal_ea1 기준으로 투영
	float length = abs(normal_ea1.Dot(aTob)); //a to b 길이의 절대값

	float lengthB = SeperateAxis(normal_ea1 , eb1 ,eb2);
	float lengthA = a.length[0];
	if (length > lengthB + lengthA) {
		return false;
	}
	
	//normal_ea2 기준으로 투영
	length = abs(normal_ea2.Dot(aTob)); //a to b 길이의 절대값

	lengthB = SeperateAxis(normal_ea2, eb1 ,eb2);
	lengthA = a.length[1];
	if (length > lengthB + lengthA) {
		return false;
	}
	
	//normal_eb1 기준으로 투영
	length = abs(normal_eb1.Dot(aTob)); //a to b 길이의 절대값

	lengthA = SeperateAxis(normal_eb1 , ea1 ,ea2);
	lengthB = a.length[0];
	if (length > lengthB + lengthA) {
		return false;
	}
	
	//normal_eb2 기준으로 투영
	length = abs(normal_eb2.Dot(aTob)); //a to b 길이의 절대값

	lengthA = SeperateAxis(normal_eb2, ea1 ,ea2);
	lengthB = a.length[0];
	if (length > lengthB + lengthA) {
		return false;
	}

	return true;
}

RectangleCollider::OBB_INFO RectangleCollider::GetOBB() const
{
	OBB_INFO info;
	info.position = _center;

	info.direction[0] = { _halfSize.x, 0 };
	info.direction[1] = { 0, -_halfSize.y };

	info.length[0] = _halfSize.x;
	info.length[1] = _halfSize.y;

	return info;
}

float RectangleCollider::SeperateAxis(Vector seperate , Vector e1 , Vector e2) const
{

	float r1 = abs(seperate.Dot(e1));
	float r2 = abs(seperate.Dot(e2));

	return r1 + r2;}
