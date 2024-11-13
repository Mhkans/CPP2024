#include "framework.h"
#include "Knight.h"

Knight::Knight(string name):Player(name,600, 25 + rand() % 10)
{
}

void Knight::Attack(Creature* m)
{
	if (m == nullptr)
		return;
	float ratio = (_hp / (float)_maxHp);
	if (ratio <= 0.5) {

		cout << "Power UP" << endl;
		cout << "--------------------" << endl;
		cout << this->GetName() << "의 공격" << endl;

		m->TakeDamage(_atk * 2);

	}
	else {
		cout << "--------------------" << endl;
		cout << this->GetName() << "의 공격" << endl;

		m->TakeDamage(_atk);

	}
	SoundManager::GetInstance()->PrintKnightSound();
	m->PrintHP();
	cout << "--------------------" << endl;

}


