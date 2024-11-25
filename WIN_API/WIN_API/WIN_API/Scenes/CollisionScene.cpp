#include "framework.h"
#include "CollisionScene.h"


CollisionScene::CollisionScene()
{
	_fixed = make_shared<RectangleCollider>(Vector(400, 400), Vector(100, 100));
	_moved = make_shared<CircleCollider>(Vector(0, 0),70);
	
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_moved->Center() = mousePos;
	_moved->Update();
	_fixed->Update();
	//점충돌
	/*
	if (_fixedCircle->IsCollision(mousePos)) {
		_fixedCircle->SetRed();
	}
	else {
		_fixedCircle->SetGreen();
	}*/
	//원충돌
	if (_moved->IsCollision(_fixed)) {
		_fixed->SetRed();
	}
	else {
		_fixed->SetGreen();
	}
}

void CollisionScene::Render(HDC hdc)
{
	_moved->Render(hdc);
	_fixed->Render(hdc);
}
