#pragma once
class SRTScene : public Scene
{
private:
	SRTTriangle* t1;
	SRTTriangle* t2;

	float delta;
public:
	SRTScene();
	~SRTScene();


	// Inherited via Scene
	virtual void Update() override;

	virtual void Render() override;

};