#include "framework.h"
#include "Mage.h"
Mage::Mage(string name)
	:Player(name, 500, 15 + rand()%10), _num(rand() % 4 + 1)
{
}
void Mage::Attack(Creature* m)
{
	if (m == nullptr)
		return;
	cout << "--------------------" << endl;
	cout << this->GetName() << "의 공격" << endl;

	cout <<_num<< "회 공격" << endl;
	for (int i = 0; i < _num; i++) {
		m->TakeDamage(_atk);
		m->PrintHP();
	}
	cout << "--------------------" << endl;

	SoundManager::GetInstance()->PrintMageSound();
}

int Mage::GetAtk()
{
	return _num * _atk;
}


