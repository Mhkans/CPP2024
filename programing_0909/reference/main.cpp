#include<iostream>

using namespace std;

/*
상수와 참조는 선언과 동시에 초기화가 필요함

(자료형) & (변수이름) = (초기화); 

c++ 관점 : 별명 별칭

어셈블리어 관점 : 포인터와 동일하게 동작 ,원본에 접근 수정이 가능하다


공통점

원본 읽기 수정이 가능하다

차이점

1. 초기화여부
ref : 반드시 초기화 해야하고 변수가 사라지면 아무것도아님
ptr : nullptr을 가리키는것으로 없다는 표시를 할 수 있다

2. 참조는 대상이 변경될 수 없다,

3. 값전달과 형태가 동일해서 오버로딩할때 문제점 생긴다 null참조를 허용하지않는다

* : 간접연산자
-> : 간접멤버연산자
. : 멤버연산자

call by value : 원본 수정 x , 읽기 o , 매개변수의 크기는 자료형을 따른다
call by Adrress : 원본 수정 o , 읽기 o , 매개변수의 크기는 주소값의 크기를 따른다 32 - 4 ,64 -8
call by reference : 원본 수정 o , 읽기 o , 매개변수의 크기는 주소값의 크기를 따른다 32 - 4 ,64 -8

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


//많이쓰는 읽기 전용 구문 : const reference
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
	int& aRef = aInt; // aInt의 별명 aRef

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

// 과제  1
// 플레이어 두명을 세팅하고 서로 죽을때까지 싸움을 반복해서 이긴 플레이어 출력
