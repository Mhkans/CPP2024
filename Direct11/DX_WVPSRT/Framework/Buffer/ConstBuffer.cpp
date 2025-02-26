#include "framework.h"
// 기본적으로는 VB와 하는 일이 거진 똑같기 때문에,
// 특히 생성자에서는 몇 개 멤버의 값이 바뀌었을 뿐이므로 여기의 설명은 생략
// 바뀐 값들이 왜 바뀌었는지 정도만 생각해보면 될 것

ConstBuffer::ConstBuffer(void* data, UINT data_size)
	: data(data), data_size(data_size)
{	
	D3D11_BUFFER_DESC bd = {};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = data_size;

	bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = data;

	DEVICE->CreateBuffer(&bd, &initData, &buffer);
}

ConstBuffer::~ConstBuffer()
{
	buffer->Release();
}

// 이하의 두 함수는, 셰이더 파일에 상수 버퍼를 어떻게 보낼 것인지를 설정하는 함수
// 매개변수로서 셰이더의 어떤 슬롯을 이용할 것인지 설정해주면,
// 이 상수 버퍼는 그 셰이더 내부에 적혀있는 슬롯에 대응하는 행렬에 데이터를 보내주는 것

void ConstBuffer::SetVS(UINT slot)
{
	DVC->UpdateSubresource(buffer, 0, NULL, data, 0, 0);
	DVC->VSSetConstantBuffers(slot, 1, &buffer);
}
void ConstBuffer::SetPS(UINT slot)
{
	DVC->UpdateSubresource(buffer, 0, NULL, data, 0, 0);
	DVC->PSSetConstantBuffers(slot, 1, &buffer);
}
