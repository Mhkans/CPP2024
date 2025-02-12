#include "framework.h"
#include "RectCollider.h"
#include "CircleCollider.h"
RectCollider::RectCollider(Vector center, Vector size)
	:_halfSize(size*0.5f)
{
	CreateVertices();
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), _vertices.size(), sizeof(Vertex));
    _vs = make_shared<VertexShader>(L"Shader/ColliderVertexShader.hlsl");
    _ps = make_shared<PixelShader>(L"Shader/ColliderPixelShader.hlsl");

    _transform = make_shared<Transform>();
    _transform->SetLocalLocation(center);

    _colorBuffer = make_shared<ColorBuffer>();
    _colorBuffer->SetData(XMFLOAT4(0, 1, 0, 1));
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
    _transform->Update();

    _colorBuffer->Update();

}

void RectCollider::Render()
{
    _vs->SetInputLayout();
    _vertexBuffer->SetVertexBuffer(0);

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
    _transform->SetVSSlot(0);
    _colorBuffer->SetPSBuffer(0);
    
    _vs->SetShader();
    _ps->SetShader();

    DC->Draw(_vertices.size(),0);
}

bool RectCollider::IsCollision(const Vector& pos)
{
    if (Left() < pos.x && pos.x < Right()) {
        if (Top() > pos.y && pos.y > Bottom()) {
           
            return true;
        }
    }
    return false;
}

bool RectCollider::IsCollision(shared_ptr<class CircleCollider> circle)
{
    Vector circlePos = circle->GetTransform()->GetWorldLocation();
    Vector rectPos = _transform->GetWorldLocation();
    

    if (abs(circlePos.x - rectPos.x) < _halfSize.x + circle->Radius()) {
        if (abs(circlePos.y - rectPos.y) < _halfSize.y + circle->Radius()) {
            Vector temp = Center() + _halfSize;
            float length = (Center() - circle->GetTransform()->GetWorldLocation()).Length() - circle->Radius() ;
            if(length <= (temp - Center()).Length()){
                return true;
            }
        }
    }
    return false;
}


void RectCollider::CreateVertices()
{
    Vertex temp;
    temp.pos = XMFLOAT3(-_halfSize.x, _halfSize.y, 0.0f);
    _vertices.push_back(temp); // 왼쪽 위

    temp.pos = XMFLOAT3(_halfSize.x, _halfSize.y, 0.0f);
    _vertices.push_back(temp); // 오른쪽 위

    temp.pos = XMFLOAT3(_halfSize.x, -_halfSize.y, 0.0f);
    _vertices.push_back(temp); // 오른쪽 아래

    temp.pos = XMFLOAT3(-_halfSize.x, -_halfSize.y, 0.0f);
    _vertices.push_back(temp); // 왼쪽 아래


    temp.pos = XMFLOAT3(-_halfSize.x, _halfSize.y, 0.0f);
    _vertices.push_back(temp); // 왼쪽 위
    
}
