#include "framework.h"
#include "CircleCollider.h"
#include "RectCollider.h"
CircleCollider::CircleCollider(Vector center, float radius)
    :_radius(radius)
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

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Update()
{
    _transform->Update();

     _colorBuffer->Update();
}

void CircleCollider::Render()
{
    _vs->SetInputLayout();
    _vertexBuffer->SetVertexBuffer(0);

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
    _transform->SetVSSlot(0);
    _colorBuffer->SetPSBuffer(0);

    _vs->SetShader();
    _ps->SetShader();

    DC->Draw(_vertices.size(), 0);
}

bool CircleCollider::IsCollision(const Vector& pos)
{
    return (pos - Center()).Length() < Radius();
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> rect)
{
    return rect->IsCollision(shared_from_this());
}
bool CircleCollider::IsCollision(shared_ptr<CircleCollider> circle)
{
    float length1 = (Center() - circle->GetTransform()->GetWorldLocation()).Length();
    float length2 = _radius + circle->Radius();
    return length1 <= length2;
}
void CircleCollider::CreateVertices()
{
    for (int i = 0; i <= vCount; i++)
    {
        float setAngle = i * angle;
        float x = _radius * cos(setAngle);
        float y = _radius * sin(setAngle);

        Vertex temp;
        temp.pos = XMFLOAT3(x, y, 0.0f);
        _vertices.push_back(temp);
    }
}
