#include "framework.h"
#include "Creature.h"

// ���Ǻ�

// :: -> ��������������

Creature::Creature(string name ,int hp, int atk):_name(name),_hp(hp), _atk(atk),_maxHp(hp) {

	PrintInfo();
};

void Creature::TakeDamage(int damage) {
	_hp -= damage;

	if (_hp < 0) {

		_hp = 0;

	}
	return;

}

bool Creature::IsDead()
{
	if (_hp <= 0)
	{
		return true;
		
	}
	return false;
}
void Creature::PrintHP()
{
	cout << _name << "�� ���� HP : " << _hp << endl;
}

void Creature::PrintInfo()
{
	cout << "name  : " << _name << endl;
	cout << "hp  : " << _hp << endl;
	cout << "atk  : " << _atk << endl;
}

const string& Creature::GetName()
{
	return _name;
}

int Creature::GetAtk()
{
	return _atk;
}

Creature::~Creature() {

	
}


