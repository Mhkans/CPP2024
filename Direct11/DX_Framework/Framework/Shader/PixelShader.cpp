#include "framework.h"
#include "PixelShader.h"

PixelShader::PixelShader(LPCWSTR file_loc, DWORD flags)
// LPCWSTR = WCHAR = 한 글자를 2바이트로 표기하는 문자열 자료형
// API 때부터 기존의 char 문자열을 지원하는 대신
// 문자 하나당 2바이트를 이용하는 유니코드 형식의 문자열을 이용하는 경우가 많아짐
// 그래서 매겨변수 역시 LPCWSTR이라는 2바이트짜리 상수 문자열(=수정이 불가능한 문자열)으로 만들어서
// 함수에서 요구하는 자료형과 일치시켜준 것

// 나중엔 이걸 wstring이라는 유니코드 지원 문자열 클래스로 교체할 예정
{
    ID3DBlob* pixelBlob;
    // 셰이더를 만들기 위해서 잠깐 사용하는 버퍼

    D3DCompileFromFile(file_loc, nullptr, nullptr, "main",
        "ps_5_0", flags, 0, &pixelBlob, nullptr);
    // VertexShader와 똑같지만, 만드는 셰이더 자체가 다른 종류의 셰이더이니
    // 그에 맞게 매개변수를 살짝 변경

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
