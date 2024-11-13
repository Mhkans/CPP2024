#include "framework.h"
#include "Goblin.h"


Goblin::Goblin(string name)
	:Monster(name, 50 + rand() % 5, 4 + rand() % 2)
{
}

Goblin::Goblin(string name, int hp, int atk)
	:Monster(name,hp,atk)
{
}

void Goblin::Attack(Creature* p)
{
	if (p == nullptr)
		return;

	p->TakeDamage(_atk);
	SoundManager::GetInstance()->PrintGoblinSound();
	p->PrintHP();
}
