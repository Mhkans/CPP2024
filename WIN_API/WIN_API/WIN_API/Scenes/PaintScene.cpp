#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
    _pens.reserve(3);
    {
        _pens.push_back(CreatePen(3, 3, RGB(255, 0, 0)));//빨
        _pens.push_back(CreatePen(3, 3, RGB(0, 255, 0)));//초
        _pens.push_back(CreatePen(3, 3, RGB(0, 0, 255)));//파
    }  
    _brushes.reserve(3);
    {
        _brushes.push_back(CreateSolidBrush(RGB(255, 0, 0)));
        _brushes.push_back(CreateSolidBrush(RGB(0, 255, 0)));
        _brushes.push_back(CreateSolidBrush(RGB(0, 0, 255)));
        
    }
    myCircle->SetRed();
    myRect->SetGreen();
}

PaintScene::~PaintScene()
{
    for (auto pen : _pens) {
        DeleteObject(pen);
    }
    for (auto brush : _brushes) {
        DeleteObject(brush);
    }
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

    
    myRect->Render(hdc);
    
    myCircle->Render(hdc);
    SelectObject(hdc, _pens[2]);
    myLine->Render(hdc);





    //SelectObject(hdc, _brushes[_curColor]);


    //타원
    //Ellipse(hdc,0,0,100,100);//픽셀에는 소수점이 없으므로 int형 
    //myCircle->Center() = mousePos;
   

    //사각형
    //Rectangle(hdc, 0, 0, 100, 100); //그리는 순서에 따라 덮어씌워질 수 있다.
    
    //선
    //MoveToEx(hdc, 500, 500, nullptr);
    //LineTo(hdc, 700, 700);
    //myLine->End() = mousePos;
   
}
