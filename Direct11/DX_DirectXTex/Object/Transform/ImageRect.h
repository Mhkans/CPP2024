#pragma once
class ImageRect : public Transform
{
private:
	RectUV* image;

	ID3D11ShaderResourceView* srv;

public:
	ImageRect(Vector2 pos = Vector2(0,0), Vector2 size = Vector2(0,0));
	~ImageRect();

	void Update();
	void Render();
};