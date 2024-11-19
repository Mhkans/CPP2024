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
    //타원
   //Ellipse(hdc,0,0,100,100);//픽셀에는 소수점이 없으므로 int형 
   //myCircle->Center() = mousePos;
    myCircle->Render(hdc);

    //사각형
    //Rectangle(hdc, 0, 0, 100, 100); //그리는 순서에 따라 덮어씌워질 수 있다.
    myRect->Render(hdc);
    //선
    //MoveToEx(hdc, 500, 500, nullptr);
    //LineTo(hdc, 700, 700);
   // myLine->End() = mousePos;
    myLine->Render(hdc);
}
