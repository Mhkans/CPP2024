#pragma once
/*
Trnasform(트랜스폼) : 컴퓨터 그래픽에서 한 오브젝트를 관리하는 기본 단위

트랜스폼은 바로 그 좌표, 크기, 회전도 등을 저장하고 관리하는 기본 데이터 묶음집을 칭하는 개념
-> 오브젝트를 표현하기 위해 반드시 하나씩은 가지고 있는 심장 내지 쐐기

앞으로 우리는 DX에서 뭔가를 만들 떄,
3D 공간에서 각 오브젝트아 어느 위치, 어느 방향으로 어느 크기를 가지고 있는지 
SRT 변환 및 WVP 변환 이론을 통해 구성된 이 트랜스폼을 이용해 관리할 예정

*/

class Transform
{
protected: 
	Matrix world; 
	// 이 오브젝트(=트랜스폼)가 속한 월드를 기록하는 행렬 = 이 오브젝트의 월드 행렬
	// 오브젝트를 다룰 떄 어디를 기준점으로 할 것인지를 행렬의 형태로 저장해
	// 이를 추후 셰이더의 월드 변환에 사용하도록 넘기는 역할

	MatrixBuffer* WB; 
	// 위의 월드 행렬을 셰이더에 넘길 떄 규격에 맞게 저장해 사용할 상수 버퍼

	Vector2 pivot;
	// 지금 당장은 다루지 않을 내용
	// 나중에 사용할 개념이라고 생각하면 OK

	Matrix* parent;
	// 이 오브젝트가 다른 오브젝트에 그 위치 등을 의존하고 있을 경우
	// 그 의존하는 오브젝트의 월드 행렬을 저장하는 용도로 사용하는 멤버

	Matrix S, R, T, P, IP; 
	// SRT 행렬 변환에 사용될 변환 행렬들을 저장할 멤버
	// P와 IP는 위의 pivot을 이용할 떄 사용하는 행렬이니 지금은 무시해도 OK

	XMFLOAT4X4 mat_world; 

	Vector2 global_scale;

	Vector2 right;
	Vector2 up;

public:
	bool is_active; // 이 오브젝트가 활성화되어있는지의 여부를 저장하는 플래그

	Vector2 pos; // 이 오브젝트가 가지고 있는 좌표
	Vector2 scale; //         ''			크기
	Float3 rot;  //			  ''			회전각
	// 이 Transform이 위치해있는 공간의 원점 및 회전축 x/y/z를 기준으로
	// 각각 0도를 기준으로 하여 얼마나 회전해있는가를 저장하는 멤버
	
	// 현 시점에서는 XY평면 하나만을 이용하고 있기 때문에,
	// X축 회전과 Y축 회전은 우리가 다룰 일이 없음
	// 따라서 XY평면에서 유효한 Z축 회전만을 다루게 되므로 우리는 Float3인 rot의 값 중 z값만 이용할 것


	Transform(Vector2 p = Vector2(0, 0), Vector2 s = Vector2(1, 1), float a = 0,
			Matrix* parent = NULL);
	~Transform();

	float GetAngle() { return rot.z; } // 상술했듯 2D를 다루고 있는 본 프로젝트에선
	// z축 회전각만 이용하게 되므로 그것만 다루게 됨
	void SetAngle(float a) { rot.z = a; }

	void SetActive(bool active) { is_active = active; }
	bool GetActive() { return is_active; }

	void SetParent(Matrix* parent) { this->parent = parent; }

	void WorldUpdate();
	// 오브젝트를 프로그램 상에서 업데이트하는 동안
	// 그렇게 업데이트된 데이터가 셰이더 쪽에 넘어갈 수 있도록 데이터를 재정비하는 과정이 필요함
	// 따라서, 업데이트 과정에서 변경된 패러미터를 월드 행렬에 반영시키기 위해,
	// 항상 업데이트 후 실행시켜줘야 하는 SRT 변환 행렬을 구하는 함수

	Matrix* GetWorld() { return &world; };
	// 그렇게 만들어지고 업데이트된 월드 행렬은 트랜스폼 외부에서 사용해야 하는 경우가 매우 많기 때문에,
	// 이를 접근 가능한 접근자를 만들어둠

	Vector2 GlobalPos()
	{
		return Vector2(mat_world._41, mat_world._42);
	}
	Vector2 GlobalScale() 
	{
		return global_scale;
	}

	Vector2 Right() { return right.Normalized(); }
	Vector2	Left() { return right.Normalized() * -1.0f; }
	Vector2 Up() { return up.Normalized(); }
	Vector2 Down() { return up.Normalized() * -1.0f; }

};

