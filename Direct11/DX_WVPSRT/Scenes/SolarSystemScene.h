#pragma once
class SolarSystemScene : public Scene
// 태양계를 대충 재현해보는 Scene
/*
구성요소로서는 태양 + 여러 행성들이 들어갈 것
일단은 수금지화는 확정, 이 이후는 만들 시간이 있으면 추가로 만들기

다음으로는 저 태양과 행성들을 어떻게 출력할 것인가?


*/
{
private:
	Planet* sun;

	Planet* mercury;
	Planet* venus; // (본래는 아니지만 여기선)금성만 공전 방향이 다르다

public:
	SolarSystemScene();
	~SolarSystemScene();



	// Inherited via Scene
	virtual void Update() override;

	virtual void Render() override;

};