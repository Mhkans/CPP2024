#include "framework.h"
#include "Cannon.h"

Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(Vector(350,350), 50);
	_barrel = make_shared<Barrel>();
	
	for (int i = 0; i < _ballCount; i++) {

		_balls.push_back(make_shared<Ball>());
	}
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	InputMove(); // �Է��ؼ� �����̰�
	InputBarrelRotation(); // �Է����� �ѽ� ���� ����
	Fire();
	_body->Update();
	_barrel->Update();
	for (auto& _ball : _balls) {
		_ball->Update();

	}
	
}

void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
	for (auto& _ball : _balls) {
		_ball->Render(hdc);

	}
}

void Cannon::Fire()
{		
	if (GetAsyncKeyState(VK_SPACE) & 0x8001 && !_spacebarPressed)
	{
		
		Vector dir = mousePos - _body->Center();
		dir.Normalize();
		_balls[_index]->SetCenter(_barrel->GetBarrelTip());
		_balls[_index]->SetDirection(dir);

  		_index++;
		if (_index >= _ballCount) {
			_index = 0;
		}
		_spacebarPressed = true;
		//�Ʒ��� õõ�� �������� �ϱ�
		//�� ������ ���ư��� �ϱ� �޸� ���� x 
	}
	else if (!(GetAsyncKeyState(VK_SPACE) & 0x8001) && _spacebarPressed)
	{
		_spacebarPressed = false;
	}
}

void Cannon::InputMove()
{
	if(GetAsyncKeyState(VK_LEFT) & 0x8001)
		_body->Center().x -= 3;

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
		_body->Center().x += 3;
}

void Cannon::InputBarrelRotation()
{
	Vector dir = mousePos - _body->Center();
	dir.Normalize();

	_barrel->SetDirection(dir);
}
