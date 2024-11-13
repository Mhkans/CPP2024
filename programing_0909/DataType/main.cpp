#include<iostream>

using namespace std;
/*과제

자료형 크기와 값 출력해오기
short int __int64 float double bool char struct
*/

/*
* x64 ( 64비트 프로그램 ) , x86 ( 32비트 프로그램)
* 데이터 크기
bit - 0,1로만 되어있는 컴퓨터가 계산할수있는 최소 단위
byte - 8bit 
kb mb gb tb 

메모리주소 : 

0b : 2진법으로 저장하겠다
0x : 16진법으로 저장하겠다.
DataType 자료형
- 저장할때 크기와 어떤자료인지 까지 알려주는 힌트

정수형 

short 
크기 : 2바이트 
범위 : -2^15-1 ~ 2^15 => 2^16

int 
크기 : 4바이트
범위 : -2^31-1 ~ 2^31 => 2^32 

__int64, long long

크기 : 8바이트 (64비트)
범위 : -2^63 -1 ~ 2^63 => 2^64

음의 정수를 나타낼때  맨 앞 비트로 부호를 결정한다
=> 0을 표기할때 문제 발생 => 2의 보수법 

양의 정수를 음의 정수로 바꾸는 법
1.모든 비트를 뒤바꾼다
2. +1을 한다

부호 비트 가 없는 정수형

unsigned 

실수형

float
크기 : 4바이트 32비트
부동소수점 : 떠다니듯 움직이는 소수점
(부호 ) (지수 )(유효숫자 )
   1       8       23 비트 

지수 : 127 - 실제지수 

0.5 

0 126 00000000000000000000000
0 0111 1110 00000000000000000000000
실제 : 00 00 00 3f

3f 00 00 00

0011 1111 000000000000000000000000
부동소수점 오차가 발생하므로 실수형은 aFloat == 0.33f 이런식으로 쓰면 절대 안됨
double
크기 : 8바이트 64비트

논리형 bool 
크기 : 1바이트 참과 거짓만 표현
0이면 거짓 0이 아니면 모두 참
컴퓨터가 처리할수있는 최소단위가 1바이트이기 때문에 울며 겨자먹기로 나머지 7비트 사용

문자형
char 
크기 : 1바이트
2^8 경우의 수
아스키코드 유니코드

아스키코드 1 바이트
utf-8 : 영어 1바이트 한국어 중국어 3바이트
utf-16 : 영어 2바이트, 한국어 중국어 2바이트 고대문자 4바이트

사용자 정의 자료형
struct enum

struct Player{

short aShort;
int hp;
float atk;

};

*/
int aInt = 1;
unsigned short a_uShort = 32767; //unsigned 붙었으니까 0~ 2^16 -1 범위를 가진다
short aShort = 32767;
float aFloat = 0.5f;
double aDouble = 0.25;
char aChar = 97; 


struct Player {

	short aShort;
	short padding;
	int _hp;
	float atk;

};

int main() {

	//aShort = 32767 +1;
	aShort = -32768 - 1; // 정수형 오버플로우
	a_uShort = 32767 + 1;

	cout << aShort << endl;
	cout << " short 의 크기 : " << sizeof(aShort) << " 변수 aShort : "<<aShort << endl;
	cout << a_uShort << endl;
	cout << aChar << endl;

	Player p;
	p.aShort = 1; // 스택영역에서 초기화되지않은 영역은 cc(padding byte 패딩바이트)로 채워져있음 서버에 보낼때는 최적화해서 cc를 00으로 채워보냄
	p.padding = 0; // cc채우기용
	p._hp = 2;
	p.atk = 0.0f;

	cout << sizeof(Player) << endl; //제일큰 단위로 묶어서 읽으므로 12가 출력


	return 0;
}
/*
메모리 4영역

1. code - 실행할 프로그램의 코드가 저장되는 영역
cpu가 해당 영역에 저장된 명령을 하나씩 가져가 처리하게 된다.

2. data - 전역변수 , 정적변수 등이 할당되는 공간
main함수 호출전에 data영역에 변수들이 할당되고 프로그램이 끝날때까지 남아있다.
초기화된 변수 영역과 초기화되지 않은 변수 영역이 있다.

3. stack - 함수호출시 생성되는 반환주소값 ,지역변수 , 매개변수가 저장되는 영역
임시 메모리 영역으로 먼저 들어온 데이터가 나중에 나가는 방식이다.
코드를 짜고 컴파일 할때 그 크기가 결정된다.

4. heap - stack과 비슷하지만 사용자에 의해 관리되는 임시메모리 영역
동적 메모리 할당할때 사용되는 영역이다.
컴파일 할 때가 아닌 프로그램이 실제 동작할때 크기가 결정된다.

컴파일 4단계

1. 전처리기 preprocessing - 소스 코드 파일을 전처리된 소스 코드 파일로 변환하는 과정
주석을 전부 제거
#include - 헤더파일을 찾아서 삽입
#define - 매크로 치환 처리

2. 컴파일 compile - 전처리된 소스 코드 파일을 어셈블리어 파일로 변환하는 과정
고수준c++ 언어를 최저수준 어셈블리 언어로 변환
언어의 문법 검사가 이루어짐
메모리 data영역의 메모리 할당을 수행

3. 어셈블리 assembly - 생성된 어셈블리어 파일을 오브젝트 파일로 변환하는 과정
오브젝트 파일은 사람이 알아볼 수 없는 기계어 , 심볼은 함수나 변수를 식별할떄 사용하는 이름
오브젝트 파일 헤더 - 오브젝트 파일의 기초정보를 가지고있는 헤더
텍스트 섹션 - 기계어로 변환된 코드가 들어 있는 부분
데이터 섹션 - 전역변수 , 정적변수가 들어있는 부분
심볼 테이블 섹션 - 소스코드에서 참조되는 심볼들의 이름과 주소가 정의되어 있는 부분
재배치 정보 섹션 - 링킹 전까지 심볼의 위치를 확정 할 수 없으므로 심볼의 위치가 확정 나면 바꿔야 할 내용을 적어놓은 부분
디버깅 정보 섹션 - 디버깅에 필요한 부분이 있는 부분


4. 링킹 linking - 오브젝트 파일들과 프로그램에서 사용하는 라이브러리 파일들을 묶어 하나의 실행파일을 만드는 과정
심볼을 해석해서 같은이름의 함수나 변수가 정의되었을 경우 어떤파일의 어떤 함수를 사용할지 결정
오브젝트 파일 내에 데이터의 주소나 코드의 메모리 참조 주소를 알맞게 재배치

*/