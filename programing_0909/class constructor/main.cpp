#include<iostream>

using namespace std;

/*
생성자 : 멤버변수를 초기화 하는 역할
객체가 생성되려면 이 생성자를 통해 생성되어야한다.

객체 : 메모리에 클래스로 기능과 속성을 가진 변수를 만들어서 할당하는것

객체화,인스턴스화 : 클래스로 변수를 만들어서 할당(생성자를 통해서) 하는 작업
*/

class Player {

public:
	//기본생성자 : 암묵적으로 정의하지 않아도 컴파일러가 자동으로 만들어준다.
	//만약 다른 생성자가 정의되어있을 시 자동으로 만들어지지 않는다
	Player():_name("") , _hp(0) , _atk(0) , _maxHp(100)//빠른초기화영역 , 상수(const)는 여기서 초기화해야한다
	{

		cout << "기본생성자 호출" << endl;
		//늦은 초기화 영역
		this->_name = " ";
		this->_hp = 0;
		this->_atk = 0;
	}

	//타입변환 생성자 , 매개변수가 있는 생성자
	Player(string name, int hp, int atk) :_name(name),_hp(hp),_atk(atk) , _maxHp(hp){

		cout << "타입변환 생성자 호출" << endl;
	}

	//소멸자
	~Player() {

		cout << "소멸자 호출" << endl;
	}
	void PrintInfo() {

		cout << "name : " << _name << endl;
		cout << "hp : " << _hp << endl;
		cout << "atk : " << _atk << endl;
	}


protected:
	string _name;
	int _hp;
	int _atk;
	const int _maxHp;
};

class Knight : public Player {

public:

	Knight():_stamina(0) // :Player 가 암묵적으로 쓰임
	{

		cout << "Knight 의 기본생성자 호출" << endl;
	}
	Knight(string name, int hp, int atk, int stamina):Player(name,hp,atk),_stamina(stamina) {

		//_name = name; // 부모의 값이라 빠른초기화 대신 늦은초기화로

	}

	~Knight() {

		cout << "Knight의 소멸자 호출" << endl;
	}
private:
	int _stamina;
};

int main() {

	/*
	Player p;
	Player p2 = Player("hanil" , 100 ,5);

	p.PrintInfo();
	p2.PrintInfo();
	*/
	
	Knight knight = Knight("hanil",100,10,10);

	knight.PrintInfo();


	return 0;
}
//상속관계에서 생성자