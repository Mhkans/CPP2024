#include "framework.h"

Timer::Timer()
	: frame_rate(0), frame_count(0), time_elapsed(0), one_sec_count(0), run_time(0)
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&period_frequency);
	// 기본적으로 프로그램의 메인 루프는 굉장히 빠른 빈도로 반복되고 있음
	// 그 반복되는 횟수가 초당 얼마인지 파악하여,
	// 매개변수를 통해 입력받은 포인터에 저장하는 함수

	// -> 현재 컴퓨터의 사양이 메인 루프를 초당 몇 번 돌릴 수 있는지 검사하는 함수

	QueryPerformanceCounter((LARGE_INTEGER*)&last_time);
	// 성능 카운터 = 위의 메인 루프가 실행된 횟수를 기록한 데이터
	// 이를 받아서 타임스탭프에 저장하는 것으로 실질적으로 현재 시각이 언제인지를
	// 시스템에게서 받아오는 함수
	
	time_scale = 1.0f / (float)period_frequency;
	// lli인 period_frequency를 1초에서 나누는 것으로
	// 저 "성능 카운터" 하나가 실제로 몇 초를 의미하는 것인지를 여기서 계산해 저장

}

Timer::~Timer()
{
}

void Timer::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&cur_time);
	// 현재시각을 저장
	// 정확히는 현재 시각까지 실행되었던 쿼리의 개수 = 메인 루프의 반복 휫수를 저장

	time_elapsed = (float)(cur_time - last_time) * time_scale;
	// 마지막으로 기록된 성능 카운터를 현재 시점에서의 성능 카운터에서 빼고,
	// 그렇게 구한 카운터의 변동값에 time_scale(=성능 카운터 하나당 실제 경과시간)을 곱해
	// 최종적으로 실제 경과된 시간을 계산

	if (time_elapsed > 0.1f)
		time_elapsed = 0.1f;
	// 프로그램에 뭔가 이상이 생겨서 일정 시간 동안 시간경과를 계산하지 못하는 경우가 생길 수 있음
	// (창의 제목 표시줄을 드래그해 움직이는 등)
	// 그런 상황에서 계산이 꼬이지 않도록, 경과 가능한 시각을 최소한으로 줄이는 장치

	last_time = cur_time;
	// 기본적인 연산이 끝났으면 타임 스탬프 갱신

	frame_count++;
	// 1초당 몇 번의 작업이 진행되었는지 우리가 직접 체크

	one_sec_count += time_elapsed;
	// 경과한 총 시간을 계속해서 누적 저장

	if (one_sec_count >= 1.0f) // 총 1초가 경과됐는지 확인
	{
		frame_rate = frame_count;
		one_sec_count = frame_count = 0;
		// 1초가 경과되었다면 현 시점의 FPS를 갱신,
		// 연산에 사용된 값들을 초기화
	}

	run_time += time_elapsed;
	// 이번 업데이트에 걸린 총 시간을 run_time에 기록
}
