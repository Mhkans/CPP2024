#include "framework.h"


bool RectCollider::isAABB(RectCollider* rect, Vector2* overwrap)
// Axis-Aligned Bounding Box = ���� ������ �������� ���Ӹ�
// �浹������ �̷�� ��� ������ ������ �⺻ ��� �����ϵ��� ������� ��� ����ϴ� �˰���
// �⺻������ "�ſ� ������"��� ���� �ִ� ����
{
    // AABB�� �ٽ��� "�浹�ϴ� ������ �����ϴ����� ����� �� �־�� �Ѵ�"�� ��
    // �� ����� ����, �浹������ �����Ѵٰ� �������� �� �ʿ��� ������ : 
    // �� �簢���� ��ǥ�� ���� ������� �� �ִ� ���� ���� �簢���� �����¿� ��ǥ ������

    // �Ʒ��� 4�� �ڵ�� �� ������ ��ǥ�� ����ϴµ� �ʿ��� �����͸� �����ϴ� ��
    float min_right = min(RightVX(), rect->RightVX());
    float max_left = max(LeftVX(), rect->LeftVX());
    float min_bottom = min(BottomVX(), rect->BottomVX());
    float max_top = max(TopVX(), rect->TopVX());

    // ������ �Ϸ�ƴٸ� �̸� ���� �̷л� �����ؾ� �� �浹������ ũ�⸦ ����
    Vector2 obstackle = Vector2(min_right - max_left, min_bottom - max_top);

    // �׷��� ���� ������ ũ�Ⱑ ����, ����,(3D���ٸ�) ���� ���� ������� üũ
    if (obstackle.x > 0 && obstackle.y > 0) // ���� ������ٸ� �浹������ ����
    {
        if (overwrap != NULL)
            *overwrap = obstackle; // �浹������ ũ�Ⱑ �ʿ��� ���� ����� �� ũ�⸦ ��ȯ
        return true; // = �浹�� ���̴�
    }
    else
        return false;

    // �� �˰��� �ִ��� �������� "ȸ��"�� ����Ǿ����� �ʴٴ� ��
    // ���� ���� ������Ʈ�� ȸ���ߴ� �ϴ���, �׿� �°� �����͸� �籸���ϴ� ���� �Ұ���

    // �׷��� ȸ���� ��츦 ����� �ٸ� �浹���� �˰����� ����ϴ� ��
    // OBB �˰����� �� �뵵�� ä�õ� ��
}

bool RectCollider::isAABB(class CircleCollider* circle, Vector2* overwrap)
{

    return false;
}

bool RectCollider::isOBB(RectCollider* rect)
// Oriented Bounding Box - ���⼺ ��� ���� �˰���
// ȸ�������� ���󰡴� �浹���� ó����

// �۷μ� ������ �������ڸ� :
// �� ��ü�� � �࿡ "����"(Ȥ�� "�翵")������ ��
// ������ �� ��ü�� ���� ��ġ�� �ʴ´ٸ�
// �� ��ü�� ���������� ���θ� �����󿡼� �и���ų �� �ִ� ��(Ȥ�� ��)�� �����Ѵٰ� Ȯ���� �� ����
// �̸� �и����̶� Ī���� ��, 
// �׷� �и����� ������ ���� �࿡ �翵���� �� �� �ϳ��� �߰ߵ��� �ʴ´ٸ�
// �� �� ��ü�� �и����� ���� = �и��� �Ұ����ϴ� = �浹�ߴٴ� ����� ���� �� �ְ�,
// �ϳ��� �߰ߵȴٸ� ���� �и��� �����ϴٴ� �̾߱�� �浹���� �ʾҴٴ� ����� ���� �� ����
// ���� �� �и����� �ִ��� �������� �˻��ϴ� �˰���
{
    ObbDesc this_obb = GetObbDesc();
    // �� �浹������ ������ �� �����, �� ���������� ȸ�� ���� ����� �浹���� �����͸� ����
    
    ObbDesc rect_obb = rect->GetObbDesc();
    // ������ �����͵� ���������� ��������

    // �� �浹������ �󸶳� ȸ���ߵ�, �� �浹������ Ʈ������ ��ü�� ����Ű�� ���� ��������
    // �ش� ������ �����ϴ� �ν��Ͻ��� ���� �ű⼭ ������ �� �ֵ��� ����� �۾�

    Vector2 nea1 = this_obb.Axis[0];
    Vector2 nea2 = this_obb.Axis[1];
    Vector2 ea1 = nea1 * this_obb.half_size.x;
    Vector2 ea2 = nea2 * this_obb.half_size.y;
    // �� �簢���� ������ ���� ���� �� �ʿ��� ��������
    // ���� ObbDesc���� ������� ȸ���� �ݿ��� �浹������ �̿��� �ۼ�

    Vector2 neb1 = rect_obb.Axis[0];
    Vector2 neb2 = rect_obb.Axis[1];
    Vector2 eb1 = neb1 * rect_obb.half_size.x;
    Vector2 eb2 = neb2 * rect_obb.half_size.y;
    // ���� ���� ���� ���� �� �ʿ��� ������ ���������� ����

    Vector2 distance = this_obb.pos - rect_obb.pos;
    // �� �浹���� ������ �Ÿ��� ����

    // A : �� �ڽ�, B : ��� �浹����
    float lengthA; // �浹���� A���� �˻��� �࿡ �翵�� �׸����� ����
    float lengthB; //    ''   B             ''
    float length;  // �� �簢���� �߽� ���̿� �׷��� ������ �˻��� �࿡ �翵�� �׸����� ����

    // ������, �� �浹�������� ���� ������ �ִ� ������, ���� ����Ű�� 2���� ���� ���͸�
    // �翵�� ������ �̿��� ��
    // �׷��� �� 4���� ���� �������� ������ �翵���� �� �и����� �����ϴ����� ����

    // �׽�Ʈ�� : nea1(A.Right())
    lengthA = ea1.GetLength();
    // �� ���ʹ� ���� �׽�Ʈ�ϰ� �ִ� �������� �Ǵ� ���� ���Ϳ� �����ϹǷ�,
    // �� ���͸� �ش� �����࿡ �翵�Ѵ� �ص� �׸����� ���̴� ������ ����
    // ���� �ش� ��� ������ ������ ������ ������ ���̸� �״�� �Է��ϸ� ��
    // �翬��, �� ��� ������ �� �簢���� �ٸ� ���ʹ� �ݿ��� �ʿ䰡 ����

    lengthB = separateAxis(nea1, eb1, eb2);
    // ���� ������ �翵�� �� ���̸� �� �Լ��� ���� ����� ����

    length = abs(Vector2::Dot(distance, nea1));
    // ������ �̿��� �� �簢�� ���̸� �մ� ����(=��ü ����)�� �翵�� �Ÿ��� ����

    if (length > lengthA + lengthB) // �׷��� ���� ���� ����,
        // �� �׸����� ������ ���� ��ü ������ �׸����� ���̺��� �۴ٸ�
        return false; // �и����� ����� �� �ִ� ������ ���� = �и����� �ִٰ� Ȯ���� �� ����
        // = ���� �浹���� �ʰ� �ִ�
    
    // ���⸦ ����ߴ� = �� �࿡���� �и����� Ȯ�ε��� �ʾҴٸ�
    // ������ 3���� �и��࿡�� �Ȱ��� �۾��� ����

    // �и���(=�׽�Ʈ��) : nea2(A.Up)
    lengthA = ea2.GetLength();
    lengthB = separateAxis(nea2, eb1, eb2);

    length = abs(Vector2::Dot(distance, nea2));

    if (length > lengthA + lengthB)
        return false;

    // �и���(=�׽�Ʈ��) : neb1(B.Right)
    lengthA = eb1.GetLength();
    lengthB = separateAxis(neb1, ea1, ea2);

    length = abs(Vector2::Dot(distance, neb1));

    if (length > lengthA + lengthB)
        return false;

    // �и���(=�׽�Ʈ��) : neb2(B.Up)
    lengthA = eb2.GetLength();
    lengthB = separateAxis(neb2, ea1, ea2);

    length = abs(Vector2::Dot(distance, neb2));

    if (length > lengthA + lengthB)
        return false;

    // ��������� ���� ����ߴٸ� = �и����� ���翩�θ� �������� ���ߴٸ�
    return true; // �и����� ���ٰ� ���� �ȴٴ� �̾߱�� �� ���� �浹���ִ�
}

bool RectCollider::isOBB(CircleCollider* circle)
{
    return false;
}

float RectCollider::separateAxis(Vector2 seperate, Vector2 e1, Vector2 e2)
// ���� �׽�Ʈ�ϰ� �ִ� ���� �̿���,
// �ش� ���� ������� �ʴ� ����� ������������ ��������� �� ���͸�
// �� ���� ���ؼ����� "�翵"���� �� ��������� ���̸� �����ϴ� �Լ�
{
    float r1 = abs(Vector2::Dot(seperate, e1));
    float r2 = abs(Vector2::Dot(seperate, e2));
    // seperate���, ���� ���� ����� ������ ����Ű�� ���� ���͸� �������� �Ͽ�
    // e1, e2��� ������ ���Ͱ� �ش� ���� ����Ű�� ���� �������� �󸶸�ŭ�� ��ǥ(=��)�� ������
    // ������ ������ ���� ����� ��
    // ���� ����� �� ���� �ְ� ������ �� ���� ������,
    // ������ ������� ������ ���� �ƴ� ������ ���̸��� �ʿ�� �ϹǷ� ���밪�� ���� ���̸� ����

    return r1 + r2;
    // e1, e2�� ���� ��� ���� ���� 2���� �̿��� ������� ���͵��̹Ƿ�
    // ���� ������ �翵�� �� ���̴� �� ���� ���� �Ǵ� �̸� ��ȯ

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
// ȸ���� ���¿����� �浹������ ������ �����ϱ� ���� �ʿ��� �����͸� ��Ƶ� ����ü��
// �Ｎ���� ����Ͽ� ��ȯ�ϴ� �Լ�
{
    // �̸� ǥ���ϱ� ���� �ʿ��� �����ʹ� �� 4��

    obb_desc.pos = GlobalPos(); // 1. ���� �� �浹������ ��ġ(=�߾���)
    obb_desc.half_size = Size() * 0.5f; // 2. �浹������ ũ��(=�¿� �� ���� ũ���� ����)

    obb_desc.Axis[0] = Right();
    obb_desc.Axis[1] = Up();
    // 3,4. �� �浹������ ���� ���� ������ �������� ������/������ ����Ű�� ���� ���� ����

    return obb_desc;
}

bool RectCollider::isPointCollision(Vector2 point)
{
    /*
    ����� :
    1. �� �簢���� ����,
    �� x��� y�� �������� �������� �������� ����

    2. �Է¹��� ���� �� x,y ������ ���� �ȿ� �� �� ������ �˻�,
    �� �� ���ٸ� ���ο� �ִ� = �浹�ߴ�
    �� �� �ϳ��� ���� ���̶�� �ܺο� �ִ� = �浹���� �ʾҴ�
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
    * ���� ���͸� �˰����� �ϳ� ���� ��
    * AABB �˰����� �����
    * OBB �˰������ ����
    ������ �˰����� �����غ� ��
    
    */
    /*
    Vector2 half = Size() * 0.5f;

    float left = GlobalPos().x - half.x;
    float right = GlobalPos().x + half.x;
    float top = GlobalPos().y - half.y;
    float bottom = GlobalPos().y + half.y;
    // �� �ڽ��� ��ǥ�� ���ϴ� ����

    half = collider->Size() * 0.5f;

    float desc_left = collider->GlobalPos().x - half.x;
    float desc_right = collider->GlobalPos().x + half.x;
    float desc_top = collider->GlobalPos().y - half.y;
    float desc_bottom = collider->GlobalPos().y + half.y;
    // ������ ��ǥ�� = �������� ��ǥ�� ���ϴ� �� �ʿ��� �����͸� ����ϴ� ����

    // �� �簢���� ���� ������ �������� ��
    // �� �ϳ��� ������ ���ο� ���ִٸ� = ���浹�� �Ͼ�ٸ�
    // Ȯ�������� �浹�ϰ� �ִٴ� �̾߱Ⱑ ��

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
    
    �̷� ������ ����� ���̵�� ��ü�� �����ؼ� ���� ���ø��� ���� �� ������,
    ������ 8�� �˻縦 �ؾ� �Ѵٴ� ������ ��ȿ������ �� ��°ġ��,
    �������� ���濡�� �� �ϳ��� ���� �ʰ� ��ĥ �� �ִٴ� ���� ������� ���� �˰���

    �� �ܿ� �츮�� ���� �˰����� �����Ѵ� ���� ��, �װ� ����� �۵��ϴ� ������ �ƴ���
    �����ϰ� �� ��쿣 �� ��ü�� �ð��� �ʹ� ���� ���� ��
    (Ư��, ������ ������ �ǵ���� �ϱ� ������ ���̵��� �ſ� ����)

    �׷��� �츮�� ���� �����ϴ� �� �ƴ϶�
    �̹� ���ɰ� ȿ������ ������ �ΰ������ ����ϴ� ��

    */

    //if (overwrap != NULL)
    //    return isAABB(collider, overwrap);
    //else
        return isOBB(collider);
}
