#include "framework.h"

VertexBuffer::VertexBuffer(void* data, UINT s, UINT count)
	: stride(s), offset(0)
{
	// 기존에 도형을 출력하기 위해 Scene 등에서 만들었던던 버퍼 생성 코드를
	// 여기서 실행하도록 가져옴

	D3D11_BUFFER_DESC bd = {}; // 설정을 저장해두는 구조체
	bd.Usage = D3D11_USAGE_DEFAULT; // 이 버퍼의 용도
	bd.ByteWidth = stride * count; // 대역폭 - 이 버퍼가 가진 데이터가 총 얼마만큼인지를 표기하는 값
	// 셰이더 파일은 C++이 아닌 탓에 받아오는 데이터의 총 용량 등을 제대로 파악하지 못함
	// 따라서 총 용량이 얼마인지를 직접 데이터로서 적어줘야 할 필요가 있음
	
	// 여기서는 정점 하나당의 용량을 매개변수로서 입력받아, 같이 입력받은 꼭지점의 개수를 통해 총 용량을 계산
	
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	// 이 버퍼가 어떤 것을 저장해두는 버퍼인지를 알리는 멤버
	// 이게 실제 용도와 일치하지 않으면 정상적으로 처리되지 않으므로 반드시 용도에 맞게 맞춰줘야 함
	// 여기서는 정점을 기록하는 버퍼이므로 위와 같이 적힌 것

	D3D11_SUBRESOURCE_DATA initData = {};
	initData.pSysMem = data;
	// 초기화하는데 사용할, 실제 데이터가 저장되어 있는 구조체를 생성

	DEVICE->CreateBuffer(&bd, &initData, &buffer);
	// 모든 데이터가 준비되었으면, 이를 DX 디바이스에 보내 버퍼를 생성하여 멤버에 저장
}

VertexBuffer::~VertexBuffer()
{
	buffer->Release();
}

void VertexBuffer::Set(D3D11_PRIMITIVE_TOPOLOGY type)
// 받아온 매개변수를 통해 DVC에 어떤 도형을 출력할 것인지 + 어떤 자료를 사용할 것인지를 세팅하는 함수
{
	DVC->IASetVertexBuffers(0, 1, &buffer, &stride, &offset);
	DVC->IASetPrimitiveTopology(type);
}
