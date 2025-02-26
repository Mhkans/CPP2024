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
// cbuffer(= Construct Buffer = ��� ����) 3���� �����ϰ�,
// �� 3�� ���۵��� ������ ���Կ� ����Ѵٴ� �ڵ�
// �� ������ ���ۿ� 4X4 ũ���� ����� ���־,
// ���� W, V, P ��ȯ�� ���� C++ �ʿ��� �޾ƿ;� �ϴ� ����/����/���� ��ȯ ����� ��ϵǾ��ִ� ������

// World��� �ϴ�, world ����� �����ϴ� ��� ���۴� b0��� "����"�� ����ؼ� �� ������ ���� �����͸� �Է¹ްڴ�
// ���� ������ b1���� view ����� view��,
// b2���� projection ����� projection�� �����ϵ��� ������ ��Ī�����ִ� ��
// �׷��� �ϸ� C++ �ʿ��� �ش� �������� �����͸� ���� ��� ���� ���ǵǾ��ִ� ������ ��Ŀ� �˾Ƽ� �����Ͱ� ���õȴ�


struct VertexInput
{
	float4 pos : POSITION;
	float4 color : COLOR;
};
struct PixelInput
{
	float4 position : SV_Position;
	float4 color : COLOR;
};

PixelInput main(VertexInput input)
{
	PixelInput output;
	output.position = mul(input.pos, world);
	output.position = mul(output.position, view);
	output.position = mul(output.position, projection);
	// mul : HLSL���� �����ϴ� ��� * ��� �� ������ �������ִ� �����
	// ��Ȯ���� ���� * ��ĵ� �����ϰ�, ������ ���� �̰͵� pos�̶�� ���Ͱ��� ��Ŀ� ���ϴ� ���̱⵵ ��
	
	// �� 3���� ���� World ��ȯ / View ��ȯ / Projection ��ȯ�� ����ϴ� �ڵ�
	// -> WVP ��ȯ�� ������Ʈ�� ������ �ִ� ��ǥ�� ����/��/�������� ������ ���ϴ� �ܰ�
	
	output.color = input.color;
	
	return output;
}