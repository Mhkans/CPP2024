#include "framework.h"
#include "RectCollider.h"
#include "CircleCollider.h"
#include "Collider.h"
RectCollider::RectCollider(Vector center, Vector size)
	:_halfSize(size*0.5f)
{
    _currType = Collider::Type::RECT;
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

RectCollider::OBB RectCollider::GetOBB()
{
    OBB result;
    result.position = _transform->GetWorldLocation();
    result.length[0] = _halfSize.x * _transform->GetWorldScale().x;
    result.length[1] = _halfSize.y * _transform->GetWorldScale().y;
    
    auto matrix = _transform->GetMatrix();
    result.direction[0] = { matrix.r[0].m128_f32[0],matrix.r[0].m128_f32[1] };
    result.direction[1] = { matrix.r[1].m128_f32[0],matrix.r[1].m128_f32[1] };
    result.direction[0].Normal();
    result.direction[1].Normal();

    return result;
}

bool RectCollider::IsCollision(const Vector& pos)
{
    OBB obb = GetOBB();

    Vector dir1 = pos - obb.position;
    Vector obbDir1 = obb.direction[0];
    float obbLength1 = obb.length[0];
    float dot1 = abs(obbDir1.Dot(dir1));

    Vector obbDir2 = obb.direction[1];
    float obbLength2 = obb.length[1];
    float dot2 = abs(obbDir2.Dot(dir1));
    if (dot1 > obbLength1) {
        return false;
    }
    if (dot2 > obbLength2) {
        return false;
    }
    return true;
}

bool RectCollider::IsCollision(shared_ptr<class CircleCollider> circle)
{
    OBB obb = GetOBB();
    Vector dir = circle->GetTransform()->GetWorldLocation() - obb.position;
    float dot1 = abs(obb.direction[0].Dot(dir));
    if (dot1 > obb.length[0] + circle->Radius()) {
        return false;
    }
    float dot2 = abs(obb.direction[1].Dot(dir));
    if (dot2 > obb.length[1] + circle->Radius()) {
        return false;
    }
    Vector temp = obb.position + obb.direction[0] * obb.length[0] + obb.direction[1] * obb.length[1];
    if (dir.Length() > temp.Length()) {
        return false;
    }
    
    return true;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> rect)
{
    //x축 y축 기준 내적값 < 변의 길이 합 -> true
    //중심 dir 기준 내적값 < dir * len의 내적 합
    OBB a = GetOBB();
    OBB b = rect->GetOBB();

    Vector dir = b.position - a.position;

    Vector aDir0 = a.direction[0];
    Vector aDir1 = a.direction[1];
    Vector bDir0 = b.direction[0];
    Vector bDir1 = b.direction[1];

    float aLen0 = a.length[0];
    float aLen1 = a.length[1];
    float bLen0 = b.length[0];
    float bLen1 = b.length[1];

    float dot1 = abs(aDir0.Dot(bDir0));
    float dot2 = abs(aDir0.Dot(bDir1));
    float dot3 = abs(bDir0.Dot(aDir1));
    float dot4 = abs(bDir1.Dot(aDir1));

    float dirDot1 = abs(aDir0.Dot(dir));
    float dirDot2 = abs(aDir1.Dot(dir));
    float dirDot3 = abs(bDir0.Dot(dir));
    float dirDot4 = abs(bDir1.Dot(dir));

    if (dirDot1 > dot1*bLen0 + dot2*bLen1 + aLen0) {
        return false;
    }
    if (dirDot2 > dot3*bLen0 + dot4*bLen1 + aLen1) {
        return false;
    }
    if (dirDot3 > dot1 * aLen0 + dot3 *aLen1 + bLen0) {
        return false;
    }
    if (dirDot4 > dot2 * aLen0 + dot4*aLen1 + bLen1) {
        return false;
    }

    return true;
}


int RectCollider::Block(shared_ptr<RectCollider> other)
{
    if (!IsCollision(other)) {
        return -1;
    }
    OBB a = GetOBB();
    OBB b = other->GetOBB();

    Vector gap;
    gap.x = (a.length[0] + b.length[0]) - abs(a.position.x - b.position.x) + 0.001f;
    gap.y = (a.length[1] + b.length[1]) - abs(a.position.y - b.position.y) + 0.001f;

    //상속된 collider에 Block X
    if (gap.x > gap.y){
        if (b.position.y < a.position.y){
            other->GetTransform()->AddLocalLocation(Vector(0, -gap.y));
            return 0;
        }
        else{
            other->GetTransform()->AddLocalLocation(Vector(0, gap.y));
            return 1;
        }
    }
    // gap의 x 값이 더 작음
    if (b.position.x < a.position.x){
        other->GetTransform()->AddLocalLocation(Vector(-gap.x, 0));
    }
    else{
        other->GetTransform()->AddLocalLocation(Vector(gap.x, 0));
    }

    return 0;
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
