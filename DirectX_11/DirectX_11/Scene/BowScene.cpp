#include "framework.h"
#include "BowScene.h"
#include "Contents/BowScene/Bow.h"
#include "Contents/BowScene/Arrow.h"
#include "Contents/BowScene/Bow_Monster.h"
BowScene::BowScene()
{
	_tip = make_shared<Transform>();

	_bow = make_shared<Bow>();
	_bow->GetCollider()->GetTransform()->SetScale({ 1.2f,1.2f });
	_bow->GetCollider()->GetTransform()->SetLocalLocation(Vector(100, 100));

	for (int i = 0; i < _arrowCount;i++) {
		auto arrow = make_shared<Arrow>();
		arrow->GetArrow()->GetTransform()->SetScale({ 1.3f,1.3f });
		auto bowPos = _bow->GetCollider()->GetTransform()->GetLocalLocation();
		arrow->GetArrow()->GetTransform()->SetLocalLocation(bowPos);
		_arrows.push_back(arrow);
	}
	_monster = make_shared<Bow_Monster>();
	_monster->GetMonster()->GetTransform()->SetScale({ 2.0f,2.0f });
	_monster->GetMonster()->GetTransform()->SetLocalLocation(CENTER + Vector(200, 200));


	_tip->SetParent(_bow->GetCollider()->GetTransform());
	_tip->SetLocalLocation(Vector(50.0f, 0));

}

BowScene::~BowScene()
{
}

void BowScene::ShootArrow(float angle)
{
	_deltaTime += DELTA_TIME;
	
	if (GetAsyncKeyState(VK_LBUTTON) & 0x08001 && _delay < _deltaTime) {
		auto Iter = std::find_if(_arrows.begin(), _arrows.end(), [](shared_ptr<Arrow> arrow) {

			return !arrow->isActive;
		});
		if (Iter != _arrows.end()) {
			(*Iter)->isActive = true;
			auto bowPos = _tip->GetWorldLocation();

			(*Iter)->GetArrow()->GetTransform()->SetLocalLocation(bowPos);

			(*Iter)->SetAngle(angle);
			_deltaTime = 0.0f;
		}
	}
}

void BowScene::SetAngle(shared_ptr<Quad> obj, float angle)
{
	obj->GetTransform()->SetAngle(angle);
}

void BowScene::PreUpdate()
{
	bool isCollision = false;

	for (auto arrow : _arrows) {
		if (arrow->GetCollider()->IsCollision(_monster->GetCollider())) {
			arrow->GetCollider()->SetRed();
			isCollision = true;
		}
		else {
			arrow->GetCollider()->SetGreen();
		}
	}

	if (isCollision) {
		_monster->GetCollider()->SetRed();
	}
	else {
		_monster->GetCollider()->SetGreen();
	}
}

void BowScene::Update()
{
	_bow->Update();
	_monster->Update();
	for (auto arrow : _arrows) {
		arrow->Update();
	}
	_tip->Update();

	Vector dir = (mousePos - _bow->GetCollider()->GetTransform()->GetLocalLocation()).Normalize();
	float cross = dir.Cross(Vector(1, 0));
	float dot = dir.Dot(Vector(1, 0));
	
	angle = -atan2f(cross, dot);

	SetAngle(_bow->GetCollider(), angle);
	for (auto arrow : _arrows) {
		if (!arrow->isActive) {
			SetAngle(arrow->GetArrow(), angle);
		}
	}
	
	ShootArrow(angle);

}

void BowScene::Render()
{

	_bow->Render();
	_monster->Render();
	for (auto _arrow : _arrows) {
		_arrow->Render();
	}
}

void BowScene::PostRender()
{
	for (auto arrow : _arrows)
	{
		arrow->PostRender();
	}
	_monster->PostRender();

}
