#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<unordered_map>

using namespace std;

struct User {


	int userID;
	int userData;

};
struct UserInfo {

	int UserID;
	User* user;
};



int main() {

	vector<User> users;
	users.reserve(1000);

	for (int i = 0; i < 1000; i++) {

		users.push_back({ i,i % 100 });
	}

	vector<UserInfo> userInfoDatas;
	userInfoDatas.reserve(1000);

	for (int i = 0; i < users.size(); i++) {

		userInfoDatas.push_back({users[i].userID,&users[i]});
	}

	//userid가 555인 애를 찾아라
	for (int i = 0; i < userInfoDatas.size(); i++) {

		if (userInfoDatas[i].UserID == 555) {

			break;
		}
	}
	//해쉬테이블 unorderedMap
	//int같은 기본자료형은 기본해쉬함수를 통과 하지만 USer같은 템플릿은 어떻게 계산할지 몰라서 통과 x

	unordered_map<int, User*> myUm; 

	myUm[0] = &users[0]; //key : 0 , Value : 0x... -> &users[0]

	pair<int, User*> p = { 2,&users[2] };
	pair<unordered_map<int, User*>::iterator, bool> inserpair = myUm.insert(p); //중복체크

	if (myUm.count(0) == 0) { //키가 0인애가없다

		myUm[0] = &users[1];

	}
	for (int i = 0; i < users.size(); i++) {

		myUm[i] = &users[i];
	}

	//탐색

	myUm[555];

	//트리 맵 - 쓰는방법은 같은데 내부구조는 다름 
	map<int, User*> myM;

	for (int i = 0; i < users.size(); i++) {

		myM[i] = &users[i];
	}

	/*
	for (int i = 0; i < myM.size(); i++) {

		cout << myM[i]->userID << endl;
		cout << myM[i]->userData << endl;
	}*/

	map<int, User*>::const_iterator myMiter = myM.begin();

	for (myMiter; myMiter != myM.end(); myMiter++) { //이터레이터를 타고들어가면 pair

		cout << (*myMiter).second->userID << endl;
		cout << (*myMiter).second->userData << endl;

	}









	return 0;
}