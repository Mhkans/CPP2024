#include<iostream>

using namespace std;


//�Լ�������
/*
�Լ��� �Ű������� �Ѱ� ���߿� � �̺�Ʈ �߻� �� ȣ��
��ư - ������ �ൿ�� ������ ������ �ٸ�
*/
void(*func)(void); //Ÿ��� �Լ��� �ñ״�ó
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

		cout << "�п�" << endl;
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
			(pet->*func)(); //��ü�� �����ؾ���
		}
	}
	void SetPetFunc(PETFUNC func) {

		_petFunc = func;
	}
private:
	FUNC _introduce;
	PETFUNC _petFunc; // pet class�� void(void)����Լ��� ����Ű�� �Լ� ������
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