#include<iostream>
#include<vector>
#include<list>
using namespace std;

//iterator : �ݺ��� (��ȸ��)
int main() {

	vector<int> v = { 1,2,3,4,5,6 };
	//vector�� �������ٿ����ڷ� ��ȸ�� ���������� list�� ��ȸ�Ұ��� -> �����̳ʿ��� ���ͷ����� ���

	vector<int>::iterator Iter;
	Iter = v.begin();
	for (Iter; Iter != v.end(); Iter++) {

		cout << *Iter << endl;
	}
	cout << " - - - - - - - - - - -" << endl;
	list<int> myList = { 5,6,7,8,9 };
	list<int>::iterator myListIter = myList.begin();

	for (myListIter; myListIter != myList.end(); myListIter++) {

		cout << *myListIter << endl;
	}
	return 0;
}