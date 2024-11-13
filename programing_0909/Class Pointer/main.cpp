#include<iostream>

using namespace std;
//�Լ� �������̵� : �θ��� �Լ��� �ڽĿ��� ������
//��ĳ���� �Ҷ� ����� ����
//�ڽ��� �Լ��� ��� ȣ���� ���ΰ� -> ����ȯ or �����Լ�

//�����Լ� ���̺�(vftable) ptr : Ŭ������ �����Լ��� �ϳ� �̻� ���ԵǸ� �ڵ����� �޸� ù��° �ּҿ� �Ҵ�Ǵ� ������
//�̸� �̿��ؼ� ��ĳ���õ� ��Ȳ������ �ڽ��� �Լ��� ȣ�� �� ���ִ�.

class Player {

public:
	virtual void Attack() {
		cout << "Player Attack" << endl;
	}
	int _hp = 1;
};

class Knight : public Player {

public:
	//�����Լ� �������̵� : �θ��� �Լ��� ������
	//����� ��� ���̺� : �ڵ念���� �Լ��κ��� ����Ű�� �����͸� �������
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
	* //��ĳ���� : �ѹ��� ��������ϱ� ����
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