#pragma once
class Timer : public Singleton<Timer>
	// 이 프로그램 내부에서 시간 경과 등을 확인할 때 사용할 클래스
	// 상속받고자 하는 클래스가 템플릿 클래스일 경우,
	// 템플릿의 포맷에 자식 클래스 그 자체를 넣는 것도 가능
{
private:
	Timer();
	~Timer();

public:
	friend class Singleton; // "여기에 호명한 클래스는 이 클래스의 private에 접근할 수 있다"
	// 라고 특정 대상에 한해 접근 권한을 부여하는 키워드 friend
	// 이게 없으면 실제 싱글폰 인스턴스를 생성하는 걸 도맡는 부모 클래스 측에서
	// 생성자/소멸자를 호출할 수 없게 된다

	float time_scale;	// 1초를 표현하는 데 필요한 "성능 카운터"
	float time_elapsed; // 경과된 시간을 체크하는 데 사용할 멤버

	// 밑의 2개 변수는 타임 스탬프로 사용할 변수
	// 자료형은 long long int -> 64비트, 8바이트를 사용하는 int 
	__int64 cur_time;
	__int64 last_time;
	__int64 period_frequency;
	// 현재 컴퓨터의 사양이 메인 루프를 몇 번 돌릴 수 있는지 저장하는 함수

	int frame_rate;		// FPS
	int frame_count;	// 프로그램 시작 후 경과된 프레임의 개수

	float one_sec_count; // 1초가 지났는지의 여부를 저장하는 변수 
	float run_time;	// 프로그램의 총 가동 시간을 저장하는 변수


	void Update();

	int GetFPS() { return frame_rate; } // FPS 출력 함수
	float GetDeltaTime() { return time_elapsed; } // 이번 '틱'에 경과된 시간을 반환하는 함수
	float GetRunTime() { return run_time; } // 프로그램 실행 후 경과된 시간을 반환하는 함수

};