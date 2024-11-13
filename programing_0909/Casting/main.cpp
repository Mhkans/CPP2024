#include<iostream>

using namespace std;

int aInt = 1;

float aFloat = 1.5f;

short aShort = 123;
//����ȯ

//������ ����ȯ

//�Ҿ����� ����ȯ
/*
�Ǽ� -> ����
�����Ͱ� ū -> �����Ͱ� ����(�⺻�ڷ����� ���ؼ�)
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
	// static - �������� ���డ���� ����ȯ�̸� ok

	Player* p = static_cast<Player*>(new Knight());

	//p = static_cast<Player*>(new Pet()); //�ȵ�

	// dynamic - ��ӱ��� , vft able�� �����־�� ��� �����ϴ�. 
	// ��Ÿ�ӿ� �˻�(Ÿ���߷� vftable -> runtime type information rtti)�ϹǷ� �����Ϸ������� �ȳ��� �����ϸ� nullptr ��ȯ

	PrintType(p);

	/*
	data ����
	- data : �ʱ�ȭ�� ��������
	- bss : �ʱ�ȭ�������� ��������
	- rodata : ���
	*/

	const char* str = "hanil"; //rvalue ���ͷ���� -> rodata �������� 32��Ʈȯ�濡�� rodata�� 4����Ʈ
	char str2[7] = "hanil2"; // L : ���ÿ� 7����Ʈ 
	
	char* temp = const_cast<char*>(str);

	//*temp = 't'; ������ ���� 

	




	return 0;
}
/*


	aFloat = aInt; //����
	aInt = aFloat; //�Ҿ��� aInt 1 �� �Ǿ �ڿ� 0.5f�� ���ư��Եȴ� 

	aInt = 32768;
	aShort = aInt;

	Player p{ 1 };
	Knight k;
	k._hp = 2;
	k._stamina = 3;

	p = k;

	Player* p2 = new Knight();
	Knight* k2 = (Knight*)(new Player());//�ٿ�ĳ����

	k2->_hp = 123;
	k2->_stamina = 12;//�޸� ���� ����


	cout << k2->_hp << endl;
	cout << k2->_stamina << endl;

	*/