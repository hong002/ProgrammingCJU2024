/*  �ۼ��� : 2021010507 ȫ����
	���� : Report #1 2�� ���� */

#include <stdio.h>                                                     // stdio.h ������ ������ ���α׷� �ȿ� ����

int main(void)
{    
	int input_money;                                                   // ������ �ݾ��� input_money�� �ϰ� int�� ������ ����
	int price;                                                         // ������ ������ ���� price�� �ϰ� int�� ������ ����
	int out_money;                                                     // �Ž������� out_money�� �ϰ� int�� ������ ����

	printf("������ �ݾ��� �Է��Ͻÿ� : ");                             // "������ �ݾ��� �Է��Ͻÿ� : " ���
	scanf_s("%d", &input_money);                                       // ���� input_money�� �� �Է�

	printf("������ ������ ���� �Է��Ͻÿ� : ");                        // "������ ������ ���� �Է��Ͻÿ� : " ���
	scanf_s("%d", &price);                                             // ���� price�� �� �Է�

	out_money = input_money - price;                                   // input_money - price�� ������� out_money�� ����

	printf("�Ž����� : %d��\n", out_money);                              // %d ��ġ�� �Ž�����(out_money)�� ���

	int paper_money1000 = out_money / 1000;                            // �Ž����� 1000���� ������ paper_money1000�̶� �ϰ�, out_money / 1000�� ������� paper_money1000�� ����
	out_money = out_money % 1000;                                      // �������� ���ϱ� ���� out_money % 1000�� �ϰ�, ������� out_money�� ����
	int coin500 = out_money / 500;                                     // �Ž����� 500���� ������ coin500�̶� �ϰ�, out_money / 500�� ������� coin500�� ����
	out_money = out_money % 500;                                       // �������� ���ϱ� ���� out_money % 500�� �ϰ�, ������� out_money�� ����
	int coin100 = out_money / 100;                                     // �Ž����� 100���� ������ coin100�̶� �ϰ�, out_money / 100�� ������� coin100�� ����
	out_money = out_money % 100;                                       // �������� ���ϱ� ���� out_money % 100�� �ϰ�, ������� out_money�� ����

	printf("�Ž����� 1000���� ���� : %d��\n", paper_money1000);        // %d��ġ�� �Ž����� 1000���� ����(paper_money1000)�� ���
	printf("�Ž����� 500���� ���� : %d��\n", coin500);                 // %d��ġ�� �Ž����� 500���� ����(coin500)�� ���
	printf("�Ž����� 100�� ���� : %d��\n", coin100);                   // %d��ġ�� �Ž����� 100���� ����(coin100)�� ���

	return 0;                                                          // ���α׷� ����
}