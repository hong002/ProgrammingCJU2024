#include <stdio.h>

int main(void)
{
	int a;                                                  // ����� ������� Number�� ǥ���ϰڴ�
	int i, j;

	printf("������ ����� ������� �Է��Ͻÿ� : ");
	scanf_s("%d", &a);

	switch (a)
	{
	case 10:
		for (i = 1; i <= 9; i++)                                    // 9�� �ݺ��Ͽ� ǥ���ϰڴ�
		{
			for (j = 1; j <= 9; j++)
			{
				printf("%d * %d = %2d\n", j, i, (j * i));
			}
			printf("\n");
		}
		break;
	default :
		for (i = 1; i <= 9; i++)
		{
			printf("%d * %d = %d\n", a, i, (a * i));
		}
		break;
	}

	return 0;
}