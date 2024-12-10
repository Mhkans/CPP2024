#include "framework.h"
#include "Liner.h"

Liner::Liner(Vector start, Vector end):_start(start),_end(end)
{
	_colors[0] = CreatePen(3, 3, RED);
	_colors[1] = CreatePen(3, 3, GREEN);
	SetGreen();
}

Liner::~Liner()
{
	for (auto& pen : _colors)
	{
		DeleteObject(pen);
	}
}

void Liner::Update()
{
	
}

void Liner::Render(HDC hdc)
{
	SelectObject(hdc, _colors[_curColor]);
	MoveToEx(hdc, _start.x, _start.y, nullptr);
	LineTo(hdc, _end.x, _end.y);

}

//bool Liner::IsCollision(shared_ptr<Liner> other)
//{
//	Vector aVector = this->_end - this->_start;
//	Vector bVector = other->_end - other->_start;
//
//	Vector aTobStart = other->_start - this->_start;
//	Vector aTobEnd = other->_end - this->_start;
//	Vector bToaStart = this->_start - other->_start;
//	Vector bToaEnd = this->_end - other->_start;
//	float crossX;
//	float crossY;
//	float x1 = this->_start.x, y1 = this->_start.y;
//	float x2 = this->_end.x, y2 = this->_end.y;
//	float x3 = other->_start.x, y3 = other->_start.y;
//	float x4 = other->_end.x, y4 = other->_end.y;
//
//	float denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
//
//	if (denominator != 0) {
//		float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
//
//		crossX = x1 + t * (x2 - x1);
//		crossY = y1 + t * (y2 - y1);
//
//		//외적으로 좌우판단 -> 각도 처리
//		if (bVector.Cross(bToaEnd) * bVector.Cross(bToaStart) < 0) {
//			if (aVector.Angle() >= aTobStart.Angle() || aVector.Angle() <= aTobEnd.Angle()) {
//				_crossCircle->Center() = Vector(-1000, 0);
//				return false;
//			}
//			else {
//				_crossCircle->Center() = Vector(crossX,crossY);
//				return true;
//			}
//		}
//
//		_crossCircle->Center() = Vector(-1000, 0);
//		return false;
//	}
//}
Liner::HitResult Liner::IsCollision(shared_ptr<Liner> other)
{
	Vector line1_s = _start;
	Vector line1_e = _end;

	Vector line2_s = other->_start;
	Vector line2_e = other->_end;

	Vector line1_sTos = line2_s - line1_s;
	Vector line1_sToe = line2_e - line1_s;

	Vector line2_sTos = line1_s - line2_s;
	Vector line2_sToe = line1_e - line2_s;

	bool isBetween1 = IsBetween((line1_e - line1_s), line1_sTos, line1_sToe);
	bool isBetween2 = IsBetween((line2_e - line2_s), line2_sTos, line2_sToe);

	float left = fabs((line2_e - line2_s).Cross(line1_s - line2_s));
	float right = fabs((line2_e - line2_s).Cross(line1_e - line2_s));

	float ratio = left / (left + right);

	Liner::HitResult result;
	result.isCollision = isBetween1 && isBetween2;
	result.hitPoint = LinearInterpolation(line1_s, line1_e, ratio);

	return result;
}

bool Liner::IsBetween(Vector center, Vector left, Vector right)
{
	float Cross1_s = center.Cross(left); // +
	float Cross1_e = center.Cross(right); // -

	float result = Cross1_e * Cross1_s;

	return result < 0;
}
