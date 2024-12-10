#include "framework.h"
#include "LineScene.h"

LineScene::LineScene()
{
	_line1 = make_shared<Liner>(Vector(100,100), Vector(0,0));
	_line2 = make_shared<Liner>(Vector(0,500), Vector(1280,500));
	_line3 = make_shared<Liner>(Vector(100,400), Vector(800,100));

	_circle = make_shared<CircleCollider>(Vector(0, 0), 30);

}

LineScene::~LineScene()
{
}

void LineScene::Update()
{
	_line1->_end = mousePos;

	_line1->Update();
	_line3->Update();
	_circle->Update();
	Liner::HitResult result = _line1->IsCollision(_line3);

	if (result.isCollision)
	{
		_line1->SetRed();
		_line2->SetRed();

		_circle->Center() = result.hitPoint;
	}
	else
	{
		_line1->SetGreen();
		_line2->SetGreen();

		_circle->Center() = Vector(-10000, 0);
	}

	//_line1->Update();
	////_line2->Update(); // floor
	//_line3->Update();

	//// line2의 단위벡터 구하기
	//Vector line2Normal = (_line2->_end - _line2->_start).NormalVector();
	//// line1의 벡터 구하기
	//Vector line1V = (_line1->_end - _line1->_start);

	//// 각도 구해서 삼각비
	////float angle = line1V.Angle(line2Normal);
	////float length = line1V.Length() * cos(angle);

	//// 내적(투영)을 활용
	//float length = line2Normal.Dot(line1V);

	////_line3->_end = _line3->_start + line2Normal * length;
}

void LineScene::Render(HDC hdc)
{
	_line1->Render(hdc);
	//_line2->Render(hdc);
	_line3->Render(hdc);
	_circle->Render(hdc);
}
