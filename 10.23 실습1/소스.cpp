#include <stdio.h>

int main(void)
{
	int Number;                                                  // ����� ������� Number�� ǥ���ϰڴ�
	int i;

	printf("������ ����� ������� �Է��Ͻÿ� : ");
	scanf_s("%d", &Number);

	for (i = 1; i <= 9; i++)                                    // 9�� �ݺ��Ͽ� ǥ���ϰڴ�
	{
		printf("%d * %d = %d\n", Number, i, (Number * i));
	}

	return 0;
}