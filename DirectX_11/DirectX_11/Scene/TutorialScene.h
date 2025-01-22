#pragma once
class TutorialScene :public Scene
{
public:
	TutorialScene();
	~TutorialScene();

	void Update() override;
	void Render() override;
private:
	//shared_ptr<VertexBuffer> _vertexBuffer; //mesh ���� ����
	//shared_ptr<VertexShader> _vs; //material ����
	//shared_ptr<PixelShader> _ps; 
	//shared_ptr<SamplerState> _samplerState;
	//shared_ptr<ShaderResourceView> _srv;
	shared_ptr<Quad> _quad;

};

