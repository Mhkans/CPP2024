#include "framework.h"
#include "Player.h"
#include "Bow.h"
#include"Arrow.h"
Player::Player()
{
	_quad = make_shared<Quad>(L"Resource/Player.png");
	_body = make_shared<RectCollider>(CENTER,_quad->ImageSize());

	_quad->GetTransform()->SetParent(_body->GetTransform()); //body¸¦ root component·Î

	_body->GetTransform()->SetScale(0.1f);
	_bow = make_shared<Bow>();
	_bow->GetCollider()->GetTransform()->SetLocalLocation(Vector(0, 0));
	_bow->GetCollider()->GetTransform()->SetParent(_body->GetTransform());
	_bow->GetCollider()->GetTransform()->AddScale(Vector(10, 10));
	_bow->Init();

}

Player::~Player()
{
}

void Player::Init()
{

}

void Player::PreUpdate()
{
	_body->Update();
	_bow->PreUpdate();
}

void Player::Update()
{
	Input();
	Jump();

	_quad->Update();

	if (isFalling == true)
	{
		_body->GetTransform()->AddLocalLocation(Vector(0, 1) * _jumpForce * DELTA_TIME);
		_jumpForce -= DELTA_TIME * 9.8f * 100;
	}
	_bow->Update();
}

void Player::Render()
{
	_quad->Render();
	_bow->Render();
}

void Player::PostRender()
{
	_body->Render();
	_bow->PostRender();
}

void Player::Input()
{
	if (KEY_PRESS('A')) {
		_body->GetTransform()->AddLocalLocation(Vector(-1.0f, 0.0f) * DELTA_TIME * _speed);
		_quad->SetFlipX(1);
	}
	if (KEY_PRESS('D')) {
		_body->GetTransform()->AddLocalLocation(Vector(1.0f, 0.0f) * DELTA_TIME * _speed);
		_quad->SetFlipX(0);
	}
	
}

void Player::Jump()
{
	if (KEY_DOWN(VK_SPACE) && !isFalling) {
		_jumpForce = 600.0f;
		isFalling = true;
	}
}
