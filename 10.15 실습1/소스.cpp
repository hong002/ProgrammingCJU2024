#include <stdio.h>

int main(void)
{
	int a = 0;
	int b = 0;
	int c = 0;

	printf("���ϴ� ������ �����Ͻÿ� (1.���� 2.���� 3.���� 4.������) :\n");
	scanf_s("%d", &a);

	printf("��Ģ���� �Է�(����) :\n");
	scanf_s("%d %d", &b, &c);

	switch (a)
	{
	case 1:
		printf("����� : %d\n", b + c);
		break;

	case 2:
		printf("����� : %d\n", b - c);
		break;

	case 3:
		printf("����� : %d\n", b * c);
		break;

	default:
		printf("����� : %d\n", b / c);
		break;
	}

	return 0;
}