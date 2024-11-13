#include"framework.h"
#include "World.h"

World::~World()
{
}

void World::Init()
{
	int inputNum = 0;

	cout << "1. knight 2. Mage 3. Archer" << endl;

	cin >> inputNum;

	switch (inputNum) {
	case 1:
		_player = new Knight("Knight");
		break;
	case 2:
		_player = new Mage("Mage");
		break;
	case 3:
		_player = new Archer("Archer");
		break;

	default:
		cout << "wrong number " << endl;

	}

	for (int i = 0; i < 10; i++) {
		_monsters[i] = new Goblin("Goblin" + to_string(i+1));
	}
}

void World::Update()
{
	(dynamic_cast<Player*>(_player))->RangeAttack(_monsters, 10);

	for (int i = 0; i < 10; i++)
	{
		_monsters[i]->Attack(_player);
		_player->PrintHP();

	}
	
}

bool World::End()
{
	if (_player->IsDead())
	{
		cout << "Player가 졌습니다." << endl;
		delete _player;
		for (int i = 0; i < 10; i++) {
			delete _monsters[i];
		}
		return true;
	}

	// monsters check
	if (CheckCreatureArr(_monsters, 10))
	{
		cout << "Monsters가 졌습니다." << endl;
		delete _player;
		for (int i = 0; i < 10; i++) {
			delete _monsters[i];
		}
		return true;
	}

	return false;
}

bool World::CheckCreatureArr(Creature* arr[], int size)
{

	for (int i = 0; i < size; i++) {

		if (arr[i]->IsDead() == false) {
			return false;
		}
	}
	return true;
}
