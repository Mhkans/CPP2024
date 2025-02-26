#include "framework.h"

SRTScene::SRTScene()
{
	t1 = new SRTTriangle(Vector2(WIN_CENTER_X, WIN_CENTER_Y), Vector2(2.0f, 0.5f), 0, Vector2(200, 200));
	t2 = new SRTTriangle(Vector2(200, 0), Vector2(1.0f, 1.0f), 0, Vector2(100, 100));

	delta = 0;
}

SRTScene::~SRTScene()
{
	delete t1;
	delete t2;
}

void SRTScene::Update()
{
	//t1->pos.x += 0.01f;
	if (t1->pos.x > WIN_WIDTH)
		t1->pos.x = 0;

	//t1->rot.z += 0.0001f;

	t1->Update();

	t2->pos.x = cos(delta) * 200.0f;

	t2->rot.z += 0.0003f;

	t2->Update(t1->GetWorld());
	// 이런 식으로 한 오브젝트의 parent에 다른 오브젝트의 월드를 등록해두면
	// 이후 그 오브젝트의 위치 계산 등은 등록한 월드의 영향을 받는 식으로 처리됨

	// -> 크기, 회전, 위치에 대한 데이터를 부모가 가진 월드의 적용이 끝난 뒤 거기에 추가적으로 작업
	// 부모의 크기 설정이 2.0과 0.5로 되어있었다면, 
	// 이 월드를 기반으로 SRT 변환 행렬을 만들 떄는 항상 저 2.0과 0.5가 적용된 상황
	// 이 상태에서 Shape가 가지고 있는 원래 비율으로 출력하게 만들려면,
	// 그 부모가 가지고 있는 scale의 값에 역원을 곱해 1로 만들어지도록 자식 오브젝트의 크기를 역원으로 설정해야 함

	// 회전, 위치 역시 마찬가지
	// 부모 클래스의 현재 위치와 회전각을 기반으로 하여 자식 클래스의 위치가 결정되는 것이 확인된다
	
	// 그 때문에, 출력하고자 하는 대상의 크기를 맞추는 것으로 인해
	// 여기에 영향을 받는 자식 오브젝트들이 정상적으로 계산되지 못하는 것을 막기 위해서
	// 본래는 "출력할 도형/이미지를 담당하는 추가적인 트랜스폼을 만들어 이를 멤버로 삼는 것"이 기본
	// (지금은 빠른 실습을 위해 해당 내용을 건너뜀)

	delta += 0.0005f;
}

void SRTScene::Render()
{
	t1->Render();
	t2->Render();
}
