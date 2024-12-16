#include "framework.h"
#include "Block.h"

Block::Block()
{
	_rect = make_shared<RectangleCollider>(Vector(300, 300), Vector(17, 17));
	_rect->SetBlack();

	_brushes.push_back(CreateSolidBrush(RGB(255, 200, 100)));
	_brushes.push_back(CreateSolidBrush(GREEN));
	_brushes.push_back(CreateSolidBrush(RED));
	_brushes.push_back(CreateSolidBrush(RGB(0, 0, 0)));
	_brushes.push_back(CreateSolidBrush(RGB(255, 100, 255)));
}

Block::~Block()
{
	for (int i = 0; i < _brushes.size(); i++) {

		DeleteObject(_brushes[i]);
	}
}

void Block::Update()
{
	_rect->Update();
}

void Block::Render(HDC hdc)
{
	SelectObject(hdc, _brushes[static_cast<unsigned int> (_curType)]);
	_rect->Render(hdc);

}
