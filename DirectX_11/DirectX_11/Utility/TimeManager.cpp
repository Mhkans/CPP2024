#include "framework.h"
#include "TimeManager.h"

TimeManager* TimeManager:: _instance = nullptr;

TimeManager::TimeManager()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency);
	QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);
	//슬로우모션 : 1.0을 낮춘다 , 일시정지 1.0 -> 0으로
	_timeScale = 1.0 / (double)_periodFrequency; 
}

TimeManager::~TimeManager()
{
}

void TimeManager::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*) &_curTime);
	_deltaTime = (double)(_curTime - _lastTime) * _timeScale;

	if (_lockFPS != 0) {
		while (_deltaTime < (1.0 / _lockFPS)) {
			QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			_deltaTime = (double)( _curTime- _lastTime) * _timeScale;

		}
	}
	_lastTime = _curTime;

	_frameCount++;
	_oneSecCount += _deltaTime;

	if (_oneSecCount > 1) {
		_oneSecCount = 0;
		_frameRate = _frameCount; //fps
		_frameCount = 0; 
	}

	_runTime += _deltaTime; //실제 흐른 시간
}
