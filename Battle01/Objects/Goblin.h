#pragma once
class Goblin : public Monster
{
public:
	
	Goblin(string name);
	Goblin(string name,int hp , int atk);
	virtual void Attack(Creature* p) override;

};

