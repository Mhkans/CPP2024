#pragma once
// 이 헤더는 이 프로젝트에서 사용할 각종 상수 버퍼들을 정의하는 헤더

class MatrixBuffer : public ConstBuffer // 변환 행렬을 저장 및 전달할 버퍼
{
private:
	struct Data
	{
		Matrix matrix;
	} data;

public:
	MatrixBuffer() : ConstBuffer(&data, sizeof(data))
	{
		data.matrix = XMMatrixIdentity();
		// 기본 생성자로서는 단위 백터를 저장

	}

	void Set(Matrix value)
	{
		data.matrix = XMMatrixTranspose(value);
		// 행렬 전용 복사함수
	}

};

class ColourBuffer : public ConstBuffer // 색상값을 저장해두는 버퍼
{
public:
	struct Data
	{
		Float4 colour;
	} data;

	ColourBuffer() : ConstBuffer(&data, sizeof(data))
	{
		data.colour = Float4(1.0f, 1.0f, 1.0f, 1.0f);
	}
};