#pragma once
class Timer : public Singleton<Timer>
	// �� ���α׷� ���ο��� �ð� ��� ���� Ȯ���� �� ����� Ŭ����
	// ��ӹް��� �ϴ� Ŭ������ ���ø� Ŭ������ ���,
	// ���ø��� ���˿� �ڽ� Ŭ���� �� ��ü�� �ִ� �͵� ����
{
private:
	Timer();
	~Timer();

public:
	friend class Singleton; // "���⿡ ȣ���� Ŭ������ �� Ŭ������ private�� ������ �� �ִ�"
	// ��� Ư�� ��� ���� ���� ������ �ο��ϴ� Ű���� friend
	// �̰� ������ ���� �̱��� �ν��Ͻ��� �����ϴ� �� ���ô� �θ� Ŭ���� ������
	// ������/�Ҹ��ڸ� ȣ���� �� ���� �ȴ�

	float time_scale;	// 1�ʸ� ǥ���ϴ� �� �ʿ��� "���� ī����"
	float time_elapsed; // ����� �ð��� üũ�ϴ� �� ����� ���

	// ���� 2�� ������ Ÿ�� �������� ����� ����
	// �ڷ����� long long int -> 64��Ʈ, 8����Ʈ�� ����ϴ� int 
	__int64 cur_time;
	__int64 last_time;
	__int64 period_frequency;
	// ���� ��ǻ���� ����� ���� ������ �� �� ���� �� �ִ��� �����ϴ� �Լ�

	int frame_rate;		// FPS
	int frame_count;	// ���α׷� ���� �� ����� �������� ����

	float one_sec_count; // 1�ʰ� ���������� ���θ� �����ϴ� ���� 
	float run_time;	// ���α׷��� �� ���� �ð��� �����ϴ� ����


	void Update();

	int GetFPS() { return frame_rate; } // FPS ��� �Լ�
	float GetDeltaTime() { return time_elapsed; } // �̹� 'ƽ'�� ����� �ð��� ��ȯ�ϴ� �Լ�
	float GetRunTime() { return run_time; } // ���α׷� ���� �� ����� �ð��� ��ȯ�ϴ� �Լ�

};