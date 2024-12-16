#pragma once
class Block 
{
public:
	enum BlockType {
		NONE,ABLE,DISABLE,PLAYER,FOOT_PRINT
	};

	Block();
	~Block();

	void Update();
	void Render(HDC hdc);

	BlockType GetType() { return _curType; }
	void SetType(BlockType type) { _curType = type; }
	void SetPos(Vector pos) { _rect->Center() = pos; }
private:
	shared_ptr<RectangleCollider> _rect; //component pattern 부품을 조립해서 쓰는 방법 -> 재사용성이 매우 크게 증가
	BlockType _curType = BlockType::NONE;
	vector<HBRUSH> _brushes;
};

