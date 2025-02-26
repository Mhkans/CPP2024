#pragma once
// Buffer 클래스들 : ID3D11Buffer를 용도에 맞게 알아서 생성해주도록 하는 클래스들의 모음집

// VertexBuffer : 그 중 꼭지점의 데이터를 기록해 넘길 버퍼를 담당하는 클래스
class VertexBuffer
{
private:
	ID3D11Buffer* buffer;
	// DX11 규격의 버퍼

	UINT stride;
	// 이 인스턴스에서 저장하고 있는 버퍼가 한 칸마다 사용하는 용량을 저장할 변수

	UINT offset;
	// 사용할 오프셋을 기록하는 멤버

public:
	VertexBuffer(void* data, UINT s, UINT count);
	~VertexBuffer();

	void Set(D3D11_PRIMITIVE_TOPOLOGY type
		= D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	// 도형을 출력하는 방식을 이제 버퍼에서 관리하도록 해주는 함수

};
