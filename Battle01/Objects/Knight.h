#pragma once
class Knight : public Player
{
	// Knight�� �ǰ� 50���� ������ ��
	// ������ 2�� �߰�
	
public:
	Knight(string name);
	virtual void Attack(Creature* m) override;

};

