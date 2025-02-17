#pragma once
class Collider :public enable_shared_from_this<Collider>
{
public:
	Collider() = default;	
	virtual ~Collider() = default;

	virtual void Update() = 0;
	virtual void Render() = 0;

	bool IsCollision(shared_ptr<Collider> other);

	virtual bool IsCollision(const Vector& pos) = 0; //점충돌
	virtual bool IsCollision(shared_ptr<class RectCollider> rect) = 0;
	virtual bool IsCollision(shared_ptr<class CircleCollider> circle) = 0;

	shared_ptr<Transform> GetTransform() { return _transform; }

	void SetRed() { _colorBuffer->SetData(XMFLOAT4(1, 0, 0, 1)); }
	void SetGreen() { _colorBuffer->SetData(XMFLOAT4(0, 1, 0, 1)); }

	Vector Center() { return _transform->GetWorldLocation(); } //월드좌표

	int GetType() { return static_cast<int>(_currType); }

protected:
	enum class Type {
		NONE,RECT,CIRCLE
	};
	Collider::Type _currType = Collider::Type::NONE;

 	virtual void CreateVertices() = 0;
	vector<Vertex>	 _vertices;
	vector<UINT>			 _indices;

	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;

	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<Transform> _transform;
	shared_ptr<ColorBuffer> _colorBuffer;
};

