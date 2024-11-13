#include<iostream>

using namespace std;


struct Player {

	int _hp;
	int atk;
	string name;

};

void PirntPlayer(const Player* const p) { //������ ������ ���� �����͸� Ÿ����� �����ϴ°͵� ���´�

	cout << "Name : " << (*p).name << endl;
	cout << "HP : " << (*p)._hp << endl;
	cout << "ATK : " << (*p).atk << endl;

}
//call by value
void SetPlayer(Player p , string name , int hp , int atk) { //p�� 8����Ʈ

	p.name = name;
	p._hp = hp;
	p.atk = atk;
}
//call by address
void SetPlayer(Player* p , string name , int hp , int atk) { //p�� 4����Ʈ

	(*p).name = name;
	(*p)._hp = hp;
	(*p).atk = atk;
}

void AlterPlayerByInt(Player* p) {

	int* ptr = (int*)p;
	*(ptr+1) = 1; //ptr +���� : ptr�� �ڷ��� ũ�⸸ŭ ���Ѵ�.

}

int main() {

	Player p;
	p._hp = 100;
	p.atk = 10;
	p.name = "Hanil";

	SetPlayer(&p, "Han", 150, 15);

	//AlterPlayerByInt(&p);

	PirntPlayer(&p);

	return 0;
}
