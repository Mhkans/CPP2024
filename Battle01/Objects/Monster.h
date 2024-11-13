#pragma once
class Monster : public Creature
{
public:
	Monster(string name, int hp, int atk);
	virtual void Attack(Creature* p) override;

};

