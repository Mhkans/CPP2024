#pragma once
class Mage :public Player

{
public:

	Mage(string name);
	virtual void Attack(Creature* m) override;
	virtual int GetAtk();

protected:
	int _num;
};
