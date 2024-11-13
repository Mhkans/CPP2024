#pragma once

class BossWorld
{
public:
	BossWorld();

	~BossWorld();

	void Init();

	void Update();

	bool End();

private:

	vector<pair<Creature*, int>> _players;
	Creature* _boss;
	bool _PlayerDead =false;
	int _playerCount = 0;
	int _bossCount = 4;
};


