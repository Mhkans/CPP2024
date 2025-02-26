#pragma once
class PixelShader
{
private:
	ID3D11PixelShader* PS;

public:
	PixelShader(LPCWSTR file_loc, DWORD flags);
	~PixelShader();

	void Release();
	ID3D11PixelShader* GetPixelShader() { return PS; }

};