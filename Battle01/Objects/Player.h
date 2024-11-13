#pragma once
class Monster;

class Player : public Creature
{
public:
	Player(string name, int hp, int atk);

	void RangeAttack(Creature* arr[], int size) {

		for (int i = 0; i < size; i++) {

			this->Attack(arr[i]);
			arr[i]->PrintInfo();
		}
	}
};
