#pragma once
class Liner
{
public:
	Liner(Vector start, Vector end);
	~Liner();

	void Render(HDC hdc);

	Vector _start;
	Vector _end;
};

