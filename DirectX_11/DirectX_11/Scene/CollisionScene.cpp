#include "framework.h"
#include "CollisionScene.h"
#include "Math/Collider/CircleCollider.h"
#include "Math/Collider/RectCollider.h"
CollisionScene::CollisionScene()
{
	_rect = make_shared<RectCollider>(Vector(200,0), Vector(100, 100));
	_circle1 = make_shared<CircleCollider>(CENTER, 100);
	_circle2 = make_shared<CircleCollider>(Vector(100,0), 50);

	_circle2->GetTransform()->SetParent(_circle1->GetTransform());
	_rect->GetTransform()->SetParent(_circle1->GetTransform());

	_circle3 = make_shared<CircleCollider>(CENTER - Vector(300, 0), 50);
	_rect2 = make_shared<RectCollider>(CENTER + Vector(300, 0), Vector(100, 50));
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_rect->Update();
	_rect2->Update();
	_circle1->Update();
	_circle2->Update();
	_circle3->Update();

	_rect2->GetTransform()->AddAngle(0.0005f);

	Input();

	if (_rect->IsCollision(mousePos) || _rect->IsCollision(_circle3)
		||_rect->IsCollision(_rect2)){
		_rect->SetRed();
	}
	else {
		_rect->SetGreen();
	}
	
	if (_circle2->IsCollision(mousePos)||_circle2->IsCollision(_circle3)
		|| _circle2->IsCollision(_rect2)) {
		_circle2->SetRed();
	}
	else {
		_circle2->SetGreen();
	}

	
}

void CollisionScene::Render()
{
	_rect->Render();
	_rect2->Render();
	_circle1->Render();
	_circle2->Render();
	_circle3->Render();

}

void CollisionScene::Input()
{
	if (KEY_PRESS('A')) {
		_rect->GetTransform()->AddLocalLocation(Vector(-0.15f, 0));
		_circle2->GetTransform()->AddLocalLocation(Vector(-0.15f, 0));
	}
	if (KEY_PRESS('D')) {
		_rect->GetTransform()->AddLocalLocation(Vector(0.15f, 0));
		_circle2->GetTransform()->AddLocalLocation(Vector(0.15f, 0));
	}
	if (KEY_PRESS('W')) {
		_circle1->GetTransform()->AddAngle(0.001f);
	}
	if (KEY_PRESS('S')) {
		_circle1->GetTransform()->AddAngle(-0.001f);
	}
	if (KEY_PRESS('O')) {
		_circle1->GetTransform()->AddScale(Vector(0.001f,0.001f));
	}
	if (KEY_PRESS('P')) {
		_circle1->GetTransform()->AddScale(Vector(-0.001f, -0.001f));
		if (_circle1->GetTransform()->GetScale().x <= 0) {
			_circle1->GetTransform()->SetScale(Vector(0.001f, 0.001f));
		}
	}
}
