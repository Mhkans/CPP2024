#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
    _pens.reserve(3);
    {
        _pens.push_back(CreatePen(3, 3, RGB(255, 0, 0)));//��
        _pens.push_back(CreatePen(3, 3, RGB(0, 255, 0)));//��
        _pens.push_back(CreatePen(3, 3, RGB(0, 0, 255)));//��
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


    //Ÿ��
    //Ellipse(hdc,0,0,100,100);//�ȼ����� �Ҽ����� �����Ƿ� int�� 
    //myCircle->Center() = mousePos;
   

    //�簢��
    //Rectangle(hdc, 0, 0, 100, 100); //�׸��� ������ ���� ������� �� �ִ�.
    
    //��
    //MoveToEx(hdc, 500, 500, nullptr);
    //LineTo(hdc, 700, 700);
    //myLine->End() = mousePos;
   
}
