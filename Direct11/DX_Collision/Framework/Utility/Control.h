#pragma once
#define KEY_MAX 256
// 일반적인 키보드의 키는 많아봐야 108개,
// 고급 키보드라 추가적인 버튼이 많이 딸려있다 하더라도 140개를 넘거나 하지는 않는다
// -> 255개의 값이면 키보드 + 추가 여러 입력장치들의 데이터를 다룰 수 있다

class Control : public Singleton<Control>
// 이 프로그램에서 입력 장치의 입력을 받아 저장하고,
// 후일 프로그램에서 특정 키가 눌려있는지 아닌지를 검사하는 기능을 제공하는 유틸리티
{
private:
	friend class Singleton;

	enum {
		NONE,
		DOWN,
		UP,
		PRESS,
		MAX
	};
	// 특정 키의 현재 상태를 의미하는 열거형
	// 이 열거형 데이터를 통해 각각의 키의 현재 상태를 정의
	// 위에서부터 "눌리지 않음" / "지금 눌렸음" / "지금 떼졌음" / "현재 눌려있음"을 의미

	// BYTE = unsigned char
	// 왜 이 자료형을 써야 하는지는 Update에서 설명
	BYTE cur_state[KEY_MAX]; // 현재 입력장치 각각의 키가 눌려있는 여부를 저장하는 행렬
	BYTE old_state[KEY_MAX]; // 직전에 Update가 이뤄졌을 당시의 입력 상황을 저장하는 행렬 
	BYTE map_state[KEY_MAX]; // 위 2개의 정보를 이용해,
	// 최종적으로 각 키가 "현재 위 열거형의 데이터들 중 무슨 상태인지"를 저장하는
	// = 각 키의 현재 버튼 상태를 확인하여 그 내용을 저장해두는 배열

	// 위 3개 배열은 키보드의 각 키가 입력되었는지의 여부를 판단할 때 사용할 배열들
	// API에서 비트 플래그를 이용해 키를 저장했던 것이 더욱 발전한 형태
	// 단, 인식하는 키가 적게 잡아도 108개 이상
	// -> 키보드의 모든 키는 물론, 그 외의 몇몇 입력장치들에도 반응할 예정

	Control();
	~Control();

public:
	void Update();

	bool Down(UINT key) { return map_state[key] == DOWN; }
	bool Up(UINT key) { return map_state[key] == UP; }
	bool Press(UINT key) { return map_state[key] == PRESS; }
	// 매개변수로 입력받은 키가 현재 (함수명에 적힌 상태)가 맞는지를 검사하는 함수
	// -> 함수에 입력한 이 키가 현재 눌려있는지 아닌지를 확인하는 함수

};