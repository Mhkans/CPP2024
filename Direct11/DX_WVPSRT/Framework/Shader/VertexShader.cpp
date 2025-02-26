#include "framework.h"
#include "VertexShader.h"


VertexShader::VertexShader(LPCWSTR file_loc, DWORD flags)
{
    ID3DBlob* vertexBlob;
    // 셰이더를 만들기 위해서 잠깐 사용하는 버퍼

    D3DCompileFromFile(file_loc, nullptr, nullptr, "main",
        "vs_5_0", flags, 0, &vertexBlob, nullptr);
    // 파일주소를 입력받아, 거기에 위의 버퍼 등을 이용해 꼭지점 셰이더 객체를 동적 할당하고 초기화하는 함수로,
    // 만들어지는 셰이더는 입력받은 경로에 있는 파일에 적혀있는 HLSL 언어에 따라
    // DirectX 엔진 자체가 컴파일하여 구성하는 방식

    // 매개 변수 중 우리가 알아둬야 할 내용은 다음과 같다 : 
    // file_loc = 우리가 로드할 셰이더 파일의 주소
    // "main" = 이 파일에 있는 진입점 역할을 할,
    //          다르게 말하면 이 파일의 "main" 함수의 이름이 무엇인지를 알리는 역할
    //
    // "vs_5_0" = 이 셰이더의 종류 + 버젼 -> 이 셰이더가 사용하는 정점이 어떤 버젼인지를 명시하는 코드
    //            이게 프로젝트의 설정과 일치하지 않을 경우 에러가 발생할 소지가 있음
    // flags = 셰이더를 생성할 떄의 설정을 세팅하는 변수
    //         들어가는 값을 우리가 바꿀 일이 많진 않으나, 
    //         이 함수가 반드시 요구하는 내용이므로 기억은 해야 함

    Device::Get()->GetDevice()->CreateVertexShader(vertexBlob->GetBufferPointer(),
        vertexBlob->GetBufferSize(), nullptr, &VS);
    // 만약 셰이더의 생성이 성공했다면, 이를 Device를 이용해서 우리가 사용 가능한 형태로 동적 할당
    // 이 코드를 실행할 떄 blob이 nullptr였다는 런타임 에러가 발생한다면,
    // 파일 주소가 잘못됐다는 등의 이유로 셰이더 생성에 실패한 것

    // 아래의 내용은 셰이더 측에서 C++ 쪽이 보낸 꼭지점의 데이터가 어떤 식으로 구성되어 있는지를
    // 인식할 수 있도록 그 구성표를 제공해주는 명세서 역할을 하는 데이터
    D3D11_INPUT_ELEMENT_DESC layouts[] =
    {
        {"POSITION", // "지금 이 부분의 정보는 이 POSITION이라는 '시멘틱'에 들어갈 것이다"
        // ,라고 도착지를 명시하는 부분
        0, // 시멘틱 인덱스 - 시멘틱이 둘 이상 존재할 경우 어느 시멘틱에 들어갈 것인지 명시하는 부분
        // 그러나 같은 시멘틱을 둘 이상 쓰지 않을 것이기 때문에 우리는 쓰지 않는 기능이므로 0 고정

        DXGI_FORMAT_R32G32B32_FLOAT, // 이 시멘틱이 맡을 데이터가 (바이트상으로) 어떻게 구성되었는지를 명시
        // 셰이더와 프로그램의 메인 코드의 언어가 서로 다르기 떄문에
        // 셰이더로 전달된 데이터를 알아서 해석하지 못하므로,
        // 이 데이터가 어디부터 어디까지인지를 직접 + 어떤 자료형인지도 명시해주는 값
        // 위의 내용은 Red 32bit / Green 32bit / Blue 32bit의 실수로 구성된 총 12바이트의 데이터
        // (덤으로 R,G,B는 그냥 각각의 바이트들을 구분하는 구분선 비슷한 느낌으로 표기한 것일 뿐
        //  색상 그 자체를 가리키는 데이터라는 의미는 아님)

        0, // 어느 "슬롯"에 들어갈 것인지를 결정하는 부분
        // 적어도 여기서 우리가 쓸 내용은 아니므로 후일 사용하게 되는 상황이 오면 그 떄 설명

        0, // 이 데이터가 정점의 전체 데이터 중 어디부터 시작되는지,
        // 그 인덱스를 명시하는 부분
        // 1번째 등이 아니라 데이터의 인덱스를 표기하는 내용이므로 배열과 마찬가지로 0부터 시작

        D3D11_INPUT_PER_VERTEX_DATA, 0} // 2D를 배우는 동안 사용할 일 없는 데이터이므로 패스

        ,
        {"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12,
        D3D11_INPUT_PER_VERTEX_DATA, 0}

    };

    UINT layoutSize = ARRAYSIZE(layouts);
    // 그렇게 규격을 지정한 layoutf 배열의 총 용량을 계산
    // 바로 밑에 있는 함수에서 레이아웃 배열의 총 용량을 직접 계산하지 못하기 떄문에,
    // 우리가 미리 계산해서 장치에 알려줘야 하기 때문 

    Device::Get()->GetDevice()->CreateInputLayout(layouts, layoutSize, vertexBlob->GetBufferPointer(),
        vertexBlob->GetBufferSize(), &input_layout);
    vertexBlob->Release();
    // 그렇게 데이터가 전부 완성됐다면 이를 이용해 명세서 인스턴스를 생성
    // 생성이 완료되면 중간에 썼던 임시 버퍼는 할당 해제
}

VertexShader::~VertexShader()
{
    Release();
}

void VertexShader::Release()
{
    VS->Release();
    input_layout->Release();
}

void VertexShader::Set()
{
    DVC->IASetInputLayout(input_layout);
    DVC->VSSetShader(VS, nullptr, 0);
}

