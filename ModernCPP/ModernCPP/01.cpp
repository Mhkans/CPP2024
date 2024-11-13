#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
/*
c++ 11 이후 modern cpp 

1. auto 
- 컴파일러가 자동으로 타입 추론 , 선언과 동시에 반드시 초기화가 필요하다
단점: 가독성이 떨어진다.

2. 중괄호 초기화
3. 범위기반 for문
4. final,delete,defualt
5. friend
6. using
7. enum class
8. lambda
9. shift 개념 이동생성자
10. 스마트포인터
11. tuple
*/

struct Vector {

	int x;
	int y;
};
class Pet {

	friend class Warrior; //5. 다른클래스는 접근이 불가능하지만 워리어클래스는 접근가능
private:
	int _hp;
};
class Player {

public:
	Player() = default; //4.기본생성자를 알아서 만들어주세요 , 생성자 소멸자에서만 쓰인다.
	Player(int hp, string name) : _hp(hp), _name(name) {}

	virtual void Attack(){}
protected:
	int _hp;
	string _name;
};
class Knight :public Player {

public:
	Knight(){}
	Knight(int hp, string name) = delete; // 4.타입변환생성자를 막는역할
	virtual void Attack() override final { cout << "Knight" << endl; } //4. final : 자식에서 오버라이딩을 금지한다


private:
};
class Warrior :public Knight {

public:
	//virtual void Attack() override{}
	void SetHP(int hp) {

		_pet._hp = hp;
		_hp = hp;
	}
private:
	Pet _pet;
};
int main() { 
	//1 auto
	unordered_map<string, int> um;
	um["hanil"] = 1;
	um["hanil2"] = 4;
	um["hanil3"] = 10;
	auto insertResult = um.insert(make_pair<string, int>("hanil4", 30));

	auto umIter = um.begin(); // 이터레이터 대신 auto로

	for (umIter; umIter != um.end(); umIter++) {

		cout << "name : " << umIter->first << " value : " << umIter->second << endl;
		if (umIter->first == "hanil") {
			umIter->second = 1234567; // 값이 변경됨
		}
	}

	int arr[3] = { 1,2,3 };
	int aInt = { 1 };
	//2 중괄호 초기화
	Player p = { 10,"hanil" };

	Vector v = { 1,1 };

	//3 범위기반 for문
	
	for (pair<string, int> p : um) {//(pair<const string, int>& p : um)

		cout << "name : " << p.first << " value : " << p.second << endl;
		if (p.first == "hanil") {
			p.second = 7654321; // 값이 변경안됨 -> 참조형으로 하면 변경됨 , key 값은 상수라 const추가
		}
	}
	
	//auto를 추가
	for (auto& p : um) {

		cout << "name : " << p.first << " value : " << p.second << endl;
		if (p.first == "hanil") {
			p.second = 7654321;
		}
	}
	return 0;
}