#include<iostream>

using namespace std;


//�Լ�������
/*
������ : (��ȯ�ڷ���) (*������ �̸�) (�Ű�����)
void(*func)(void);
*/
void(*func)(void); //Ÿ��� �Լ��� �ñ״�ó



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