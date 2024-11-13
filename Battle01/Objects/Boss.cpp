#include "framework.h"
#include "Boss.h"


Boss::~Boss()
{
}



Boss::Boss(string name , int hp, int atk) 
	:Goblin(name,hp,atk)
{
}

void Boss::Attack(Creature* p)
{
	if (p == nullptr)
		return;

	p->TakeDamage(_atk);
	SoundManager::GetInstance()->PrintGoblinSound();
	cout << "--------------------" << endl;
	p->PrintHP();
	cout << "--------------------" << endl;
}
