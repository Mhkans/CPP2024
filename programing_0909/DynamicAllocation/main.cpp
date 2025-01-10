#include<iostream>

using namespace std;

/*
code

data - �������� ��������

�����ֱ� : ���α׷� ����ɶ� �Ҵ� -> ���α׷� ����� ����
���� : ��� ������ ������ �����ϴ�.
���� : ���α׷� ����Ǳ� ������ ������ �Ұ���, �����Ϳ����� ũ�Ⱑ �۴�

stack - �������� , ��ȯ�ּҰ� , �Ű����� -> ����������

�����ֱ� : �Լ� ȣ�� �� ���� -> �Լ� ����� �Ҹ�
���� , ���� : �Լ� ������ ���� �� ���� , �޸𸮿��� 

heap - ���α׷����� ���� ����ڰ� ���� �����ϴ� �޸�

�����ֱ� : ���α׷��Ӱ� ���� ���� ,�Ҹ��� �������

�����Ҵ� -> heap������ �޸𸮸� �Ҵ��ϴ� �۾� , �ü���� �����ִ� �۾�(Ŀ�ο���)
���� �Ҹ� ������ ���Ҽ������� �Ҵ��� �ü����



*/

class Player {

public:
	Player(){}
	Player(int hp, int atk) : _hp(hp), _atk(atk) {


	}

	int _hp;
	int _atk;
};




int main() {

	//c��Ÿ�� �����Ҵ� : malloc , free
	/*
	void* ptr = malloc(100); //heap �� 100����Ʈ �Ҵ�ް� ��ġ�� ����Ű�� ������ ��ȯ
	int* intPtr = (int*)ptr;

	for (int i = 0; i < 25; i++) {

		*(intPtr + i) = i + 1;

	}

	free(ptr);
	*/
	//c++ ��Ÿ�� �����Ҵ� : new delete , new[] delete[]

	int* intPtr = new int(); //4����Ʈ �Ҵ�
	int* intPtr2 = new int[25]; // 100����Ʈ �Ҵ�
	Player* pPtr = new Player(10, 2);
	char* charPtr = new char[100]; //100����Ʈ �Ҵ�
	Player* pArr = new Player[100]; // �⺻������ ���Ǹ� �ؾ���
	Player* pPtrArr[100] = { nullptr };

	for (int i = 0; i < 100; i++) { //�� 400����Ʈ(����) -> 800����Ʈ(��)

		pPtrArr[i] = new Player();
	}




	delete[] pArr;
	delete pPtr;
	delete[] charPtr;
	delete[] intPtr2;
	delete intPtr;
	
	
	


	return 0;

}