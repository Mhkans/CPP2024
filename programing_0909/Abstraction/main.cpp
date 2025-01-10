#include<iostream>

using namespace std;

/*
인터페이스

접근하고자 하는 기능이나 데이터에 접근(읽기 쓰기)하기 위한 수단 (ex 설정창을 통해 게임 환경을 조절 ,인벤토리로 아이템 버리기)

추상화

동물 이라는 추상화된 개념
은행 이라는 추상화된 개념

1. 객체화 될 수 없다 -> 개념이다 (객체 : 기능과 속성을 갖고 메모리에 올라가있는것)
2. 순수가상함수가 하나 이상 포함되면 추상클래스다.
3. 추상클래스의 자식을 객체화 시키려면 순수가상함수를 정의해 줘야한다 -> 순수가상함수를 오버라이딩 하지 않으면 해당 클래스도 추상클래스

추상클래스를 쓰는이유

1.추상개념이라 객체화 시키면 안되는 클래스
2.가상함수를 무조건 구현해줘야 하는 경우 -> 자식클래스에서 무조건 오버라이딩이 필요한 경우
(자식클래스로 만들어진 객체는 무조건 갖고있어야 하는 고유한 기능)


*/
class Bank { // 추상클래스

public:
	virtual void PrintInfo() abstract{ // abstract 순수가상함수
		/*
		cout << _money << endl;
		cout << "은행입니다 " << endl;*/
	}
protected:
	int _money;
};
class Kakao:public Bank {

public:
	virtual void PrintInfo() override {// 순수가상함수 오버라이딩 -> 인터페이스 구현
		//c++ 기준 : protected 멤버변수에 접근할수있는 수단을 제공하라

		cout << "카카오 뱅크 입니다 " << endl; 
		cout << "예금하신 금액은 :" << _money << endl;

	}

};
class ShinHan :public Bank {

public:
	virtual void PrintInfo() override {
		

		cout << "신한은행 입니다 " << endl;
		cout << "예금하신 금액은 :" << _money << endl;

	}

};


int main() {


	//Bank* b = new Bank(); 추상화된 개념은 동적할당조차 되면 안됨
	Bank* k = new Kakao();
	k->PrintInfo();


	return 0;
}