#include "framework.h"
#include "PixelShader.h"

PixelShader::PixelShader(LPCWSTR file_loc, DWORD flags)
// LPCWSTR = WCHAR = �� ���ڸ� 2����Ʈ�� ǥ���ϴ� ���ڿ� �ڷ���
// API ������ ������ char ���ڿ��� �����ϴ� ���
// ���� �ϳ��� 2����Ʈ�� �̿��ϴ� �����ڵ� ������ ���ڿ��� �̿��ϴ� ��찡 ������
// �׷��� �Űܺ��� ���� LPCWSTR�̶�� 2����Ʈ¥�� ��� ���ڿ�(=������ �Ұ����� ���ڿ�)���� ����
// �Լ����� �䱸�ϴ� �ڷ����� ��ġ������ ��

// ���߿� �̰� wstring�̶�� �����ڵ� ���� ���ڿ� Ŭ������ ��ü�� ����
{
    ID3DBlob* pixelBlob;
    // ���̴��� ����� ���ؼ� ��� ����ϴ� ����

    D3DCompileFromFile(file_loc, nullptr, nullptr, "main",
        "ps_5_0", flags, 0, &pixelBlob, nullptr);
    // VertexShader�� �Ȱ�����, ����� ���̴� ��ü�� �ٸ� ������ ���̴��̴�
    // �׿� �°� �Ű������� ��¦ ����

    Device::Get()->GetDevice()->CreatePixelShader(pixelBlob->GetBufferPointer(),
        pixelBlob->GetBufferSize(), nullptr, &PS);

    pixelBlob->Release();

}

PixelShader::~PixelShader()
{
    Release();
}

void PixelShader::Release()
{
    PS->Release();
}
