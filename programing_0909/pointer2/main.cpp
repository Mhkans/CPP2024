#include<iostream>

using namespace std;


struct Player {

	int _hp;
	int atk;
	string name;

};

void PirntPlayer(const Player* const p) { //포인터 수정도 막고 포인터를 타고들어가서 수정하는것도 막는다

	cout << "Name : " << (*p).name << endl;
	cout << "HP : " << (*p)._hp << endl;
	cout << "ATK : " << (*p).atk << endl;

}
//call by value
void SetPlayer(Player p , string name , int hp , int atk) { //p는 8바이트

	p.name = name;
	p._hp = hp;
	p.atk = atk;
}
//call by address
void SetPlayer(Player* p , string name , int hp , int atk) { //p는 4바이트

	(*p).name = name;
	(*p)._hp = hp;
	(*p).atk = atk;
}

void AlterPlayerByInt(Player* p) {

	int* ptr = (int*)p;
	*(ptr+1) = 1; //ptr +정수 : ptr의 자료형 크기만큼 더한다.

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
