cbuffer Color : register(b0)
{
	float4 color;
}
// VS �ʰ� ���������� ������۸� 0�� �������� �޾Ƶ��̵��� ����

struct PixelInput
{
	float4 position : SV_Position;
	float4 color : COLOR;
};

float4 main(PixelInput input) : SV_TARGET
{
	return input.color * color;
	// ������ ������ ���� �޾ƿ� ���� ���۸� �״�� �Է¹��� �������� ���� ������
	// �̸� ���� ������ ������ �ִ� ���� �߰��� ���۰� ������ �ִ� ���� �����Ͽ� ȭ�鿡 ����ϵ��� ��
	
}