#include<iostream>

using namespace std;

//포인터

// 간접연산자 
//(자료형) * (변수이름) = (초기화);
// &(변수이름) : 주소연산자 변수의 주소값을 추출한다
// *(변수이름) : 간접연산자 포탈연산자
// 크기 : 32비트(4바이트) 64비트 (8바이트)
// 자료형이 있는이유 : 포탈타고 들어갔을때 어떤 자료형이 있는지 힌트



void AddOne(int num) {
	//main[반환주소값][지역변수:aInt(1)][] 스택프레임 , AddOne[반환주소값][][매개변수: num(1)] 스택프레임

	num++;

	//main[반환주소값][지역변수:aInt(1)][] 스택프레임 , AddOne[반환주소값][][매개변수: num(2)] 스택프레임
	
}
//call by address
void AddOne(int* ptr) {
	//main[반환주소값][지역변수:aInt(1) , aPtr(&aInt) ][] 스택프레임 , AddOne[반환주소값][][매개변수: ptr(&aInt)] 스택프레임

	(*ptr)++; //aInt 의 원본 +1

	//main[반환주소값][지역변수:aInt(2) , aPtr(&aInt) ][] 스택프레임 , AddOne[반환주소값][][매개변수: ptr(&aInt)] 스택프레임
}
//함수끝 소멸
//main[반환주소값][지역변수:aInt(1)][] 스택프레임

int main() {

	int aInt = 1;
	float aFloat = 1.0f;

	int* aPtr;
	aPtr = &aInt; 
	//aPtr = (int*)&aFloat; 0000 0110 int형을 받아서 float형 부동소수점 연산을하기때문에 메모리오염
	//*aPtr = 10;
	
	//main[반환주소값][지역변수:aInt(1)][] 스택프레임 -> main[반환주소값][지역변수:aInt(1) , aPtr(&aInt) ][] 스택프레임
	//AddOne(aInt);
	
	//AddOne(&aInt);
	AddOne(aPtr);
	//main[반환주소값][지역변수:aInt(2)][] 스택프레임 -> main[반환주소값][지역변수:aInt(1) , aPtr(&aInt) ][] 스택프레임

	cout << aInt << endl;
	return 0;
}

