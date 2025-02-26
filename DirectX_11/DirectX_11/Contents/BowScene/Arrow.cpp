#include "framework.h"
#include "Arrow.h"
#include "Bow.h"
#include"Bow_Monster.h"
Arrow::Arrow(shared_ptr<class Bow> bow)
{
	_arrow = make_shared<Quad>(L"Resource/Bullet.png");
	_collider = make_shared<CircleCollider>(CENTER, _arrow->ImageSize().x / 10);
	_collider->GetTransform()->SetScale(0.15f);

	_arrow->GetTransform()->SetParent(_collider->GetTransform());
	_bow = bow;

}

Arrow::~Arrow()
{
}

void Arrow::PreUpdate()
{
	if (!isActive) {
		return;
	}
	_collider->Update();
}

void Arrow::Update()
{
	_arrow->Update();

	if(!isActive){
		if (!_bow.expired()) {
			_collider->GetTransform()->SetLocalLocation(_bow.lock()->GetCollider()->GetTransform()->GetWorldLocation());
		}
		return;
	}

	if (_collider->GetTransform()->GetWorldLocation().x <0 ||
		_collider->GetTransform()->GetWorldLocation().x > WIN_WIDTH ||
		_collider->GetTransform()->GetWorldLocation().y > WIN_HEIGHT ||
		_collider->GetTransform()->GetWorldLocation().y < 0) {

		isActive = false;
	}
	
	_collider->GetTransform()->AddLocalLocation(_dir * _arrowSpeed * DELTA_TIME);
}

void Arrow::Render()
{
	if (!isActive) {
		return;
	}
	_arrow->Render();
}

void Arrow::PostRender()
{
	if (!isActive) {
		return;
	}
	_collider->Render();
}

bool Arrow::Collision(shared_ptr<class Bow_Monster> monster)
{
	return _collider->IsCollision(monster->GetCollider());
}

