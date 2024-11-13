#pragma once
class Knight : public Player
{
	// Knight는 피가 50프로 이하일 때
	// 데미지 2배 추가
	
public:
	Knight(string name);
	virtual void Attack(Creature* m) override;

};

