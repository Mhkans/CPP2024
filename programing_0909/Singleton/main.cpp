#include<iostream>

using namespace std;

/*
싱글톤

1. 생성주기를 설정할 수 있어야한다.
2. 한개만 생성
3. 전역에서 접근 가능

사운드매니저를 100개 필요할때 모두 하나씩 갖고있으면 new/delete가 일어나면서 운영체제를 거치기때문에 성능저하가 생김
싱글톤 사운드매니저를 만들어서 사용하면 해결가능

사운드매니저
1. 프로그램 내에서 단 한개
2. 여러가지 사운드를 갖고 , 어디서든 출력도 가능해야함
3. 생성 삭제를 사용자가 조정할 수 있어야함 - 프로그램 시작 / 종료

정적 / 동적

정적 : 컴파일 시간에 생성 , 런타임에 해제되지 않음
동적 : 런타임에 생성 가능, 런타임에 해제 가능
*/

class SoundManager {

private:
	SoundManager() {
		_warriorSound = "WarriorSound";
	}
	~SoundManager() {

	}

public:
	static void CreateInstance() {
		if (_instance == nullptr) {

			_instance = new SoundManager();
		}

	}
	static void DeleteInstance() {

		if (_instance != nullptr) {

			delete _instance;
		}
	}
	static SoundManager* GetInstance() {

		if (_instance != nullptr) {

			return _instance;

		}
		return nullptr;
	}
	void PrintHello() {

		cout << _warriorSound << endl;
	}
private:
	static SoundManager* _instance;
	string _warriorSound;
};



//static 변수는 반드시 전역에서 초기화를 해줘야 한다
SoundManager* SoundManager::_instance = nullptr;

int main() {

	SoundManager::CreateInstance();

	SoundManager::GetInstance()->PrintHello();

	SoundManager::DeleteInstance();

	return 0;
}

//static

//class Marine {
//
//public:
//	void PrintInfo() {
//
//		cout << _hp << endl;
//		cout << _atk << endl;
//	}
//
//	//정적멤버함수 : 멤버함수를 전역함수처럼 만들어줌
//
//	//멤버함수 호출 조건
//	//1. 어디 산하인지 알 수 있어야 한다
//	//2. 객체가 있어야 한다.
//	static void Hello() {
//
//		cout << "Hello World" << endl;
//		cout << _atk << endl;
//		//cout << _hp << endl; 을 쓸수 없는 이유 : 누구의 hp인가 모름
//		//정적멤버함수는 static멤버 변수에만 접근해서 사용 할 수 있다.
//	}
//public:
//	int _hp;
//	static int _atk;
//};
//int Marine::_atk = 0;

/*
	Marine::_atk = 5;
	Marine::Hello();

	Marine* arr[100];

	for (int i = 0; i < 100; i++) {

		arr[i] = new Marine;
		arr[i]->_hp = 50;

	}

	//공격력 업

	for (int i = 0; i < 100; i++) {

		arr[i]->PrintInfo();


	}



	for (int i = 0; i < 100; i++) {

		delete arr[i];
	}
	*/