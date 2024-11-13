#include "framework.h"
#include "Monster.h"

Monster::Monster(string name, int hp, int atk):Creature(name,hp,atk)
{
}

void Monster::Attack(Creature* p)
{
	cout << "Monster 공격 미구현" << endl;
}

