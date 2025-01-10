#include<iostream>

using namespace std;


/*
��ü ���� : ��ü�� �Ӽ��� ����� ���� �Ϳ� ������ �ΰ� ���α׷����ϴ� ��
��ü : �Ӽ� ����� ���� �޸𸮿� �Ҵ�Ǿ��ִ� ��

��ü ������ 3�Ӽ�

1. ���м� (ĸ��ȭ)
����������
public : �������� ��ü�� ����� ���� , ���� ����
private :  Ŭ���� �ȿ�����(������ , ����Լ�) ����� ���� ,���� ����
protected : Ŭ������ �ڽĵ� ������ ���� ,���� ����

2. ��Ӽ�
3. ������
*/


class Car {
public: 

	//����Լ� : ��� method
	//����Լ� ȣ�� ����
	//1. ��� ���Ͽ� �ִ��� �� �� �־�� �Ѵ�
	//2. ��ü�� �ʿ��ϴ�

	void SetInfo(int handle, int engine, int doors, int wheels) {

		_handle = handle;
		_engine = engine;
		_doors = doors;
		_wheels = wheels;
	}
	//get set  : ����ó�� ���� , ����� ����
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
	//������� : �Ӽ� attribute 
	//������ : ��������� �տ� _�ٿ��� ǥ���ϱ�
	int _handle;
	int _engine;
	int _doors;
	int _wheels;

};

//��� 
/*
is - a ���� ����

Animal Ŭ���� , Cat Ŭ����

Cat is Animal - O
Animal is Cat - X

���ʸ� �����ؾ���

�θ��� public , protected �Ӽ��� ����� ��� �����޴´� : �ڵ��� ���뼺

Ŭ������ ���赵 code������ �ְ� �Ҵ��� �ȵ�

*/

//������
/*
1. �����ε� : �Լ����� �Ű������� ������ �ڷ����� �ٸ� �Լ��� �����ϴ� ��
2. �������̵� : �θ��� �Լ��� ���� ������ �ϴ°� �� �Լ� �ñ״��Ŀ� �Լ� �̸��� �����ؾ��Ѵ�
*/
class Animal {

public:
	void Eat() {
		cout << "�ȳ� " << endl;
	}
protected:
public:
	int _mouth;
};

class Cat : public Animal { // public ��� 

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

	Player operator+(const Player& other) { // ������ �����ε�

		//this : �� ����Լ��� ȣ���� ��ü�� ����Ű�� ������
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
	//���м�
	Car myCar;

	// :: �������������� 
	myCar.Car::SetEngine(3);

	cout << myCar.GetEngine() << endl;
	*/
	/*
	//��Ӽ�
	Cat cat;
	cat._mouth = 1;
	cat._legs = 4;
	cat.Eat();
	//cat�� 8����Ʈ 

	*/
	/*
	//������
	Player p1;
	p1._hp = 1;
	Player p2;
	p2._hp = 2;
	
	Player p3 = p1 + p2; // ������ �����ε�

	p3.Creature::Attack(); // ũ������ �����Լ�
	p3.Attack(); // �÷��̾��� �����Լ�
	*/

	cout << Plus(1, 2);
	cout << Plus(1.0f, 3.0f);
	return 0;
}
//ctr + r+ r �ϰ��ٲٱ�

/*
�Լ� �����ε� 
-�Ű������� ������ �Ű������� �ڷ����� �޶� ���� �̸����� �Լ��� ������ ���� �� �� �ִ� ���
��ȯ���� �޶����� �Ű������� ������ �ڷ����� ���ٸ� �����Լ��� �ν��ϹǷ� �����ε� �Ұ���
������Ÿ�ӿ� �Լ��� �����ǰ� �̰��� ���� ���ε� �̶�� �Ѵ�
����) 
int Plus(int a, int b)  {
	return a + b;
}
float Plus(float a, float b) {
	return a + b;
}

�Լ� �������̵�
-�θ� Ŭ�������� ������ �Լ��� �ڽ�Ŭ�������� ������ �ϴ� ���

����: �Լ��� �̸��� ���ƾ��ϰ� �Ű������� ������ �ڷ����� ���ƾ��Ѵ�
����) �θ�Ŭ�������� Attack�̶�� �Լ��� �����Ҷ� �ڽ�Ŭ�������� 2ȸ �����ϰ�ʹٸ� 
�Լ� �������̵��� ����Ͽ� Attack�Լ��� ������ �Ͽ� 2ȸ���� ����

������� �θ�Ŭ������ Attack�Լ��� virtualŰ���带 �ٿ��� virtual void Attack(Creature* other) �� ����

�̶� �޸�4�����߿� data������ virual fuction table�� �����ǰ� ���⼭ virtualŰ���尡 ���� �Լ��� �����͸� �����Ͽ�
�ڽ�Ŭ������ Attack�Լ��� ȣ��Ǹ� �����Լ����̺��� ���� Attack�߿� �ڽ��� Attack�� ȣ��ȴ�

�̷��� �Լ��� ȣ���ϴ� ��ü�� Ȯ���ϰ� �ش� ��ü�� �Լ��� ��Ÿ�ӿ� �ҷ��ͼ� �̰��� �������ε� �̶�� �Ѵ�
*/