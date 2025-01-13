/*
컴파일 4단계
-우리가 읽을수있는 언어를 컴퓨터 언어로 바꾸는 작업

1.전처리기
2.컴파일러
3.어셈블러
4.링커

CPU - 메모리
CPU - 연산 제어 논리 작업을 수행하는 장치
메모리 : 
주기억 장치 Ram 
- 게임을 실행시키면 현재눈에 보여야하는 데이터들이 이 장치에 올라온다
- 휘발성 메모리
- 읽고 저장하는데 빠르다 물리적으로 거리가 가깝다

보조기억 장치 SSD
- 게임을 다운받으면 여기다가 저장
- 읽고 저장하는데 오래걸림 물리적 거리가 멀다

메모리(주기억장치) 

code : 코드 저장 
data : 전역변수 , 정적변수 (초기화 안되어있으면 00으로 밀려있음)
stack : 지역변수 매개변수 반환주소값 -> 스택프레임 (초기화가 안되어있으면 cc로 밀려있음)
heap : 사용자가 조절하는 메모리 

스택은 컴파일타임에 크기가 결정된다.
스택프레임 : 함수가 호출될때 stack영역에 쌓여있는 반환주소값 매개변수 지역변수 

재귀호출 주의할점 스택오버플로우

// 메모이제이션 으로 방지가능


자료형 : 컴퓨터가 데이터를 읽을때 구분
정수자료형을 실수자료형으로 읽으면 부동소수점때문에 이상한값이나옴
같은 비트라도 읽는 방식이 다르기 때문

포인터
(자료형)* 포인터변수이름 = (초기화);
크기 : 32비트환경에서는 4바이트씩 처리 - 4바이트, 64비트환경에서는 8바이트씩 처리 - 8바이트

ref
(자료형)& (Ref 이름) = (초기화);
- C++ 관점 : 해당 변수의 별명
- 어셈블리어 : 포인터랑 동일하다.
- 크기 : 32비트환경(4바이트) 64비트환경(8바이트)

ptr, ref 차이
1. 포인터는 중간에 대상을 변경할 수 있다 / Ref는 중간에 대상을 변경할 수 없다.
2. 포인터는 nullptr을 저장할 수 있다. / Ref 없는 값을 참조할 수 있다.
3. 포인터는 초기화를 하지않아도 된다. / Ref는 무조건 초기화

정의 와 왜 를 설명해야한다

객체지향 3속성
1.은닉성
접근지정자 public(어디서든) /protected(멤버함수 ,자식의 멤버함수) / private(멤버변수 , friend클래스)
왜 쓰냐 외부에서 쉽게 혹은 직접 접근해서 바꾸지못하게 하려고
멤버함수 내에서만 통제하기위해서(예를들면 자동차 클래스에서 public으로 선언할 멤버 바퀴 , private로 선언할 멤버 엔진)
사용자가 건들수 없게 하려고





*/
