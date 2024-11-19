#pragma once
class Liner
{
public:
	Liner(Vector start, Vector end);
	~Liner();

	Vector& End() { return _end; }
	void Update();
	void Render(HDC hdc);

	Vector _start;
	Vector _end;
};

