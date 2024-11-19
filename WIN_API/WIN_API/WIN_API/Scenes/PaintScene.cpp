#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
    myRect->Center() = LinearInterpolation(myRect->Center(), mousePos, 0.1f);

    myCircle->Update();
    myRect->Update();
    myLine->Update();
}

void PaintScene::Render(HDC hdc)
{
    //Ÿ��
   //Ellipse(hdc,0,0,100,100);//�ȼ����� �Ҽ����� �����Ƿ� int�� 
   //myCircle->Center() = mousePos;
    myCircle->Render(hdc);

    //�簢��
    //Rectangle(hdc, 0, 0, 100, 100); //�׸��� ������ ���� ������� �� �ִ�.
    myRect->Render(hdc);
    //��
    //MoveToEx(hdc, 500, 500, nullptr);
    //LineTo(hdc, 700, 700);
   // myLine->End() = mousePos;
    myLine->Render(hdc);
}
