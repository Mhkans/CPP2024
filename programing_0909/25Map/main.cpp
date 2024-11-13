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

	//userid�� 555�� �ָ� ã�ƶ�
	for (int i = 0; i < userInfoDatas.size(); i++) {

		if (userInfoDatas[i].UserID == 555) {

			break;
		}
	}
	//�ؽ����̺� unorderedMap
	//int���� �⺻�ڷ����� �⺻�ؽ��Լ��� ��� ������ USer���� ���ø��� ��� ������� ���� ��� x

	unordered_map<int, User*> myUm; 

	myUm[0] = &users[0]; //key : 0 , Value : 0x... -> &users[0]

	pair<int, User*> p = { 2,&users[2] };
	pair<unordered_map<int, User*>::iterator, bool> inserpair = myUm.insert(p); //�ߺ�üũ

	if (myUm.count(0) == 0) { //Ű�� 0�ξְ�����

		myUm[0] = &users[1];

	}
	for (int i = 0; i < users.size(); i++) {

		myUm[i] = &users[i];
	}

	//Ž��

	myUm[555];

	//Ʈ�� �� - ���¹���� ������ ���α����� �ٸ� 
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

	for (myMiter; myMiter != myM.end(); myMiter++) { //���ͷ����͸� Ÿ����� pair

		cout << (*myMiter).second->userID << endl;
		cout << (*myMiter).second->userData << endl;

	}









	return 0;
}