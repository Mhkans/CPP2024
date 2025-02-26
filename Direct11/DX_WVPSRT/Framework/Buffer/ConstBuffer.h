#pragma once
// Constant(상수) 버퍼 - 정점 전용으로 사용하는 버퍼, 혹은 정점의 순서를 기록하기 위해 사용하는 버퍼 외에
//						다른 용도로 사용하는 버퍼들은 기본적으로 "상수" 버퍼를 이용함
// 정점 버퍼, 인덱스 버퍼 둘은 DX에서 직접적으로 개별적으로서 다루는 버퍼지만
// 나머지 버퍼들은 딱히 전용 버퍼를 준비해주지 않았으므로,
// 그런 것들을 통틇어 구성하는 버퍼

/*
수많은 상수 버퍼들이 공통적으로 가지고 있는 개념들을 정리하기 위한 클래스로,
실제로 사용할 상수 버퍼들은 이 클래스를 상속받아서 만듦(GlobalBuffer.h)
*/
class ConstBuffer
{
private:
	ID3D11Buffer* buffer;

	void* data;

	UINT data_size;

public:
	ConstBuffer(void* data, UINT data_size);
	~ConstBuffer();

	void SetVS(UINT slot);
	void SetPS(UINT slot);
};