#pragma once
class TutorialScene : public Scene
{
private:
	VertexShader* VS;
	PixelShader* PS;

	Triangle* list_triangle;
	Triangle* strip_triangle;


public:
	TutorialScene();
	~TutorialScene();



	// Inherited via Scene
	virtual void Update() override;

	virtual void Render() override;

};