#include<iostream>

using namespace std;

//Data 영역 - 전역변수 정적변수 
//생성주기 : 프로그램 실행 시 할당 / 프로그램 종료 시 해제

static int aInt = 1;
int bInt = 1;

class Marine {

public:
	Marine():_hp(40),_armor(1){}
	~Marine(){}
	//멤버함수 호출조건
	//1. 객체가 존재 2. 어디 산하에 있는지 알아야함
	void Upgrade_ATK1() { marine_atk++; }
	//정적멤버함수
	//1. 객체가 없어도 호출 가능 2. 모든 객체들이 바라보고있는 공유 함수 3. 정적 멤버변수만 접근 가능 
	static void Upgrade_ATK2() { marine_atk++; }
	
private:
	int _hp;
	int _armor;
	static int marine_atk;

};

//정적 멤버변수는 외부에서 초기화 해야한다
int Marine::marine_atk = 5;

int main() {

	Marine marine[50];
	Marine::Upgrade_ATK1();
	Marine::Upgrade_ATK2();
	return 0;
}
