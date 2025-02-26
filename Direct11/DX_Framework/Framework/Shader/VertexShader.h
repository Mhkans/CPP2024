#pragma once
class VertexShader // 이 자체가 무엇인지는 그래픽 파이프라인에서 설명
{
private:
	ID3D11VertexShader* VS;
	// 꼭지점 셰이더(=정점 세이더)를 담당할 클래스 객체
	ID3D11InputLayout* input_layout;
	// DX 장치에 어떤 꼭지점 데이터를 전달할 것인지
	// 그 꼭지점의 레이아웃(=구조)의 명세서를 저장해두는 객체
	// 여기에 저장된 데이터를 토대로 꼭지점이 입력됐을 떄 셰이더 측에서 이를 해석하여 이용

public:
	VertexShader(LPCWSTR file_loc, DWORD flags);
	~VertexShader();

	void Release();
	ID3D11InputLayout* GetInputLayout() { return input_layout; }
	ID3D11VertexShader* GetVertexShader() { return VS; }
};