#pragma once
class Liner
{
public:
	struct HitResult
	{
		bool isCollision = false;
		Vector hitPoint;
	};
	Liner(Vector start, Vector end);
	~Liner();

	Vector& End() { return _end; }
	void Update();
	void Render(HDC hdc);
	void SetRed() { _curColor = 0; }
	void SetGreen() { _curColor = 1; }
	HitResult IsCollision(shared_ptr<Liner> other);
	bool IsBetween(Vector center, Vector left, Vector right);
public:
	Vector _start;
	Vector _end;
	HPEN _colors[2];
	int _curColor = 1;
};

