#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
/*
8. lambda
9. shift ���� �̵�������
10. ����Ʈ������
11. tuple
*/

int main() {

	//vector<int> v = { 4,5,2,1,12,313,22,50 };


	////150���� ū���� ã��ʹ�

	//struct Functor {

	//	bool operator()(const int& num) {

	//		if (num > Cnum) {

	//			return true;
	//		}
	//		return false;
	//	}
	//	int Cnum;
	//};

	////Functor f;
	////f.Cnum = 150;
	////auto iter = std::find_if(v.begin(), v.end(), f);

	////8 ���� �Լ� -> �����Լ� �����̾ȵ�
	///*
	//[ĸ��](�Ű�����) ->��ȯ�� {�Լ���}
	//-ĸ�ĺκп� ������ �����Ҽ��ִ�. ref��
	//-ĸ�ĺκп� �����ִ� ���������� ��� �����Ҽ��ִ�. = ��
	//*/
	//int compareNum = 150;
	//int temp = 1;
	//auto iter = std::find_if(v.begin(), v.end(), [&compareNum, temp](const int& num)->bool { // = ������ϸ� ������ ��� ����
	//	if (num > compareNum) {
	//		//compareNum = 33; 
	//		return true;
	//	}
	//	return false;
	//});

	//cout << *iter << endl;

	////v �� 10�̻��� ���� ������������ �̿��� ���� ��������

	//vector<int> v = { 4,5,2,1,12,313,22,50 };

	//std::sort(v.begin(), v.end(), [](const int& a, const int& b)->bool {

	//	if (a < b) { 
	//		return true;
	//	}
	//	else {
	//		return false;
	//	}

	//});
	class Pet {
	public:
		int _atk = 0;

	};
	class Player {

	public:
		int _atk = 0;
		Pet* _pet = 0;
	};
	vector<Player*> players;
	for (int i = 0; i < 10; i++) {
		Player* p = new Player();
		p->_pet = new Pet();
		p->_pet->_atk = rand() % 50;
		players.push_back(p);
	}
	std::sort(players.begin(), players.end(), [](const Player* p1 , const Player* p2) {

		return p1->_pet->_atk > p2->_pet->_atk;
	});

	return 0;
}