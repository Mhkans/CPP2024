#pragma once
class Quad
{
public:
	// TextureMapping¿ª ±‚∫ª
	Quad(wstring path);
	~Quad();

	void Update();
	void Render();

	void SetScale(XMFLOAT2 scale) { _scale = scale; }
	void SetAngle(float addAngle) { _addAngle = addAngle; }
	void SetPos(XMFLOAT2 pos) { _pos = pos; }


private:
	void CreateVertices();
	vector<Vertex_Texture> vertices;

	shared_ptr<VertexBuffer> _vertexBuffer;

	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;
	shared_ptr<SamplerState> _samplerState;
	shared_ptr<ShaderResourceView> _srv;

	XMFLOAT2		 _scale; // S
	float			 _angle; // R
	float			 _addAngle;
	XMFLOAT2		 _pos;   // Translate
	shared_ptr<MatrixBuffer> _world;
};

