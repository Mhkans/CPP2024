#pragma once
class TimeManager
{private:
	TimeManager();
	~TimeManager();
public:
	static void Create() {
		if (_instance == nullptr) {
			_instance = new TimeManager();
		}
	}
	static void Delete() {
		if (_instance != nullptr) {
			delete _instance;
		}
	}
	static TimeManager* Instance() { return _instance; }

	void Update();

	void SetLockFPS(double value) { _lockFPS = value; }
	int GetFPS() { return _frameRate; }

	double GetDeltaTime() { return _deltaTime; }
	double GetRunTime() { return _runTime; }

private:
	static TimeManager* _instance;

	double _timeScale = 0.0;
	double _deltaTime = 0.0;//시간변화랑

	unsigned __int64 _curTime = 0;
	unsigned __int64 _lastTime = 0;
	unsigned __int64 _periodFrequency = 0; //초당 cpu 진동수

	UINT _frameRate = 0;
	UINT _frameCount = 0;

	double _oneSecCount = 0.0;
	double _runTime = 0.0;
	double _lockFPS = 0.0;
};

