#pragma once
class ImageScene : public Scene
{
private:
	ImageRect* image;
	ImageRect* player;

	ScrollingBG* bg;
public:
	ImageScene();
	~ImageScene();


	// Inherited via Scene
	virtual void Update() override;

	virtual void Render() override;

	virtual void PostRender() override;
	// ImGui에 출력할 데이터들을 출력하도록 세팅하는 함수

};


/* 과제 :

이미지를 가진, 움직이는 오브젝트를 하나 만들 것
단, 그 움직이는 오브젝트는 "마우스 이동"에 따라 움직여야 한다

조건 )
1) 모든 오브젝트는 서로 다른 이미지를 사용해야 함
2) 오브젝트의 개수는 배경을 제외하고 최소 2개(배경은 반드시 포함)
-> 기존 오브젝트는 놔두고 새로 하나 만들란 이야기
3) 과제에서 추가한 오브젝트는 마우스의 이동을 그대로 따라가야 함

힌트
1) API 때 다뤘던 마우스 그 자체

2) extern Vector2 mouse_pos;


*/