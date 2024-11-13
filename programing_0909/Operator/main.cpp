#include<iostream>

using namespace std;

/*
operator : 연산자

aInt + bInt = a와 b를 더하고 임시값을 반환한다 정수
aFloat + bFloat = a와 b를 더하고 임시값을 반환한다 실수
aInt / bInt = 정수 나눗셈 정수몫이 나옴
aFloat / bFloat = 실수 나눗셈 실수몫이 나옴
실수끼리 나머지 연산 안됨

대입연산자 
=
a = b : a에 b를 대입하고 a의 원본을 반환한다.

단항연산자

++aInt : 전위연산자 aInt 원본에 1을 더하고 aInt원본을 반환한다
aInt++ : 후위연산자 aInt 의 값을 복사한 임시값을 만들고 aInt에 1을 더한 후 임시값을 반환한다.

비교연산자
> < == !=
반환값이 bool

aInt = 3  bInt = 5

aInt > bInt : false
aInt == bInt : false 
aInt!=bInt : true

논리연산자
! && ||

! : true 였으면 false false였으면true
&& : and 둘다 true 이면 true 둘중에 하나라도 false 면 false
|| : or 둘중에 하나라도 true면 true 둘다 false 면 false

비트연산자
<< , >> , & , | , ^

<< : 왼쪽 shift연산 , 곱하기 2 처럼 움직임 나머지 비트는 0으로채워진다. 보통 unsigned 형식을 많이쓴다
>> : 오른쪽 shift연산 ,나누기 2 아님 , 맨 오른쪽 비트가 버려진다 부호비트는 맨 왼쪽 비트의 부호를 따르게된다.
비트 & 비트 : 비트and연산 두 비트중에 같은것만 1 나머지 0 
비트 | 비트 : 비트or연산 
비트 ^ 비트 : 비트 xor연산 같으면 false 다르면 true

^를 두번쓰면 원본을 알수있다 암호에서 사용

(aInt ^ bInt)^bInt = aInt


상태이상 처리할때 사용가능


*/

int main() {

	
	int aInt = 10;
	int bInt = 3;

	int dInt = (aInt = bInt); // 3 

	aInt += bInt; //6

	aInt = 0;
	bInt = 3;

	

	//cout << ++aInt << endl; 1
	
	aInt = bInt++; //a = 3 b = 4
	aInt = ++bInt; //a = 5 b = 5

	cout << aInt << endl; // 5

	aInt = 3;
	bInt = 5;

	bool check1 = (aInt < bInt);//1 t
	bool check2 = (aInt == bInt);//0 f
	bool check3 = check1 < check2;//0 f
	bool check4 = (check1 && check3);// 0 f
	bool check5 = !check4 +10;//1 t
	bool check6 = check4 || check5 || check1||check3||check2;//1 t
	
	unsigned char stun = 0b1000;
	unsigned char airbone = 0b0100;
	unsigned char rooted = 0b0010;
	unsigned char slow = 0b0001;
	//상태이상 처리할때 사용가능
	unsigned char bitFlag = 0;

	//기절에 걸림
	bitFlag = 0b1000;
	bitFlag = stun | slow; // 기절 , 둔화 상태
	//기절에 걸렸는지 확인하고싶다 조건문안에 0이 아니면 true
	if (bitFlag & stun /* 0b1000*/) {
		//and비트연산으로 상태이상 확인
		cout << " 기절상태입니다 " << endl;
	}

	bitFlag^ slow; // bitFlag -= slow;
	bitFlag | rooted;

	/*
	bitFlag ^=(slow|rooted);
	*/
	if (bitFlag & stun | bitFlag & rooted) { // bitFlag&(slow|rooted)
		cout << " 기절과 속박에 걸렸습니다 " << endl;

	}


}
/*
과제
1. 상수(절대바꿀수없는)를 표시하는 3가지 방법

*/