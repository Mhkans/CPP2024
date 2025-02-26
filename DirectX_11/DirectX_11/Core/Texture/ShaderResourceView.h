#pragma once
class ShaderResourceView
{
public:
	ShaderResourceView(wstring file);
	~ShaderResourceView();

	void PSSet(int slot);

	Vector GetSize();
private:
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> _srv;
	ScratchImage image;
};

