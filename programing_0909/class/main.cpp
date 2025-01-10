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
int Plus(int a, int b)  {
	return a + b;
}
float Plus(float a, float b) {
	return a + b;
}
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

	cout << Plus(1, 2);
	cout << Plus(1.0f, 3.0f);
	return 0;
}
//ctr + r+ r 일괄바꾸기

/*
함수 오버로딩 
-매개변수의 개수나 매개변수의 자료형이 달라도 같은 이름으로 함수를 여러개 정의 할 수 있는 기능
반환형은 달라져도 매개변수의 개수나 자료형이 같다면 같은함수로 인식하므로 오버로딩 불가능
컴파일타임에 함수가 결정되고 이것을 정적 바인딩 이라고 한다
예시) 
int Plus(int a, int b)  {
	return a + b;
}
float Plus(float a, float b) {
	return a + b;
}

함수 오버라이딩
-부모 클래스에서 정의한 함수를 자식클래스에서 재정의 하는 방법

조건: 함수의 이름이 같아야하고 매개변수의 개수나 자료형이 같아야한다
예시) 부모클래스에서 Attack이라는 함수를 정의할때 자식클래스에서 2회 공격하고싶다면 
함수 오버라이딩을 사용하여 Attack함수를 재정의 하여 2회공격 가능

사용방법은 부모클래스의 Attack함수에 virtual키워드를 붙여서 virtual void Attack(Creature* other) 로 변경

이때 메모리4영역중에 data영역에 virual fuction table이 생성되고 여기서 virtual키워드가 붙은 함수의 포인터를 관리하여
자식클래스의 Attack함수가 호출되면 가상함수테이블에서 여러 Attack중에 자식의 Attack이 호출된다

이렇게 함수를 호출하는 객체를 확인하고 해당 객체의 함수를 런타임에 불러와서 이것을 동적바인딩 이라고 한다
*/