#include <stdio.h>

int main(void)
{
	int Number;                                                  // ����� ������� Number�� ǥ���ϰڴ�
	int i, j;

	printf("������ ����� ������� �Է��Ͻÿ� : ");
	scanf_s("%d", &Number);

	for (i = 1; i <= 9; i++)                                    // 9�� �ݺ��Ͽ� ǥ���ϰڴ�
	{
		for (j = 1; j <= 9; j++)
		{
			printf("%d * %d = %2d\n", j, i, (j * i));
		}
		printf("\n");
	}

	return 0;
}