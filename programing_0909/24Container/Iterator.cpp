#include<iostream>
#include<vector>
#include<list>
using namespace std;

//iterator : 반복자 (순회자)
int main() {

	vector<int> v = { 1,2,3,4,5,6 };
	//vector는 임의접근연산자로 순회가 가능하지만 list는 순회불가능 -> 컨테이너에선 이터레이터 사용

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