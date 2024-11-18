#include "framework.h"
#include "RectangleCollider.h"

RectangleCollider::RectangleCollider(Vector start, int length, int height)
	:_start(start)
{
	_length = length;
	_height = height;
}

RectangleCollider::~RectangleCollider()
{
}

void RectangleCollider::Render(HDC hdc)
{
	Vector end;
	end.x = _start.x + _length;
	end.y = _start.y + _height;
	Rectangle(hdc, _start.x, _start.y, end.x, end.y);
}
