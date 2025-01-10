#include <iostream>

using namespace std;

class Pet
{
public:

private:
	int _hp;
	//
};

class Player
{
public:
	Player()
		: _pet(new Pet())
	{
		cout << "Player ������" << endl;
	}

	~Player()
	{
		cout << "Player�� �Ҹ���" << endl;

		if (_pet == nullptr) return;

		delete _pet;
	}

	// ���� ���� => ���� ����
	// ���� ���� : �����Ҵ�Ǿ��ִ� ��������� �����ؼ� ���ο� ��ü�� ����� �۾�
	Player(const Player& p)
		: _pet(new Pet(*p._pet))
	{
		cout << "���� ���� ������ ȣ��" << endl;
	}

	Player& operator=(const Player& other)
	{
		cout << "���� ������ ȣ��" << endl;
		_pet = new Pet(*other._pet);

		return *this;
	}

private:
	// ���ο��� �����Ҵ�
	Pet* _pet;
};

int main()
{
	Player p;
	Player p2 = p;
	Player p3;
	p3 = p2;
	// ���������
	// ������ ��(���������)�� �ѹ� �� ��������Ѵ�.


	return 0;
}