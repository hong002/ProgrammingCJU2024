#include <stdio.h>

int main(void)
{
	int Number1, Number2;                                                     // �Է��� �ΰ��� ���ڸ� ���� Number1, Number2�� �Ѵ�
	int Result1, Result2 = 0;                                                 // �ִ������� Result1, �ּҰ������ Result2�� �Ѵ�
	int i;

	printf("�ִ�����, �ּҰ������ ���� �ΰ��� ���ڸ� �Է��Ͻÿ� : ");
	scanf_s("%d %d", &Number1, &Number2);

	i = 2;                                                                    // i�� 2���� �����Ѵ�

	do
	{
		if (Number1 % i == 0 && Number2 % i == 0)                             // �� ���� ����� �� �� ������ �������� ������̴�
			Result1 = i;
		i = i++;
		break;
	} while (i <= Number1 && i <= Number2);                                   // i�� �� ���ں��� ���ų� ������ i�� 1�� ������Ű�鼭 ������� ã�´�

	Result2 = Number1 * Number2 / Result1;                                    // �� ���ڸ� ���� ���� �ִ������� ������ �ּҰ������ ���Ѵ�

	printf(" %d�� %d�� �ִ������� %d�̴�.\n", Number1, Number2, Result1);
	printf(" %d�� %d�� �ּҰ������ %d�̴�.\n", Number1, Number2, Result2);

	return 0;
}