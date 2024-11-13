#pragma once
class Archer : public Player
{
public:
	Archer(string name);
	virtual void Attack(Creature* c) override;
	virtual void TakeDamage(int dagame) override;
public:
	int _dex;
};

