#include "framework.h"
#include "Liner.h"

Liner::Liner(Vector start, Vector end):_start(start),_end(end)
{

}

Liner::~Liner()
{
}

void Liner::Update()
{
}

void Liner::Render(HDC hdc)
{
	MoveToEx(hdc, _start.x, _start.y, nullptr);
	LineTo(hdc, _end.x, _end.y);
}
