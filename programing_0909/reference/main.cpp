#include<iostream>

using namespace std;

/*
����� ������ ����� ���ÿ� �ʱ�ȭ�� �ʿ���

(�ڷ���) & (�����̸�) = (�ʱ�ȭ); 

c++ ���� : ���� ��Ī

������� ���� : �����Ϳ� �����ϰ� ���� ,������ ���� ������ �����ϴ�


������

���� �б� ������ �����ϴ�

������

1. �ʱ�ȭ����
ref : �ݵ�� �ʱ�ȭ �ؾ��ϰ� ������ ������� �ƹ��͵��ƴ�
ptr : nullptr�� ����Ű�°����� ���ٴ� ǥ�ø� �� �� �ִ�

2. ������ ����� ����� �� ����,

3. �����ް� ���°� �����ؼ� �����ε��Ҷ� ������ ����� null������ ��������ʴ´�

* : ����������
-> : �������������
. : ���������

call by value : ���� ���� x , �б� o , �Ű������� ũ��� �ڷ����� ������
call by Adrress : ���� ���� o , �б� o , �Ű������� ũ��� �ּҰ��� ũ�⸦ ������ 32 - 4 ,64 -8
call by reference : ���� ���� o , �б� o , �Ű������� ũ��� �ּҰ��� ũ�⸦ ������ 32 - 4 ,64 -8

*/

void AddOne(int& ref) {

	ref++;

}
struct Player
{

	int _hp;
	int atk;
	string name;


};


//���̾��� �б� ���� ���� : const reference
void PrintPlayer(const Player& ref) {

	cout << ref.name << endl;
	cout << ref._hp << endl;
	cout << ref.atk << endl;

}

void SetPlayer(Player& ref, string name, int hp, int atk) {

	ref.name = name;
	ref._hp = hp;
	ref.atk = atk;


}
void SetPlayer(Player* p, string name, int hp, int atk) { 

	(*p).name = name;
	p->_hp = hp;
	p->atk = atk;
}

int main() {

	/*
	int aInt = 1;
	int& aRef = aInt; // aInt�� ���� aRef

	int* aPtr = &aInt;

	aRef++;

	cout << aInt << endl;

	(*aPtr)++;

	cout << aInt << endl;

	AddOne(aInt);

	cout << aInt << endl;

	*/

	Player p;

	p.name = "";
	p._hp = 0;
	p.atk = 0;

	PrintPlayer(p);

	SetPlayer(p , "hanil" , 100 ,5);

	PrintPlayer(p);

	Player p2;

	p.name = "";
	p._hp = 0;
	p.atk = 0;

	SetPlayer(p2, "mmmm", 50, 3);



	return 0;


}

// ����  1
// �÷��̾� �θ��� �����ϰ� ���� ���������� �ο��� �ݺ��ؼ� �̱� �÷��̾� ���
