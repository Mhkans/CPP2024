#include "framework.h"
#include "Arrow.h"

Arrow::Arrow()
{
	_arrow = make_shared<Quad>(L"Resource/Bullet.png");
}

Arrow::~Arrow()
{
}

void Arrow::Update()
{

	if(!isActive){
		_arrow->GetTransform()->SetLocalLocation(Vector(-5000, -5000));
		return;
	}
	_arrow->Update();

	if (_arrow->GetTransform()->GetWorldLocation().x <0 ||
		_arrow->GetTransform()->GetWorldLocation().x > WIN_WIDTH ||
		_arrow->GetTransform()->GetWorldLocation().y > WIN_HEIGHT ||
		_arrow->GetTransform()->GetWorldLocation().y < 0) {

		isActive = false;
	}
	
	_arrow->GetTransform()->AddLocalLocation(Vector(cosf(_angle) , sinf(_angle)) * _arrowSpeed);
}

void Arrow::Render()
{
	if (!isActive) {

		return;
	}
	_arrow->Render();
}

