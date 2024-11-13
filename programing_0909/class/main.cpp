#include<iostream>

using namespace std;


/*
객체 지향 : 객체가 속성과 기능을 갖는 것에 초점을 두고 프로그래밍하는 것
객체 : 속성 기능을 갖고 메모리에 할당되어있는 것

객체 지향의 3속성

1. 은닉성 (캡슐화)
접근지정자
public : 모든곳에서 객체의 멤버에 접근 , 수정 가능
private :  클래스 안에서만(생성자 , 멤버함수) 멤버에 접근 ,수정 가능
protected : 클래스와 자식들 에서만 접근 ,수정 가능

2. 상속성
3. 다형성
*/


class Car {
public: 

	//멤버함수 : 기능 method
	//멤버함수 호출 조건
	//1. 어디 산하에 있는지 알 수 있어야 한다
	//2. 객체가 필요하다

	void SetInfo(int handle, int engine, int doors, int wheels) {

		_handle = handle;
		_engine = engine;
		_doors = doors;
		_wheels = wheels;
	}
	//get set  : 예외처리 가능 , 디버그 가능
	void SetEngine(int engine) {

		if (engine < 0) {

			_engine = 0;

			return;
		}
		_engine = engine;

	}

	int GetEngine() {

		return _engine;
	}

private:
	//멤버변수 : 속성 attribute 
	//컨벤션 : 멤버변수는 앞에 _붙여서 표현하기
	int _handle;
	int _engine;
	int _doors;
	int _wheels;

};

//상속 
/*
is - a 관계 성립

Animal 클래스 , Cat 클래스

Cat is Animal - O
Animal is Cat - X

한쪽만 성립해야함

부모의 public , protected 속성과 기능을 모두 물려받는다 : 코드의 재사용성

클래스는 설계도 code영역에 있고 할당은 안됨

*/

//다형성
/*
1. 오버로딩 : 함수에서 매개변수의 개수나 자료형을 다른 함수로 정의하는 것
2. 오버라이딩 : 부모의 함수를 새로 재정의 하는것 단 함수 시그니쳐와 함수 이름이 동일해야한다
*/
class Animal {

public:
	void Eat() {
		cout << "냠냠 " << endl;
	}
protected:
public:
	int _mouth;
};

class Cat : public Animal { // public 상속 

public:
private:

public: 
	int _legs;
};
class Creature {

public:
	void Attack() {

		cout << "Creature attack" << endl;
	}

};


class Player:public Creature {
public:

	Player operator+(const Player& other) { // 연산자 오버로딩

		//this : 이 멤버함수를 호출한 객체를 가리키는 포인터
		this->_hp += other._hp;
		return *this;
	}

	void Attack() {

		cout << "Player Attack" << _hp << endl;
	}

	int _hp; 

};


int main() {
	/* 
	//은닉성
	Car myCar;

	// :: 범위지정연산자 
	myCar.Car::SetEngine(3);

	cout << myCar.GetEngine() << endl;
	*/
	/*
	//상속성
	Cat cat;
	cat._mouth = 1;
	cat._legs = 4;
	cat.Eat();
	//cat은 8바이트 

	*/
	/*
	//다형성
	Player p1;
	p1._hp = 1;
	Player p2;
	p2._hp = 2;
	
	Player p3 = p1 + p2; // 연산자 오버로딩

	p3.Creature::Attack(); // 크리쳐의 어택함수
	p3.Attack(); // 플레이어의 어택함수
	*/


	return 0;
}
//ctr + r+ r 일괄바꾸기