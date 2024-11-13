#pragma once

// �����
class Creature
{
public:
	
	Creature(string name, int hp, int atk );
	virtual void Attack(Creature* c) abstract;
	virtual void TakeDamage(int damage);
	bool IsDead();
	virtual ~Creature(); //�θ� �Ҹ��ڿ� virtual�� �ٿ��� ��ĳ���������� �ڽ��� �Ҹ��ڰ� �Ҹ�
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


