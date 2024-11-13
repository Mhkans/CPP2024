#include"framework.h"
#include "SoundManager.h"

SoundManager::SoundManager()	
{
	_goblinSound = "goblin sound";
	_knightSound = "knight sound";
	_mageSound = "mage sound";
	_archerSound = "archer sound";
}

SoundManager::~SoundManager()
{
}

void SoundManager::PrintGoblinSound()
{
	if (_goblinCount != 0) {
		cout << _goblinSound << endl;
	}
	_goblinCount--;//다시채우는거 아직 구현못함
}

void SoundManager::PrintKnightSound()
{
	if (_knightCount != 0) {
		cout << _knightSound << endl;
	}
	_knightCount--;
}

void SoundManager::PrintMageSound()
{
	if (_mageCount != 0) {
		cout << _mageSound << endl;
	}
	_mageCount--;
}

void SoundManager::PrintArcherSound()
{
	if (_archerCount != 0) {
		cout << _archerSound << endl;
	}
	_archerCount--;
}
SoundManager* SoundManager::_instance = nullptr;
int SoundManager::_goblinCount = 3;
int SoundManager::_knightCount = 1;
int SoundManager::_mageCount = 1;
int SoundManager::_archerCount = 1;