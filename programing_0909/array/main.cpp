#include<iostream>

using namespace std;

/*
자료구조 (데이터가 어떤형식으로 이루어져 있는지)
정적 배열
1. 데이터가 연속되어 배치되어 있는 구조
2. 같은 자료형끼리 

선언 방법
(자료형) 배열이름 [배열개수] = {초기화};   
[] : 임의 접근 연산자
탐색시간 : n , 접근시간 : 1

포인터의 연산자
(자료형)* 변수이름;  //포인터 선언
(변수) * (변수) // 곱셈연산
*(변수) // 간접연산자
(자료형)& 변수이름 // 참조(레퍼런스) 선언
&(변수이름) // 주소연산자
(변수이름) && (변수이름) //and연산
(변수이름) & (변수이름) //비트and연산

int* ptr = 0x00;
ptr = (ptr +1) -> 0x04 덧셈연산할때 자료형의 크기에 근거해서 덧셈한다

배열을 매개변수로 전달하는 것은 포인터를 전달하는 것과 동일하다
배열의 이름은 배열의 첫번재 원소의 주소값을 갖고있는 포인터와 동일하게 작동한다
정적배열은 매개변수로 넘길때 size도 같이넘겨줘야한다
*/
struct Player {

	int itemCode[100];


};


void PrintArray(int* ptr , int size) { // int arr[] , int size

	for (int i = 0; i < 5; i++) {

		cout << arr[i] << endl;
		//cout << *( ptr + i ) << endl;
	}
}
int arr[5] = { 1,2,3,4,5 };

int main() {

	int* ptr = &arr[0];

	cout << *(ptr + 1) << endl;

	PrintArray(arr,sizeof(arr)/sizeof(int));

	return 0;
}