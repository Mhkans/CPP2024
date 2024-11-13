#include<iostream>

using namespace std;

/*
code
data - 전역변수 정적변수
생성주기 : 프로그램 실행될때 할당 -> 프로그램 종료시 삭제
장점 : 모든 곳에서 접근이 가능하다.
단점 : 프로그램 종료되기 전까지 해제가 불가능, 데이터영역의 크기가 작다

stack - 지역변수 , 반환주소값 , 매개변수 -> 스택프레임
생성주기 : 함수 호출 시 생성 -> 함수 종료시 소멸
장점 , 단점 : 함수 밖으로 꺼낼 수 없다 , 메모리오염 

heap - 프로그래머의 영역
생성주기 : 프로그래머가 직접 생성 ,소멸을 만들어줌



*/

class Player {

public:
	Player(){}
	Player(int hp, int atk) : _hp(hp), _atk(atk) {


	}

	int _hp;
	int _atk;
};




int main() {

	//c스타일 동적할당 : malloc , free
	/*
	void* ptr = malloc(100); //heap 에 100바이트 할당받고 위치를 가리키는 포인터 반환
	int* intPtr = (int*)ptr;

	for (int i = 0; i < 25; i++) {

		*(intPtr + i) = i + 1;

	}

	free(ptr);
	*/
	//c++ 스타일 동적할당 : new delete , new[] delete[]

	int* intPtr = new int(); //4바이트 할당
	Player* pPtr = new Player(10, 2);
	char* charPtr = new char[100]; //100바이트 할당
	Player* pArr = new Player[100]; // 기본생성자 정의를 해야함
	Player* pPtrArr[100] = { nullptr };

	for (int i = 0; i < 100; i++) { //총 400바이트(스택) -> 800바이트(힙)

		pPtrArr[i] = new Player();
	}




	delete[] pArr;
	delete intPtr;
	delete pPtr;
	delete[] charPtr;


	return 0;

}