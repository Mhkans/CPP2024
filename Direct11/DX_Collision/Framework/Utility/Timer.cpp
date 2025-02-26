#include "framework.h"

Timer::Timer()
	: frame_rate(0), frame_count(0), time_elapsed(0), one_sec_count(0), run_time(0)
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&period_frequency);
	// �⺻������ ���α׷��� ���� ������ ������ ���� �󵵷� �ݺ��ǰ� ����
	// �� �ݺ��Ǵ� Ƚ���� �ʴ� ������ �ľ��Ͽ�,
	// �Ű������� ���� �Է¹��� �����Ϳ� �����ϴ� �Լ�

	// -> ���� ��ǻ���� ����� ���� ������ �ʴ� �� �� ���� �� �ִ��� �˻��ϴ� �Լ�

	QueryPerformanceCounter((LARGE_INTEGER*)&last_time);
	// ���� ī���� = ���� ���� ������ ����� Ƚ���� ����� ������
	// �̸� �޾Ƽ� Ÿ�ӽ������� �����ϴ� ������ ���������� ���� �ð��� ����������
	// �ý��ۿ��Լ� �޾ƿ��� �Լ�
	
	time_scale = 1.0f / (float)period_frequency;
	// lli�� period_frequency�� 1�ʿ��� ������ ������
	// �� "���� ī����" �ϳ��� ������ �� �ʸ� �ǹ��ϴ� �������� ���⼭ ����� ����

}

Timer::~Timer()
{
}

void Timer::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&cur_time);
	// ����ð��� ����
	// ��Ȯ���� ���� �ð����� ����Ǿ��� ������ ���� = ���� ������ �ݺ� �ܼ��� ����

	time_elapsed = (float)(cur_time - last_time) * time_scale;
	// ���������� ��ϵ� ���� ī���͸� ���� ���������� ���� ī���Ϳ��� ����,
	// �׷��� ���� ī������ �������� time_scale(=���� ī���� �ϳ��� ���� ����ð�)�� ����
	// ���������� ���� ����� �ð��� ���

	if (time_elapsed > 0.1f)
		time_elapsed = 0.1f;
	// ���α׷��� ���� �̻��� ���ܼ� ���� �ð� ���� �ð������ ������� ���ϴ� ��찡 ���� �� ����
	// (â�� ���� ǥ������ �巡���� �����̴� ��)
	// �׷� ��Ȳ���� ����� ������ �ʵ���, ��� ������ �ð��� �ּ������� ���̴� ��ġ

	last_time = cur_time;
	// �⺻���� ������ �������� Ÿ�� ������ ����

	frame_count++;
	// 1�ʴ� �� ���� �۾��� ����Ǿ����� �츮�� ���� üũ

	one_sec_count += time_elapsed;
	// ����� �� �ð��� ����ؼ� ���� ����

	if (one_sec_count >= 1.0f) // �� 1�ʰ� ����ƴ��� Ȯ��
	{
		frame_rate = frame_count;
		one_sec_count = frame_count = 0;
		// 1�ʰ� ����Ǿ��ٸ� �� ������ FPS�� ����,
		// ���꿡 ���� ������ �ʱ�ȭ
	}

	run_time += time_elapsed;
	// �̹� ������Ʈ�� �ɸ� �� �ð��� run_time�� ���
}
