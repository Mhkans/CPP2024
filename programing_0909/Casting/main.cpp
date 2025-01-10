#include<iostream>

using namespace std;

// DATA
// - bss���� : �ʱ�ȭ�������� ��������
// - data���� : �ʱ�ȭ�� ��������
// - rodata���� : ���(���ͷ� ���... ���)

int aInt = 1;

float aFloat = 1.5f;

short aShort = 123;
//����ȯ

//������ ����ȯ : int���� float����

//�Ҿ����� ����ȯ : float���� int�� , �����Ͱ� ū -> �����Ͱ� ����(�⺻�ڷ����� ���ؼ�)

//��ĳ���� : �ڽ� Ŭ������ ������ ��ü�� �θ� Ŭ���� �����ͷ� ����Ű�� ��
// -> ������ ĳ����
//�ٿ�ĳ���� : �θ� Ŭ������ ������ ��ü�� �ڽ� Ŭ���� �����ͷ� ����Ű�� ��
// -> �Ҿ����� ĳ����

/*
1. static_cast : �������ε� ������Ÿ�ӿ� �������� , �������� �����ϸ� ������ ���
2. dynamic_cast : ��� ���������� (�����Լ� ���̺��� �����ϴ� ���) ��밡�� ,�����ϸ� ĳ���� ���� �����ϸ� nullptr��ȯ
��Ÿ�ӿ� �������ι�ȯ
3. const_cast
4. reinterpret_cast : ������ ����ȯ , ��Ŷ �����͸� �������� (��Ʈ �״�� ex 0000 0100) ��Ŷ���̵� Ȯ���ϰ� �ڷ����� ����
*/
struct Packet
{
	int packetId; // ����ڳ��� ���ϴ°�
	int aInt; // 32��Ʈ (0100)
};

class Player
{
public:
	virtual void Attack() { cout << "Player Attack!" << endl; }

	int type = 0;
};

class Knight : public Player
{
public:
	Knight() { type = 1; }

	virtual void Attack() override { cout << "Knight Attack!" << endl; }
};

class Archer : public Player
{
public:
	Archer() { type = 2; }

	virtual void Attack() override { cout << "Archer Attack!" << endl; }
};


template<typename T>

T MyDynamic(T player) { //���������ϸ� �����Լ����̺� ���� �����ϱ��ϴ�
	if (player->type == 1) {

		return reinterpret_cast<T>(player)l
			
	}
	else {
		return nullptr;
	}

}

int main()
{
	int aInt = 1;
	float aFloat = aInt;
	aFloat = 1.523f;
	aInt = aFloat;

	Knight* k = new Knight();
	Player* p = k; // ��ĳ����

	Player* temp = new Player();
	Knight* temp2 = (Knight*)temp; // �ٿ�ĳ����

	// ĳ���� 4�ѻ�
	// static_cast
	aFloat = static_cast<float>(aInt);
	Player* p1 = static_cast<Player*>(new Knight()); // ��ĳ����

	// dynamic_cast
	Player* p2 = new Knight();

	// ... ���� �ϵ��� �־���.

	Knight* p3 = dynamic_cast<Knight*>(p2); // RTTI ������ ����Ѵ�.
	if (p3 == nullptr)
	{
		cout << "p2�� Knight�� �ƴϿ����ϴ�." << endl;
	}
	else
	{
		cout << "p2�� Knight�����ϴ�." << endl;
	}

	// const_cast
	const char* str1 = "hello world!";
	char str2[13] = "hello world!";

	char* str3 = const_cast<char*>(str1);
	//str3[0] = 't';

	// reinterpret_cast
	// �������� �ַ� ���δ�.
	aFloat = 1.234f;
	int* aPtr = reinterpret_cast<int*>(&aFloat);

	switch (p2->type)
	{
	case 1:
	{
		p3 = reinterpret_cast<Knight*>(p2);
		break;
	}
	case 2:
	{
		p3 = nullptr;
	}

	default:
		break;
	}


	delete p2;
	delete temp;
	delete k;

	return 0;
}
