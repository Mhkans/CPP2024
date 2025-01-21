#pragma once
class Device
{
public:
	static void Create() {
		if (_instance == nullptr) {
			_instance = new Device();
		}
	}
	static void Delete() {
		if (_instance != nullptr) {
			delete _instance;
		}
	}
	static Device* Instance() {
		return _instance;
	}
	Microsoft::WRL::ComPtr<ID3D11Device> GetDevice() { return _device; }

		
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> GetDC() { return _deviceContext; }

	Microsoft::WRL::ComPtr<IDXGISwapChain> GetSwapChain() { return _swapChain; }

	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> GetRTV(){ return _renderTargetView; }


private:
	Device();
	~Device();

	static Device* _instance;
	// 인력사무소장
	// 외주를 맡기고 실질적인 공사 대표 뽑기
	// 컴퓨터 하드웨어 기능 점검, 리소스 할당(하드웨어 접근에 필요한 리소스 할당)
	Microsoft::WRL::ComPtr<ID3D11Device>							_device;

	// 연출감독
	// 세트장을 실질적으로 꾸며주는 연출가
	// 렌더링 대상 결정(어따 그릴지, 얼마나 그릴지 결정)
	// -> 리소스를 그래픽 파이프라인에 바인딩, GPU가 수행할 명령을 지시
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>						_deviceContext;

	// DX의 인터페이스로써 1개 이상의 표면을 포함하는 얘
	// 각각의 표면(버퍼, 텍스쳐)를 출력하기 전에 데이터를 보관한다.
	Microsoft::WRL::ComPtr<IDXGISwapChain>							_swapChain;

	// 후면버퍼를 가리키는 포인터
	// 후면버퍼(지금 당장 그릴 곳)
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>					_renderTargetView;

};

