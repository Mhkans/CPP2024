cbuffer world : register(b0)
{
	matrix world;
}
cbuffer view : register(b1)
{
	matrix view;
}
cbuffer projection : register(b2)
{
	matrix projection;
}

struct VertexInput
{
	float4 pos : POSITION;
	float4 uv : UV;
};
struct PixelInput
{
	float4 position : SV_Position;
	float4 uv : UV;
};
/*
UV : ���� ����ϰ� �ִ� �ؽ��Ŀ��� � ������ �ִ� �����͸� ������ �������� �����ϴ�,
	 �ؽ��� �ȿ����� ��ǥ
�ؽ���(Texture = ����) : � ��ü�� ǥ���� ������ �ִ� ����
						�׷��ȿ����� � ������Ʈ�� ǥ���� �� ����ϴ� ������
						(2D�� ��쿣 ����ϴ� �� ����ϴ� �̹���,
						 3D�� ��쿣 �ϴ� ���밡 ������� ���� ǥ�鿡 � ���� ���� �������� �����ϴ� ������)

3D�� 2D�� ����ϰ��� �ϴ� �������� ����� �������� � ��ġ�� �ִ� ������ �̿��� �������� �����ؾ� �ϸ�,
�� ������δ� �� �����Ϳ� ����Ǿ� �ִ� �ڷ�� �� ����ϰ��� �ϴ� "��ġ"�� �ִ� ���� Ȯ���� �� �ֵ���
�ؽ��� �󿡼��� ��ǥ�� ������� ��

�׷� �뵵�� ���Ǵ�, X/Y/Z ���� ���� ������ ���еǴ� �ؽ�ó �󿡼��� ��ǥ�� ������� �ϸ�,
�� �뵵�� �ؽ��� �󿡼��� X/Y/Z ��ǥ�� �̿��ϴ� ���� U/V/W��� ��
��, �� ������Ʈ�� 3D�� �ƴ� 2D�� ����ϴ� �̹����� 2D �̹����̹Ƿ� W���� ������� �ʰ� 
UV���� �̿��ϴ� ��

�⺻������, ������ �����Ϳ��� ���� �� ���κп� �ִ� �������� ��ġ�� 0,0���� ����ϸ�
������ �Ʒ� ���� 1,1���� �����
������ ���� �������� ��� ��ǥ


*/

PixelInput main(VertexInput input)
{
	PixelInput output;
	output.position = mul(input.pos, world);
	output.position = mul(output.position, view);
	output.position = mul(output.position, projection);
	
	output.uv = input.uv;
	
	return output;
}