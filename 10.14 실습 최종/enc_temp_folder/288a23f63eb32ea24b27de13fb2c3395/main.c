#include <stdio.h>

int main(void)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	printf("���ϴ� ������ �����Ͻÿ�(1.���� 2.���� 3.���� 4.������ :\n");
	scanf_s("%d", &a);

	printf("��Ģ���� �Է�(����) :\n");
	scanf_s("%d %d, &b, &c");

	if (a == 1)
	{
		printf("%d, b+c");
	}
	else if (a == 2)
	{
		printf("%d, b-c");
	}
	else if (a == 3)
	{
		printf("%d, b*c");
	}
	else if (a == 4)
	{
		d = b / c;
	}

	printf("����� : %d\n", d);

	return 0;
}