#include "framework.h"
#include "Arrow.h"

Arrow::Arrow()
{
	_arrow = make_shared<Quad>(L"Resource/Bullet.png");
	_collider = make_shared<CircleCollider>(Vector(20, 0), 20);

	_collider->GetTransform()->SetParent(_arrow->GetTransform());
}

Arrow::~Arrow()
{
}

void Arrow::Update()
{
	_collider->Update();
	_arrow->Update();

	if(!isActive){
		_arrow->GetTransform()->SetLocalLocation(Vector(-5000, -5000));
		return;
	}

	if (_arrow->GetTransform()->GetWorldLocation().x <0 ||
		_arrow->GetTransform()->GetWorldLocation().x > WIN_WIDTH ||
		_arrow->GetTransform()->GetWorldLocation().y > WIN_HEIGHT ||
		_arrow->GetTransform()->GetWorldLocation().y < 0) {

		isActive = false;
	}
	
	_arrow->GetTransform()->AddLocalLocation(Vector(cosf(_angle) , sinf(_angle)) * _arrowSpeed * DELTA_TIME);
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

