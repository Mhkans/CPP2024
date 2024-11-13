#include<iostream>

using namespace std;

int aInt = 1;

float aFloat = 1.5f;

short aShort = 123;
//형변환

//안전한 형변환

//불안전한 형변환
/*
실수 -> 정수
데이터가 큰 -> 데이터가 작은(기본자료형에 한해서)
*/

/*
static_cast
dynamic_cast
const_cast
reinterpret_cast
*/
class Player {

public:

	Player():_type(0){}
	virtual ~Player() {}
	virtual void VirtualF(){}
	int _hp;
	int _type;
};

class Knight : public Player {

public:
	Knight(){_type = 1; }
	virtual void VirtualF() override {}
	int _stamina;
};
class Archer : public Player {

public:
	Archer() { _type = 1; }
	virtual void VirtualF() override {}
	
};
class Pet {


};

void PrintType(Player* p) {

	int type = p->_type;

	switch (type) {

	case 1:{
		Knight* k = dynamic_cast<Knight*>(p);
		if (k != nullptr) {

			cout << "Knight" << endl;
		}
	}
	case 2:{
		Archer* a = dynamic_cast<Archer*>(p);
		if (a != nullptr) {

			cout << "Archer" << endl;
		}
	}
	default: {
		break;
	}

	}
}



int main() {

	int aInt = 1;
	float aFloat = static_cast<int>(aInt); 
	// static - 논리적으로 수행가능한 형변환이면 ok

	Player* p = static_cast<Player*>(new Knight());

	//p = static_cast<Player*>(new Pet()); //안됨

	// dynamic - 상속구조 , vft able을 갖고있어야 사용 가능하다. 
	// 런타임에 검사(타입추론 vftable -> runtime type information rtti)하므로 컴파일러오류가 안난다 실패하면 nullptr 반환

	PrintType(p);

	/*
	data 영역
	- data : 초기화된 전역변수
	- bss : 초기화되지않은 전역변수
	- rodata : 상수
	*/

	const char* str = "hanil"; //rvalue 리터럴상수 -> rodata 포인터임 32비트환경에서 rodata에 4바이트
	char str2[7] = "hanil2"; // L : 스택에 7바이트 
	
	char* temp = const_cast<char*>(str);

	//*temp = 't'; 엑세스 위반 

	




	return 0;
}
/*


	aFloat = aInt; //안전
	aInt = aFloat; //불안전 aInt 1 이 되어서 뒤에 0.5f가 날아가게된다 

	aInt = 32768;
	aShort = aInt;

	Player p{ 1 };
	Knight k;
	k._hp = 2;
	k._stamina = 3;

	p = k;

	Player* p2 = new Knight();
	Knight* k2 = (Knight*)(new Player());//다운캐스팅

	k2->_hp = 123;
	k2->_stamina = 12;//메모리 오염 위험


	cout << k2->_hp << endl;
	cout << k2->_stamina << endl;

	*/