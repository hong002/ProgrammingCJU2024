/*  �ۼ��� : 2021010507 ȫ����
	���� : Report #2 1�� ���� */

#include <stdio.h>                                          // stdio.h ������ ������ ���α׷� �ȿ� ����

int main(void)                                              
{
	int Number = 0;                                         // �Ǻ��� ���ڸ� Number�� �ϰ�, int�� ���� Number ����

	printf("�Ǻ��� ���ڸ� �Է��Ͻÿ� : ");                  // "�Ǻ��� ���ڸ� �Է��Ͻÿ� : "�� ���
	scanf_s("%d", &Number);                                 // �Ǻ��� ���� Number�� �Է� �޴´�

	if (Number % 2 == 0)                                    // �Ǻ��� ���ڰ� ¦���� ���
	{
		printf(" %d�� ¦���̴�.\n", Number);                // %d �ڸ��� Number�� �ְ� " %d�� ¦���̴�." ���
	}
	else                                                    // �Ǻ��� ���ڰ� Ȧ���� ���
	{
		printf(" %d�� Ȧ���̴�.\n", Number);                // %d �ڸ��� Number�� �ְ� " %d�� Ȧ���̴�." ���
	}

	return 0;                                               // ���α׷� ����
}