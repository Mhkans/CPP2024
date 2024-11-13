#include<iostream>

using namespace std;

int Add(int a, int b); // 선언과 정의를 따로가능 함수시그니쳐
float Add(float a, float b);
int Add(int a, int b, int c);
int Add(int a, int b, int c, int d, int e = 1);

int Factorial(int n) {

	if (n == 1) {
		return 1;
	}
	return n * Factorial(n - 1);
}
int main() {

	//Add[반환주소값 ,지역변수 c , 매개변수 a ,b] 
	//main[반환주소값 , aInt , ]
	int aInt = Add(5, 3);
	float aFloat = Add(1.1f, 2.1f);
	int aInt3 = Add(1,2,3);
	int aInt4 = Add(1,2,3,4);
	int factorial = Factorial(5);

	cout << aInt << endl;
	cout << aFloat << endl;
	cout << aInt3 << endl;
	cout << aInt4 << endl;
	cout << factorial << endl;


	return 0;
}

int Add(int a, int b) {

	int c = a + b;

	return c;
}

int Add(int a, int b , int c) {

	int d = a + b + c;

	return d;
}

float Add(float a, float b) {

	float c = a + b;

	return c;
}
int Add(int a, int b, int c , int d , int e ) { // 함수의 기본인자 맨뒤부터 기본인자로 설정할 수 있다.

	int f = Add(a, b, c) + Add(d, e);

	return f;
}


/*

과제 : 아홉고개 만들기

1. 컴퓨터가 1부터 500 까지의 랜덤한 숫자를 갖는다 . 
2. 플레이어가 숫자를 입력한다
3. 컴퓨터가 숫자가 큰지 작은지 up down 으로 대답 컴 400 나 200 up
4. 아홉번만에 맞춘것을 캡쳐해서 같이 올리기


메모리 4영역

code 
data : 전역변수 정적변수
stack : 반환주소값 , 지역변수 , 매개변수 셋을 스택프레임
heap 

반환형식 , 매개변수의 자료형 , 개수 , 함수이름 => 함수 시그니쳐

함수오버로딩 : 함수의 이름을 같게하고 매개변수의 자료형이나 매개변수의 개수가 달라도 사용가능

난수생성
1.시드 srand(time(NULL))
2.난수생성

입력
int Num;
cin >> Num;

*/