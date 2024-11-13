#pragma once
class SoundManager
{
private:
	SoundManager();
	~SoundManager();

public:
	static void CreateInstance()
	{
		if (_instance == nullptr)
			_instance = new SoundManager();
	}

	static void DeleteInstance()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static SoundManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;
		return nullptr;
	}

		
	void PrintGoblinSound();
	void PrintKnightSound();
	void PrintMageSound();
	void PrintArcherSound();
private:
	static SoundManager* _instance;
	string _goblinSound;
	string _knightSound;
	string _mageSound;
	string _archerSound;
	static int _goblinCount;
	static int _knightCount;
	static int _mageCount;
	static int _archerCount;

};


