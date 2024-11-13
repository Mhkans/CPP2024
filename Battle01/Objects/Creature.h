#pragma once

// 선언부
class Creature
{
public:
	
	Creature(string name, int hp, int atk );
	virtual void Attack(Creature* c) abstract;
	virtual void TakeDamage(int damage);
	bool IsDead();
	virtual ~Creature(); //부모 소멸자에 virtual을 붙여야 업캐스팅했을때 자신의 소멸자가 불림
	void PrintHP();
	void PrintInfo();
	const string& GetName();
	virtual int GetAtk();
protected:
	string _name;
	int _hp;
	int _atk;
	int _maxHp;
};


