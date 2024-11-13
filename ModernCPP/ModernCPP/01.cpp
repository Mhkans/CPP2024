#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
/*
c++ 11 ���� modern cpp 

1. auto 
- �����Ϸ��� �ڵ����� Ÿ�� �߷� , ����� ���ÿ� �ݵ�� �ʱ�ȭ�� �ʿ��ϴ�
����: �������� ��������.

2. �߰�ȣ �ʱ�ȭ
3. ������� for��
4. final,delete,defualt
5. friend
6. using
7. enum class
8. lambda
9. shift ���� �̵�������
10. ����Ʈ������
11. tuple
*/

struct Vector {

	int x;
	int y;
};
class Pet {

	friend class Warrior; //5. �ٸ�Ŭ������ ������ �Ұ��������� ������Ŭ������ ���ٰ���
private:
	int _hp;
};
class Player {

public:
	Player() = default; //4.�⺻�����ڸ� �˾Ƽ� ������ּ��� , ������ �Ҹ��ڿ����� ���δ�.
	Player(int hp, string name) : _hp(hp), _name(name) {}

	virtual void Attack(){}
protected:
	int _hp;
	string _name;
};
class Knight :public Player {

public:
	Knight(){}
	Knight(int hp, string name) = delete; // 4.Ÿ�Ժ�ȯ�����ڸ� ���¿���
	virtual void Attack() override final { cout << "Knight" << endl; } //4. final : �ڽĿ��� �������̵��� �����Ѵ�


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

	auto umIter = um.begin(); // ���ͷ����� ��� auto��

	for (umIter; umIter != um.end(); umIter++) {

		cout << "name : " << umIter->first << " value : " << umIter->second << endl;
		if (umIter->first == "hanil") {
			umIter->second = 1234567; // ���� �����
		}
	}

	int arr[3] = { 1,2,3 };
	int aInt = { 1 };
	//2 �߰�ȣ �ʱ�ȭ
	Player p = { 10,"hanil" };

	Vector v = { 1,1 };

	//3 ������� for��
	
	for (pair<string, int> p : um) {//(pair<const string, int>& p : um)

		cout << "name : " << p.first << " value : " << p.second << endl;
		if (p.first == "hanil") {
			p.second = 7654321; // ���� ����ȵ� -> ���������� �ϸ� ����� , key ���� ����� const�߰�
		}
	}
	
	//auto�� �߰�
	for (auto& p : um) {

		cout << "name : " << p.first << " value : " << p.second << endl;
		if (p.first == "hanil") {
			p.second = 7654321;
		}
	}
	return 0;
}