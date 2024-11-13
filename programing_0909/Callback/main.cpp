#include<iostream>

using namespace std;


//함수포인터
/*
함수를 매개변수로 넘겨 나중에 어떤 이벤트 발생 시 호출
버튼 - 누르는 행동은 같지만 과정은 다름
*/
void(*func)(void); //타고들어간 함수의 시그니처
void(*func1)(int); 

typedef unsigned int UINT;
typedef void(*FUNC)();


void HelloWorld() {

	cout << "Hellow World" << endl;
}

void HelloClass() {

	cout << "Hello Class" << endl;
}

void PrintNum(int num) {

	cout << num << endl;
}


class Pet {

public:
	void Bark() {

		cout << "왈왈" << endl;
	}
};

class Player {
public:
	typedef void(Pet ::*PETFUNC)(void);
	void Hello() {
		if (_introduce != nullptr) {

			_introduce();
		}
	}

	void SetIntro(FUNC func) {

		_introduce = func;
	}
	void Attack(Pet* pet,PETFUNC func) {
		cout << "player attack" << endl;
		if (pet != nullptr && func != nullptr)
		{
			(pet->*func)(); //객체가 존재해야함
		}
	}
	void SetPetFunc(PETFUNC func) {

		_petFunc = func;
	}
private:
	FUNC _introduce;
	PETFUNC _petFunc; // pet class의 void(void)멤버함수를 가리키는 함수 포인터
};
int main(){

	func = &HelloWorld;
	func1 = &PrintNum;
	UINT aInt = 12;


	func();
	func1(aInt);

	Pet* pet = new Pet();
	Player* p = new Player();
	//p->_introduce = &HelloWorld;
	//p->Hello();
	//p->_introduce = &HelloClass;
	//p->Hello();
	
	p->SetIntro(&HelloWorld); 
	p->Hello();

	p->SetPetFunc(&Pet::Bark);

	return 0;
}