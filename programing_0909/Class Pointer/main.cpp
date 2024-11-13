#include<iostream>

using namespace std;
//함수 오버라이딩 : 부모의 함수를 자식에서 재정의
//업캐스팅 할때 생기는 문제
//자식의 함수를 어떻게 호출할 것인가 -> 형변환 or 가상함수

//가상함수 테이블(vftable) ptr : 클래스에 가상함수가 하나 이상 포함되면 자동으로 메모리 첫번째 주소에 할당되는 포인터
//이를 이용해서 업캐스팅된 상황에서도 자식의 함수를 호출 할 수있다.

class Player {

public:
	virtual void Attack() {
		cout << "Player Attack" << endl;
	}
	int _hp = 1;
};

class Knight : public Player {

public:
	//가상함수 오버라이딩 : 부모의 함수를 재정의
	//버츄얼 펑션 테이블 : 코드영역의 함수부분을 가리키는 포인터를 담고있음
	virtual void Attack() override {
		cout << "Knight Attack" << endl;
	}
	int _stamina = 2;
};

class Archer : public Player {

public:
	virtual void Attack() override {
		cout << "Archer Attack" << endl;
	}
	int _dex = 3;
};



int main() {

	Player* p = new Player();
	Player* k = new Knight();
	Player* a = new Archer();

	/*
	* //업캐스팅 : 한번에 묶어서관리하기 쉬움
	Player* arr[3];
	arr[0] = new Player();
	arr[1] = new Knight();
	arr[2] = new Archer();

	for (int i = 0; i < 3; i++) {

		delete arr[i];
	}

	*/


	p->Attack();
	k->Attack();
	a->Attack();


	delete a;
	delete k;
	delete p;



	return 0;
}