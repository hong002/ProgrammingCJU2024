/*  �ۼ��� : 2021010507 ȫ����
	���� : Report #2 1�� ���� */

#include <stdio.h>                                          // stdio.h ������ ������ ���α׷� �ȿ� ����

int main(void)
{
	int Number = 0;                                         // �Ǻ��� ���ڸ� Number�� �ϰ�, int�� ���� Number ����

	printf("�Ǻ��� ���ڸ� �Է��Ͻÿ� : ");                  // "�Ǻ��� ���ڸ� �Է��Ͻÿ� : "�� ���
	scanf_s("%d", &Number);                                 // �Ǻ��� ���� Number�� �Է� �޴´�

	Number = Number % 2;

	switch (Number)
	{
	case 0:
		printf(" �ش� ���ڴ� ¦���̴�.\n");
		break;

	default:
		printf(" �ش� ���ڴ� Ȧ���̴�.\n");
		break;
	}

	return 0;                                               // ���α׷� ����
}