#include<iostream>

using namespace std;

/*
������ : ��������� �ʱ�ȭ �ϴ� ����
��ü�� �����Ƿ��� �� �����ڸ� ���� �����Ǿ���Ѵ�.

��ü : �Ӽ��� ����� ���� �޸𸮿� �Ҵ�Ǿ� �ִ� ������

��üȭ,�ν��Ͻ�ȭ : Ŭ������ ������ ���� �޸𸮿� �Ҵ�(�����ڸ� ���ؼ�) �ϴ� �۾�
*/

class Player {

public:
	//�⺻������ : �Ϲ������� �������� �ʾƵ� �����Ϸ��� �ڵ����� ������ش�.
	//���� �ٸ� �����ڰ� ���ǵǾ����� �� �ڵ����� ��������� �ʴ´�
	Player():_name("") , _hp(0) , _atk(0) , _maxHp(100)//�����ʱ�ȭ���� Initialize List , ���(const)�� ���⼭ �ʱ�ȭ�ؾ��Ѵ�
	{

		cout << "�⺻������ ȣ��" << endl;
		//���� �ʱ�ȭ ���� , ���Կ����� ���
		this->_name = " ";
		this->_hp = 0;
		this->_atk = 0;
	}

	//Ÿ�Ժ�ȯ ������ , �Ű������� �ִ� ������ 
	Player(string name, int hp, int atk) :_name(name),_hp(hp),_atk(atk) , _maxHp(hp){ 

		cout << "Ÿ�Ժ�ȯ ������ ȣ��" << endl;
	}
	//��������� -  Player p2 = p; ,player p2(p); ,�������� �ʾƵ� ������ش�
	Player(const Player& other) :_name(other._name), _hp(other._hp), _atk(other._atk), _maxHp(other._maxHp) {
		_hp = other._hp;
		_atk = other._atk; 
		//��������
	}
	//�Ҹ��� - �����Ҵ� ���� , �Ҹ� ó��
	~Player() {

		cout << "�Ҹ��� ȣ��" << endl;
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

	Knight():_stamina(0) // :Player �� �Ϲ������� ����
	{

		cout << "Knight �� �⺻������ ȣ��" << endl;
	}
	Knight(string name, int hp, int atk, int stamina):Player(name,hp,atk),_stamina(stamina) {

		//_name = name; // �θ��� ���̶� �����ʱ�ȭ ��� �����ʱ�ȭ��

	}

	~Knight() {

		cout << "Knight�� �Ҹ��� ȣ��" << endl;
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
//��Ӱ��迡�� ������