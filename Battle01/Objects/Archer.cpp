#include "framework.h"
#include "Archer.h"
Archer::Archer(string name) :Player(name, 400, 30), _dex(40)
{
}

void Archer::Attack(Creature* c)
{
	if (c == nullptr)
		return;
	cout << "--------------------" << endl;
	cout << this->GetName() << "의 공격" << endl;
	c->TakeDamage(_atk);
	SoundManager::GetInstance()->PrintArcherSound();
	c->PrintHP();
	cout << "--------------------" << endl;


}


void Archer::TakeDamage(int damage)
{
	if (_dex <= rand() % 99 + 1) {

		cout << "회피 성공" << endl;
		return;
	}
	else {
		cout << "회피 실패" << endl;

		_hp -= damage;

	}
	if (_hp < 0) {

		_hp = 0;

	}
	return;

}
