#pragma once
class Transform
{
public:
	Transform();
	~Transform();

	void Update();
	void SetVSSlot(int slot);
	//정보를 cpu가 주지않고 렌더하니까 행렬에 곱셈이되지않는 문제 예방 
	void SetLocalLocation(Vector pos) { _pos = pos; Update(); } // 행렬을 고쳤으니 업데이트
	Vector GetLocalLocation() { return _pos; }
	void AddLocalLocation(Vector value) { _pos += value; }

	Vector GetWorldLocation();


	void SetScale(Vector scale) { _scale = scale; Update();}
	Vector GetScale() { return _scale; }
	void AddScale(Vector value) { _scale += value; }


	void SetAngle(float angle) { _angle = angle; Update();}
	float GetAngle() { return _angle; }
	void AddAngle(float value) { _angle += value; }

	void SetParent(shared_ptr<Transform> parent) { _parent = parent; Update();}

	XMMATRIX GetMatrix() { return _srtMatrix; }

	Vector GetWorldScale();
private:
	weak_ptr<Transform> _parent;
	XMMATRIX _srtMatrix;
	//Transform 구성
	Vector		 _scale; // S
	float		 _angle; // R
	Vector		 _pos;   // Translate
	shared_ptr<class MatrixBuffer> _world;
};

