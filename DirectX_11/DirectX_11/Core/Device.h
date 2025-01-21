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
	// �η»繫����
	// ���ָ� �ñ�� �������� ���� ��ǥ �̱�
	// ��ǻ�� �ϵ���� ��� ����, ���ҽ� �Ҵ�(�ϵ���� ���ٿ� �ʿ��� ���ҽ� �Ҵ�)
	Microsoft::WRL::ComPtr<ID3D11Device>							_device;

	// ���Ⱘ��
	// ��Ʈ���� ���������� �ٸ��ִ� ���Ⱑ
	// ������ ��� ����(��� �׸���, �󸶳� �׸��� ����)
	// -> ���ҽ��� �׷��� ���������ο� ���ε�, GPU�� ������ ����� ����
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>						_deviceContext;

	// DX�� �������̽��ν� 1�� �̻��� ǥ���� �����ϴ� ��
	// ������ ǥ��(����, �ؽ���)�� ����ϱ� ���� �����͸� �����Ѵ�.
	Microsoft::WRL::ComPtr<IDXGISwapChain>							_swapChain;

	// �ĸ���۸� ����Ű�� ������
	// �ĸ����(���� ���� �׸� ��)
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>					_renderTargetView;

};

