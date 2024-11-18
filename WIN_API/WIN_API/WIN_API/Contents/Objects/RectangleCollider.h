#pragma once
class RectangleCollider
{
public:

	RectangleCollider(Vector start , int length , int height);
	~RectangleCollider();

	void Render(HDC hdc);

	Vector _start;
	int _height;
	int _length;
};

