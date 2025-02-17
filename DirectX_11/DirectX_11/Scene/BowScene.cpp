#include "framework.h"
#include "BowScene.h"
#include "Contents/BowScene/Bow.h"
#include "Contents/BowScene/Arrow.h"
BowScene::BowScene()
{
	_tip = make_shared<Transform>();

	_bow = make_shared<Bow>();
	_bow->GetCollider()->GetTransform()->SetScale({ 1.2f,1.2f });
	_bow->GetCollider()->GetTransform()->SetLocalLocation(Vector(100, 100));

	for (int i = 0; i < _arrowCount;i++) {
		auto arrow = make_shared<Arrow>();
		arrow->GetCollider()->GetTransform()->SetScale({ 1.3f,1.3f });
		auto bowPos = _bow->GetCollider()->GetTransform()->GetLocalLocation();
		arrow->GetCollider()->GetTransform()->SetLocalLocation(bowPos);
		_arrows.push_back(arrow);
	}
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

			(*Iter)->GetCollider()->GetTransform()->SetLocalLocation(bowPos);

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
	//게임로직이 주로 들어감
}

void BowScene::Update()
{
	_bow->Update();
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
			SetAngle(arrow->GetCollider(), angle);
		}
	}
	
	ShootArrow(angle);

}

void BowScene::Render()
{

	_bow->Render();
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
}
