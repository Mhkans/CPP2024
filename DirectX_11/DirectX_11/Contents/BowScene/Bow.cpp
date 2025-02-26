#include "framework.h"
#include "Bow.h"
#include "Arrow.h" 

Bow::Bow()
{
	_bow = make_shared<Quad>(L"Resource/Bow.png");
	_collider = make_shared<RectCollider>(Vector(0,0), _bow->ImageSize());
	_bow->GetTransform()->SetParent(_collider->GetTransform());
}

Bow::~Bow()
{
}

void Bow::Init()
{
	for (int i = 0; i < _arrowCount; i++) {
		auto arrow = make_shared<Arrow>(shared_from_this());
		_arrows.push_back(arrow);
	}
}

void Bow::PreUpdate()
{
	_collider->Update();
	for (auto arrow : _arrows) {
		arrow->PreUpdate();
	}
	_dir = mousePos - _collider->GetTransform()->GetWorldLocation();
	auto dir = _dir.Normalize();
	_collider->GetTransform()->SetAngle(dir.Angle());
}

void Bow::Update()
{
	_bow->Update();
	for (auto arrow : _arrows) {
		arrow->Update();
	}
	_delay += DELTA_TIME;
	ShootArrow();

}

void Bow::Render()
{
	_bow->Render();
	for (auto arrow : _arrows) {
		arrow->Render();
	}
}

void Bow::PostRender()
{
	_collider->Render();
	for (auto arrow : _arrows) {
		arrow->PostRender();
	}
	
}

void Bow::ShootArrow()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x08001 && (_delay > 1.0f)) {

		auto iter = std::find_if(_arrows.begin(), _arrows.end(), [](shared_ptr<Arrow> arrow)->bool
		{
			return !arrow->isActive;
		});

		if (iter != _arrows.end())
		{
			(*iter)->isActive = true;
			auto dir = _dir;
			(*iter)->SetDir(dir);
			_delay = 0.0f;
		}
	}
}
