/*  �ۼ��� : 2021010507 ȫ����
	���� : Report #2 1�� ���� */

#include <stdio.h>                                          // stdio.h ������ ������ ���α׷� �ȿ� ����

int main(void)
{
	int Number = 0;                                         // �Ǻ��� ���ڸ� Number�� �ϰ�, int�� ���� Number ����

	printf("�Ǻ��� ���ڸ� �Է��Ͻÿ� : ");                  // "�Ǻ��� ���ڸ� �Է��Ͻÿ� : "�� ���
	scanf_s("%d", &Number);                                 // �Ǻ��� ���� Number�� �Է� �޴´�

	Number = Number % 2;                                    // Ȧ��, ¦���� �����ϱ� ���� Number % 2�� ������� Number�� ����

	switch (Number)                                         // Number�� ���� ������ Ȯ��
	{
	case 0:                                                 // Number�� 0�̸�, �� �Ǻ��� ���ڰ� ¦���̸�
		printf(" �ش� ���ڴ� ¦���̴�.\n");                 // " �ش� ���ڴ� ¦���̴�."�� ���
		break;

	default:                                                // Number�� 0�� �ƴϸ�, �� �Ǻ��� ���ڰ� Ȧ���̸�
		printf(" �ش� ���ڴ� Ȧ���̴�.\n");                 // " �ش� ���ڴ� Ȧ���̴�."�� ���
		break;
	}

	return 0;                                               // ���α׷� ����
}