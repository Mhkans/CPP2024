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
	//circle �ΰ� ����� �� ��Ŭ�� ���ӽ�Ų ���¿��� �ٸ���Ŭ �̵� �� ȸ��
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_circle1->Update();//��Ŭ2�� �ڽ����� ���� ������ ������
	_circle2->Update();//��Ŭ1�� ��ӹް� �յڷθ� ������ ���콺����Ʈ�� ���� ����
	_circle3->Update();//�����ִ� Ÿ��

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
