#include "framework.h"


bool RectCollider::isAABB(RectCollider* rect, Vector2* overwrap)
// Axis-Aligned Bounding Box = 축이 나란한 경계상자의 줄임말
// 충돌판정을 이루는 모든 상자의 변들이 기본 축과 평행하도록 만들어진 경우 사용하는 알고리즘
// 기본적으로 "매우 빠르다"라는 것이 최대 장점
{
    // AABB의 핵심은 "충돌하는 영역이 실존하는지를 계산할 수 있어야 한다"는 것
    // 그 계산을 위해, 충돌판정이 존재한다고 가정했을 때 필요한 데이터 : 
    // 두 사각형의 좌표를 통해 만들어질 수 있는 가장 작은 사각형의 상하좌우 좌표 데이터

    // 아래의 4개 코드는 그 영역의 좌표를 계산하는데 필요한 데이터를 구축하는 것
    float min_right = min(RightVX(), rect->RightVX());
    float max_left = max(LeftVX(), rect->LeftVX());
    float min_bottom = min(BottomVX(), rect->BottomVX());
    float max_top = max(TopVX(), rect->TopVX());

    // 구축이 완료됐다면 이를 통해 이론상 존재해야 할 충돌범위의 크기를 구함
    Vector2 obstackle = Vector2(min_right - max_left, min_bottom - max_top);

    // 그렇게 구한 영역의 크기가 가로, 세로,(3D였다면) 높이 전부 양수인지 체크
    if (obstackle.x > 0 && obstackle.y > 0) // 전부 양수였다면 충돌영역이 실존
    {
        if (overwrap != NULL)
            *overwrap = obstackle; // 충돌영역의 크기가 필요할 떄를 대비해 이 크기를 반환
        return true; // = 충돌한 것이다
    }
    else
        return false;

    // 이 알고리즘 최대의 문제점은 "회전"이 고려되어있지 않다는 것
    // 따라서 실제 오브젝트가 회전했다 하더라도, 그에 맞게 데이터를 재구성하는 것이 불가능

    // 그래서 회전한 경우를 대비해 다른 충돌판정 알고리즘을 사용하는 것
    // OBB 알고리즘이 그 용도로 채택된 것
}

bool RectCollider::isAABB(class CircleCollider* circle, Vector2* overwrap)
{

    return false;
}

bool RectCollider::isOBB(RectCollider* rect)
// Oriented Bounding Box - 지향성 경계 상자 알고리즘
// 회전방향을 따라가는 충돌판정 처리법

// 글로서 간단히 정리하자면 :
// 두 물체를 어떤 축에 "투영"(혹은 "사영")시켰을 때
// 투영된 두 물체가 서로 겹치지 않는다면
// 두 물체를 가로질러서 서로를 공간상에서 분리시킬 수 있는 선(혹은 면)이 존재한다고 확정할 수 있음
// 이를 분리축이라 칭했을 때, 
// 그런 분리축이 가능한 많은 축에 사영했을 때 단 하나도 발견되지 않는다면
// 이 두 물체는 분리축이 없다 = 분리가 불가능하다 = 충돌했다는 결론을 내릴 수 있고,
// 하나라도 발견된다면 둘이 분리가 가능하다는 이야기니 충돌하지 않았다는 결론을 내릴 수 있음
// 따라서 그 분리축이 있는지 없는지를 검사하는 알고리즘
{
    ObbDesc this_obb = GetObbDesc();
    // 내 충돌판정이 투영할 떄 사용할, 현 시점에서의 회전 등이 적용된 충돌판정 데이터를 생성
    
    ObbDesc rect_obb = rect->GetObbDesc();
    // 상대방의 데이터도 마찬가지로 가져오기

    // 두 충돌판정이 얼마나 회전했든, 그 충돌판정의 트랜스폼 자체가 가리키는 위와 오른쪽을
    // 해당 정보를 관리하는 인스턴스를 만들어서 거기서 접근할 수 있도록 만드는 작업

    Vector2 nea1 = this_obb.Axis[0];
    Vector2 nea2 = this_obb.Axis[1];
    Vector2 ea1 = nea1 * this_obb.half_size.x;
    Vector2 ea2 = nea2 * this_obb.half_size.y;
    // 두 사각형을 투영할 축을 만들 떄 필요한 정보들을
    // 위의 ObbDesc에서 만들어진 회전이 반영된 충돌판정을 이용해 작성

    Vector2 neb1 = rect_obb.Axis[0];
    Vector2 neb2 = rect_obb.Axis[1];
    Vector2 eb1 = neb1 * rect_obb.half_size.x;
    Vector2 eb2 = neb2 * rect_obb.half_size.y;
    // 상대방 측의 축을 만들 때 필요한 정보도 마찬가지로 생성

    Vector2 distance = this_obb.pos - rect_obb.pos;
    // 두 충돌판정 사이의 거리를 저장

    // A : 나 자신, B : 상대 충돌판정
    float lengthA; // 충돌판정 A에서 검사할 축에 사영한 그림자의 길이
    float lengthB; //    ''   B             ''
    float length;  // 두 사각형의 중심 사이에 그러진 선분을 검사할 축에 사영한 그림자의 길이

    // 앞으로, 두 충돌판정들이 각각 가지고 있는 오른쪽, 위를 가리키는 2개의 방향 벡터를
    // 사영할 축으로 이용할 것
    // 그렇게 총 4개의 축을 기준으로 각각에 사영했을 때 분리축이 존재하는지를 검증

    // 테스트축 : nea1(A.Right())
    lengthA = ea1.GetLength();
    // 이 벡터는 현재 테스트하고 있는 기준축이 되는 방향 벡터와 평행하므로,
    // 이 벡터를 해당 기준축에 사영한다 해도 그림지의 길이는 원본과 동일
    // 따라서 해당 축과 동일한 방향의 원본인 벡터의 길이를 그대로 입력하면 됨
    // 당연히, 이 축과 수직인 이 사각형의 다른 벡터는 반영할 필요가 없다

    lengthB = separateAxis(nea1, eb1, eb2);
    // 상대방 측에서 사영한 총 길이를 위 함수를 통해 계산해 저장

    length = abs(Vector2::Dot(distance, nea1));
    // 내적을 이용해 두 사각형 사이를 잇는 선분(=전체 선분)을 사영한 거리를 저장

    if (length > lengthA + lengthB) // 그렇게 구한 값을 통해,
        // 두 그림자의 길이의 합이 전체 선분의 그림자의 길이보다 작다면
        return false; // 분리축이 통과할 수 있는 범위가 존재 = 분리축이 있다고 확신할 수 있음
        // = 둘은 충돌하지 않고 있다
    
    // 여기를 통과했다 = 이 축에서는 분리축이 확인되지 않았다면
    // 나머지 3개의 분리축에도 똑같은 작업을 수행

    // 분리축(=테스트축) : nea2(A.Up)
    lengthA = ea2.GetLength();
    lengthB = separateAxis(nea2, eb1, eb2);

    length = abs(Vector2::Dot(distance, nea2));

    if (length > lengthA + lengthB)
        return false;

    // 분리축(=테스트축) : neb1(B.Right)
    lengthA = eb1.GetLength();
    lengthB = separateAxis(neb1, ea1, ea2);

    length = abs(Vector2::Dot(distance, neb1));

    if (length > lengthA + lengthB)
        return false;

    // 분리축(=테스트축) : neb2(B.Up)
    lengthA = eb2.GetLength();
    lengthB = separateAxis(neb2, ea1, ea2);

    length = abs(Vector2::Dot(distance, neb2));

    if (length > lengthA + lengthB)
        return false;

    // 여기까지를 전부 통과했다면 = 분리축의 존재여부를 증명하지 못했다면
    return true; // 분리축이 없다고 봐도 된다는 이야기니 이 둘은 충돌해있다
}

bool RectCollider::isOBB(CircleCollider* circle)
{
    return false;
}

float RectCollider::separateAxis(Vector2 seperate, Vector2 e1, Vector2 e2)
// 현재 테스트하고 있는 축을 이용해,
// 해당 축을 사용하지 않는 상대측 판정범위에서 만들어지는 두 벡터를
// 이 축을 기준선으로 "사영"했을 때 만들어지는 길이를 측정하는 함수
{
    float r1 = abs(Vector2::Dot(seperate, e1));
    float r2 = abs(Vector2::Dot(seperate, e2));
    // seperate라는, 현재 축을 만드는 방향을 가리키는 단위 벡터를 기준으로 하여
    // e1, e2라는 각각의 벡터가 해당 축이 가리키는 방향 기준으로 얼마만큼의 좌표(=값)를 가지나
    // 벡터의 내적을 통해 계산한 것
    // 값이 양수가 될 수도 있고 음수가 될 수도 있지만,
    // 지금은 방향까지 포함한 값이 아닌 순수란 길이만을 필요로 하므로 절대값을 통해 길이만 추출

    return r1 + r2;
    // e1, e2는 각각 상대 측의 벡터 2개를 이용해 만들어진 벡터들이므로
    // 상대방 측에서 사영한 총 길이는 이 둘의 합이 되니 이를 반환

    return 0.0f;
}

RectCollider::RectCollider(Vector2 size)
    : size(size)
{
    type = TYPE::RECT;

    CreateLine();
}

void RectCollider::CreateLine()
{
    Vector2 half = size * 0.5f;

    vertices.emplace_back(-half.x, +half.y);
    vertices.emplace_back(+half.x, +half.y);
    vertices.emplace_back(+half.x, -half.y);
    vertices.emplace_back(-half.x, -half.y);
    vertices.emplace_back(-half.x, +half.y);

    VB = new VertexBuffer(vertices.data(), sizeof(VertexPos), vertices.size());
}

RectCollider::~RectCollider()
{
    delete VB;
}

RectCollider::ObbDesc RectCollider::GetObbDesc()
// 회전된 상태에서의 충돌판정의 범위를 정의하기 위해 필요한 데이터를 모아둔 구조체를
// 즉석에서 계산하여 반환하는 함수
{
    // 이를 표현하기 위해 필요한 데이터는 총 4개

    obb_desc.pos = GlobalPos(); // 1. 지금 이 충돌판정의 위치(=중앙점)
    obb_desc.half_size = Size() * 0.5f; // 2. 충돌판정의 크기(=좌우 및 상하 크기의 절반)

    obb_desc.Axis[0] = Right();
    obb_desc.Axis[1] = Up();
    // 3,4. 이 충돌판정이 현재 보는 방향을 기준으로 오른쪽/위쪽을 가리키는 단위 방향 벡터

    return obb_desc;
}

bool RectCollider::isPointCollision(Vector2 point)
{
    /*
    계산방법 :
    1. 이 사각형의 범위,
    즉 x축과 y축 각각에서 시작점과 종료점을 잡음

    2. 입력받은 점이 그 x,y 각각의 범위 안에 둘 다 들어가는지 검사,
    둘 다 들어갔다면 내부에 있다 = 충돌했다
    둘 중 하나라도 범위 밖이라면 외부에 있다 = 충돌하지 않았다
    */

    Vector2 half = Size() * 0.5f;

    float left = GlobalPos().x - half.x;
    float right = GlobalPos().x + half.x;
    float top = GlobalPos().y - half.y;
    float bottom = GlobalPos().y + half.y;


    if (point.x > left && point.x < right)
        if (point.y > top && point.y < bottom)
            return true;

    return false;
}

bool RectCollider::isCircleCollision(class CircleCollider* collider)
{
    return false;
}

bool RectCollider::isRectCollision(RectCollider* collider, Vector2* overwrap)
{
    /*
    * 먼저 엉터리 알고리즘을 하나 만들어본 뒤
    * AABB 알고리즘을 만들고
    * OBB 알고리즘까지 만들어서
    각각의 알고리즘을 시험해볼 것
    
    */
    /*
    Vector2 half = Size() * 0.5f;

    float left = GlobalPos().x - half.x;
    float right = GlobalPos().x + half.x;
    float top = GlobalPos().y - half.y;
    float bottom = GlobalPos().y + half.y;
    // 나 자신의 좌표를 구하는 과정

    half = collider->Size() * 0.5f;

    float desc_left = collider->GlobalPos().x - half.x;
    float desc_right = collider->GlobalPos().x + half.x;
    float desc_top = collider->GlobalPos().y - half.y;
    float desc_bottom = collider->GlobalPos().y + half.y;
    // 상대방의 좌표들 = 꼭지점의 좌표를 구하는 데 필요한 데이터를 계산하는 과정

    // 두 사각형이 가진 각각의 꼭지점들 중
    // 단 하나라도 상대방의 내부에 들어가있다면 = 점충돌이 일어났다면
    // 확정적으로 충돌하고 있다는 이야기가 됨

    if (collider->isPointCollision(Vector2(left, top))
        || collider->isPointCollision(Vector2(left, bottom))
        || collider->isPointCollision(Vector2(right, top))
        || collider->isPointCollision(Vector2(right, bottom))
        || isPointCollision(Vector2(desc_left, desc_top))
        || isPointCollision(Vector2(desc_left, desc_bottom))
        || isPointCollision(Vector2(desc_right, desc_top))
        || isPointCollision(Vector2(desc_right, desc_bottom)))
        return true;
    else
        return false;
    
    이런 식으로 만들면 아이디어 자체는 간단해서 쉽게 떠올리고 만들 수 있지만,
    무조건 8번 검사를 해야 한다는 점에서 비효율적인 건 둘째치고,
    꼭지점이 상대방에게 단 하나도 들어가지 않고도 겹칠 수 있다는 것이 고려되지 않은 알고리즘

    이 외에 우리가 직접 알고리즘을 구상한다 했을 때, 그게 제대로 작동하는 것인지 아닌지
    검증하게 될 경우엔 그 자체에 시간을 너무 많이 쓰게 됨
    (특히, 수학의 영역을 건드려야 하기 때문에 난이도도 매우 높다)

    그래서 우리는 직접 구상하는 게 아니라
    이미 성능과 효율성이 검증된 앓고리즘들을 사용하는 것

    */

    //if (overwrap != NULL)
    //    return isAABB(collider, overwrap);
    //else
        return isOBB(collider);
}
