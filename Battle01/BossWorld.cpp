#include "framework.h"
#include "BossWorld.h"


BossWorld::BossWorld()
{
	Init();
}

BossWorld::~BossWorld()
{
}

void BossWorld::Init()
{
	
	int inputNum = 0;
	int count = 10;
	_players.resize(count);

	for (int i = 0; i < count; i++) {
		
		cout << "1. knight 2. Mage 3. Archer" << endl;

		cin >> inputNum;

		switch (inputNum) {
		case 1:
			_players[i] = { new Knight("Knight" + to_string(i + 1)) ,0};
			break;
		case 2:
			_players[i] = { new Mage("Mage" + to_string(i + 1)),0 };
			break;
		case 3:
			_players[i] = { new Archer("Archer" + to_string(i + 1)),0 };
			break;

		default:
			cout << "wrong number " << endl;
			i--;
		}
	}
	
	_boss = new Boss("Boss", 10000, 50);

	
	for (const auto& p : _players) {
		std::cout << p.first->GetName() << ": " << p.second << std::endl;
	}
}

void BossWorld::Update()
{
	// 1.전투 - 2.남은 플레이어 확인 반복
	// 1-1 보스를공격 1-2 누적데미지 저장 1-3 데미지 상위 넷 공격
	
	for (auto& p : _players) {

		p.first->Attack(_boss);
		p.second += p.first->GetAtk();
		
	}
	sort(_players.begin(), _players.end(), [](pair<Creature*, int> a, pair<Creature*, int> b)->bool {
		return a.second > b.second;
	});

	for (const auto& p : _players) {
		cout << p.first->GetName() << ": " << p.second << endl;
	}	
	if (_players.size() < _bossCount) {
		_bossCount = _players.size();
	}
	if (_players.size() > 0){
		for (int i = 0; i < _bossCount; i++) {

			_boss->Attack(_players[i].first);
		}
	}
	for (auto Iter = _players.begin(); Iter != _players.end();) {

		if ((*Iter).first->IsDead()) {
			_playerCount++;
			Iter = _players.erase(Iter);
			
		}
		else {
			Iter++;
		}
	}
	
	if (_players.empty()) {
		_PlayerDead = true;
		return;
	}
}

bool BossWorld::End()
{

	if (_boss->IsDead()) {

		cout << "Boss 가 쓰러졌습니다" << endl;
		delete _boss;
		for (auto& p : _players) {

			delete p.first;

		}
		return true;
	}
	if (_PlayerDead) {
		for (auto& p : _players) {

			delete p.first;

		}
		_players.clear();
		cout << "Player들이 쓰러졌습니다" << endl;

		return true;
	}
	return false;
}


