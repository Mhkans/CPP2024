#include<iostream>

using namespace std;
/*
전역변수 : global valueable
모든 지역에서 접근 할 수 있다.

*/

int aInt = 1; //a와c가 붙어있고 data영역은 미리 다 0으로 초기화 되어있음
int cInt = 2;

int main() {


	//지역변수 
	//스택 영역 변수들의 생성주기 :함수가 호출되면 생성된다 , 함수가 종료되면 소멸한다
	//스택은 컴파일 과정에서 할당됨

	int bInt = 2; //b와d가 약간떨어져있고 스택영역의 데이터는 초기화 하지 않았으므로 쓰레기값으로 밀려있다,
	int dInt = 3;
	{// 지역

		int kInt = 123;
	}
	//cout << kInt << endl; 지역변수는 지역을 벗어나면 사용할수없다 
	return 0;
}