#include<iostream>
#include<vector>
#include<list>

using namespace std;

//정적배열
int arr[5] = { 1,2,3,4,5 };

//동적배열
//vector
/*
1. 길이가 동적으로 변할수있다

스택에서 힙을 가리킴
힙에서 4의 용량을 넘어서면 5의 용량을 만들고
기존 내용을 복사해서 옮기는 방식

capacity : 뒤에 얼마나 추가될지 모르니 미리 1.5배 할당

size : 실제 들어가는 사이즈

단점 메모리 파편화,단편화 -> 운영체제에서 관리함

벡터가 리스트보다 삽입삭제가 느린이유
캐패시터와 사이즈가 동일할때 해당 위치를 new delete로 복사하기때문에
*/

#include"vector_Iter.h"

int main() {

	Vector<int> v;
	
	//v.reserve(1000); //capacity를 미리 1000 사이즈는 1부터
	//v.resize(1000,-1); // size까지 미리 1000

	v.reserve(3000);
	for (int i = 0; i < 1000; i++) {

		v.push_back(i);
		cout << "Capacity : " << v.capacity() << endl;
		cout << "size     : " << v.size() << endl;
		cout << endl;
	}

	//v.shrink_to_fit(); //capacity와 size를 맞춰줌


	Vector<int>::Iterator iter = v.begin();
	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}




	return 0;
}
