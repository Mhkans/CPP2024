#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
/*
8. lambda
9. shift 개념 이동생성자
10. 스마트포인터
11. tuple
*/

int main() {

	//vector<int> v = { 4,5,2,1,12,313,22,50 };


	////150보다 큰수를 찾고싶다

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

	////8 람다 함수 -> 무명함수 재사용이안됨
	///*
	//[캡쳐](매개변수) ->반환식 {함수식}
	//-캡쳐부분에 원본을 전달할수있다. ref로
	//-캡쳐부분에 위에있는 지역변수를 모두 전달할수있다. = 로
	//*/
	//int compareNum = 150;
	//int temp = 1;
	//auto iter = std::find_if(v.begin(), v.end(), [&compareNum, temp](const int& num)->bool { // = 를사용하면 지역의 모든 변수
	//	if (num > compareNum) {
	//		//compareNum = 33; 
	//		return true;
	//	}
	//	return false;
	//});

	//cout << *iter << endl;

	////v 를 10이상의 수는 정렬하지말고 이외의 수는 오름차순

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