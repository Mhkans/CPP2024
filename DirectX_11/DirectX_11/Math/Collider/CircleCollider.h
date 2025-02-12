#pragma once
class CircleCollider :public enable_shared_from_this<CircleCollider>
{
public:
	CircleCollider(Vector center, float radius);
	~CircleCollider();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _transform; }

	void SetRed() { _colorBuffer->SetData(XMFLOAT4(1, 0, 0, 1)); }
	void SetGreen() { _colorBuffer->SetData(XMFLOAT4(0, 1, 0, 1)); }

	float Radius() { return _radius * _transform->GetScale().x; }

	Vector Center() { return _transform->GetWorldLocation(); }
	bool IsCollision(const Vector& pos); //Á¡Ãæµ¹
	bool IsCollision(shared_ptr<class RectCollider> rect);
	bool IsCollision(shared_ptr<class CircleCollider> circle);
private:
	void CreateVertices();
	vector<Vertex>	 _vertices;
	vector<UINT>			 _indices;

	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;

	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<Transform> _transform;
	shared_ptr<ColorBuffer> _colorBuffer;

	float _radius;
	Vector scale;

	int vCount = 37;
	float angle = 2 * PI / vCount;
};

