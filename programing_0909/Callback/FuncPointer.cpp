#include<iostream>

using namespace std;


//함수포인터
/*
선언방법 : (반환자료형) (*포인터 이름) (매개변수)
void(*func)(void);
*/
void(*func)(void); //타고들어간 함수의 시그니처



void HelloWorld() {

	cout << "Hellow World" << endl;
}

void HelloClass() {

	cout << "Hello Class" << endl;
}

void PrintNum(int num) {

	cout << num << endl;
}


int main() {

	func = &HelloWorld;
	


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