/*  �ۼ��� : 2021010507 ȫ����
    ���� : Report #1 1�� ���� */

#include <stdio.h>                                                                     // stdio.h ������ ������ ���α׷� �ȿ� ����

int main(void)
{
	double a, b, c, d;                                                                 // double�� ���� a, b, c, d ����
	double res1, res2, res3, res4 = 0.0;                                               // double�� ���� res1, res2, res3, res4 ����
	double Degree = 0.0;                                                               // double�� ���� Degree ����
	
	a = 180.0;                                                                         // double�� ���� a�� �Ǽ� 180.0 ����
	b = 1.0;                                                                           // double�� ���� b�� �Ǽ� 1.0 ����
	c = -1.0;                                                                          // double�� ���� c�� �Ǽ� -1.0 ����
	d = 360.0;                                                                         // double�� ���� d�� �Ǽ� 360.0 ����
	
	printf("����� �������� �Է��Ͻÿ�\t (����� �������� 360 ���ϰ��� ���)");        // "����� �������� �Է��Ͻÿ�"�� ����ϰ� �� ��ġ�� �̵�(\t) �Ŀ� "(����� �������� 360 ���ϰ��� ���)"�� ���
	scanf_s("%lf", &Degree);                                                           // ����� ������ Degree�� �Է�
	res1 = Degree * c + a;                                                             // ���� ����� res1�� ����
	res2 = Degree * b;                                                                 // ���� ����� res2�� ����
	Degree = (Degree > a) ? res1 : res2;                                               // Degree�� a���� Ŭ ��� res1���� Degree�� �����ϰ�, Degree�� a���� ũ������ ��� res2���� Degree�� ����
	printf("��ȯ�� �ڼ��� : %.2lf [deg.]\n", Degree);                                  // "��ȯ�� �ڼ��� : [deg.]"�� ����ϰ� �� �ٲ�(\n)
	printf("����� �������� �Է��Ͻÿ�\t (����� �������� 360 �ʰ����� ���)");        // "����� �������� �Է��Ͻÿ�"�� ����ϰ� �� ��ġ�� �̵�(\t) �Ŀ� "(����� �������� 360 �ʰ����� ���)"�� ���
	scanf_s("%lf", &Degree);                                                           // ����� ������ Degree�� �Է�
	res3 = Degree * c + a + d;                                                         // ���� ����� res3�� ����
	res4 = Degree * b - d;                                                             // ���� ����� res4�� ����
	Degree = (Degree > (a + d)) ? res3 : res4;                                         // Degree�� (a+d)���� Ŭ ��� res3���� Degree�� �����ϰ�, Degree�� (a+d)���� ũ������ ��� res4���� Degree�� ����
	printf("��ȯ�� �ڼ��� : %.2lf [deg.]\n", Degree);                                  // "��ȯ�� �ڼ��� : [deg.]"�� ����ϰ� �� �ٲ�(\n)

	return 0;                                                                          // ���α׷� ����
}