#include "framework.h"
#include "CollisionScene.h"
#include "Math/Collider/CircleCollider.h"
#include "Math/Collider/RectCollider.h"
CollisionScene::CollisionScene()
{
	_circle1 = make_shared<CircleCollider>(CENTER, 50);
	_circle2 = make_shared<CircleCollider>(Vector(0,0), 50);
	_circle3 = make_shared<CircleCollider>(CENTER - Vector(300,0), 50);

	_circle2->GetTransform()->SetParent(_circle1->GetTransform());
	//circle 두개 만들고 한 서클을 종속시킨 상태에서 다른서클 이동 및 회전
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_circle1->Update();//서클2를 자식으로 갖고 각도만 움직임
	_circle2->Update();//서클1에 상속받고 앞뒤로만 움직임 마우스포인트와 원에 반응
	_circle3->Update();//가만있는 타겟

	Input();

	if (_circle2->IsCollision(mousePos) || _circle2->IsCollision(_circle3)) {
		_circle2->SetRed();
	}
	else {
		_circle2->SetGreen();
	}
	
	if (_circle3->IsCollision(_circle2)) {
		_circle3->SetRed();
	}
	else {
		_circle3->SetGreen();
	}

}

void CollisionScene::Render()
{
	//_rect->Render();
	_circle1->Render();
	_circle2->Render();
	_circle3->Render();

}

void CollisionScene::Input()
{
	if (KEY_PRESS('A')) {
		_circle2->GetTransform()->AddLocalLocation(Vector(-0.3f, 0));
	}
	if (KEY_PRESS('D')) {
		_circle2->GetTransform()->AddLocalLocation(Vector(0.3f, 0));
	}
	if (KEY_PRESS('W')) {
		_circle1->GetTransform()->AddAngle(0.001f);
	}
	if (KEY_PRESS('S')) {
		_circle1->GetTransform()->AddAngle(-0.001f);
	}

}
