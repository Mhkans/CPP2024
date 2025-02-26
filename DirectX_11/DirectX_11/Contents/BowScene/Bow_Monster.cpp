#include "framework.h"
#include "Bow_Monster.h"

Bow_Monster::Bow_Monster()
{
	_quad = make_shared<Quad>(L"Resource/monster.png");
	_body = make_shared<CircleCollider>(CENTER+ Vector(100,100), _quad->ImageSize().x/2);

	_quad->GetTransform()->SetParent(_body->GetTransform()); 
	_body->GetTransform()->SetScale(0.4f);

	_HP = _maxHP;
}

Bow_Monster::~Bow_Monster()
{
}

void Bow_Monster::SetValue(float value)
{
	
}

void Bow_Monster::PreUpdate()
{
	_body->Update();

}

void Bow_Monster::Update()
{
	_quad->Update();
	float ratio = _HP / _maxHP;
	//SetValue(ratio);
	_body->GetTransform()->AddLocalLocation(_dir.Normalize() * _speed * DELTA_TIME);

	BossMove();
}

void Bow_Monster::Render()
{
	_quad->Render();
}

void Bow_Monster::PostRender()
{
	_body->Render();
}

void Bow_Monster::BossMove()
{
	Vector pos = _body->GetTransform()->GetLocalLocation();
	if (pos.x < CENTER.x || pos.x > WIN_WIDTH) {		
		SetBossDir(Vector(_dir.x * -1, _dir.y));
	}
	if (pos.y < CENTER.y || pos.y > WIN_HEIGHT) {
		SetBossDir(Vector(_dir.x, _dir.y * -1));
	}

}

void Bow_Monster::BossAttack()
{
}


