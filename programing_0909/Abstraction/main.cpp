#include<iostream>

using namespace std;

/*
�������̽�

�����Ϳ� ����(�б� ����)�ϱ� ���� ����

�߻�ȭ

���� �̶�� �߻�ȭ�� ����
���� �̶�� �߻�ȭ�� ����

1. ��üȭ �� �� ���� -> �����̴�
2. ���������Լ��� �ϳ� �̻� ���ԵǸ� �߻�Ŭ������.
3. �߻�Ŭ������ �ڽ��� ��üȭ ��Ű���� ���������Լ��� ������ ����Ѵ�

�߻�Ŭ������ ��������

1.�߻󰳳��̶� ��üȭ ��Ű�� �ȵǴ� Ŭ����
2.�����Լ��� ������ ��������� �ϴ� ��� -> �ڽ�Ŭ�������� ������ �������̵��� �ʿ��� ���
(�ڽ�Ŭ������ ������� ��ü�� ������ �����־�� �ϴ� ������ ���)


*/
class Bank { // �߻�Ŭ����

public:
	virtual void PrintInfo() abstract{ // abstract ���������Լ�
		/*
		cout << _money << endl;
		cout << "�����Դϴ� " << endl;*/
	}
protected:
	int _money;
};
class Kakao:public Bank {

public:
	virtual void PrintInfo() override {// ���������Լ� �������̵� -> �������̽� ����
		//c++ ���� : protected ��������� �����Ҽ��ִ� ������ �����϶�

		cout << "īī�� ��ũ �Դϴ� " << endl; 
		cout << "�����Ͻ� �ݾ��� :" << _money << endl;

	}

};
class ShinHan :public Bank {

public:
	virtual void PrintInfo() override {
		

		cout << "�������� �Դϴ� " << endl;
		cout << "�����Ͻ� �ݾ��� :" << _money << endl;

	}

};


int main() {


	//Bank* b = new Bank(); �߻�ȭ�� ������ �����Ҵ����� �Ǹ� �ȵ�
	Bank* k = new Kakao();
	k->PrintInfo();


	return 0;
}