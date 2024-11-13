#pragma once
class Boss : public Goblin
{

public:

	~Boss();
	Boss(string name,int hp, int atk);
	virtual void Attack(Creature* p) override;

protected:

	
};

