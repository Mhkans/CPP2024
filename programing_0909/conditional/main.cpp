#include<iostream>


/*
 1. 상수표시하는 3가지
 2. 분기문 예시
 3. 포인터에 대해서 조사해오기
*/

/*
1. const - 변수 앞에 const를 사용하면 상수로 만들어 값을 변경할 수 없다. 초기화하지 않으면 쓰레기값이 들어가므로 선언과 동시에 초기화가 필요함
2. enum - 초기화를 하지 않으면 0부터시작해서 1씩 증가 정수형만 가능
3. #define 매크로 - #define aInt 3 이런식으로 정의해두면 aInt는 3으로 고정된다. 컴파일단계에서 치환해 버림 (전처리기 단계에서 변경)


포인터
전자기기가 저장 장치에 데이터를 저장할때 실제 기기상에서 저장되는 위치의 주소를 확보한 뒤 그 주소를 기준으로 해서
해당 위치에 저장할 자료가 요구하는 만큼의 용량을 그 이름에 할당 , 할당된 용량 안에 데이터를 저장하는 것
그렇기 때문에 저장된 데이터를 이용할 때는 데이터가 실제로 저장된 위치와 그 위치에 저장되어있는 자료 둘로 나뉘어 생각할수있고
거기서 자료를 취급하는게 변수 , 주소를 취급하는게 포인터


while(조건식){
실행문
continue; -> 조건식으로 점프

제어식 
break;
}

for(초기식;조건식;제어식){

실행문 
continuel
break;
}
*/
using namespace std;

int main() {

	int aInt = 5;

	if (aInt > 5)
	{
		cout << "aInt는 5보다 큽니다 " << endl;

	}
	else if (aInt < 5) {

		cout << "aInt 는 5보다 작습니다" << endl;
	}
	else {

		cout << "aInt 는 5입니다" << endl;
	}
	switch (aInt)
	{
	case 0:
	{
		cout << "aInt 는 0입니다" << endl;
		break;
	}
	case 5:
	{
		cout << "aInt 는 5입니다" << endl;
		break;
	}

	default:
	{
		cout << "aInt 가 무엇인지 모르겠습니다" << endl;

		break;
	}

	}

	aInt = 0;

	while (true) {

		//continue; 여기에 컨티뉴 적으면 아래가 다 필요없어짐
		aInt++;
		if(aInt > 10)
		{
			break;
		}

	}
	for (int i = 0; i < 10; i++) {

		if (i == 3) {
			continue; // 3일때는 빼고 출력
		}
		if (i == 5) {
			break; // 0 1 2 4
		}
		cout << i << endl;
	}
	return 0;

}