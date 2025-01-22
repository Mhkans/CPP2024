#pragma once
class TutorialScene :public Scene
{
public:
	TutorialScene();
	~TutorialScene();

	void Update() override;
	void Render() override;
private:
	//shared_ptr<VertexBuffer> _vertexBuffer; //mesh 정점 정보
	//shared_ptr<VertexShader> _vs; //material 재질
	//shared_ptr<PixelShader> _ps; 
	//shared_ptr<SamplerState> _samplerState;
	//shared_ptr<ShaderResourceView> _srv;
	shared_ptr<Quad> _quad;

};

