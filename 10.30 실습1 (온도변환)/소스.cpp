#include <stdio.h>

double Ctemperature(double C);                                                           // �����µ� ����
double Ftemperature(double F);                                                           // ȭ���µ� ����

int main(void)
{
	int choice;
	double C, F;
	double result;                                                                       // ��ȯ�� �� ����

	printf("��ȯ�� �µ������� �����Ͻÿ�. (1��: ����->ȭ��. 2��: ȭ��->����) : ");
	scanf_s("%d", &choice);
	
	if (choice == 1)                                                                     // ����->ȭ�� �� ���� ���
	{
		printf("���� �µ��� �Է��Ͻÿ� : ");
		scanf_s("%lf", &C);
		result = Ctemperature(C);
		printf("ȭ�� �µ� : %.2lf\n", result);
	}
	else if (choice == 2)                                                                // ȭ��->���� �� ���� ���
	{
		printf("ȭ�� �µ��� �Է��Ͻÿ� : ");
		scanf_s("%lf", &F);
		result = Ftemperature(F);
		printf("���� �µ� : %.2lf\n", result);
	}
	else
	{
		printf("�ٽ� �õ��Ͻÿ�");
	}

	return 0;
}

double Ctemperature(double C)
{
	return C * 9.0 / 5.0 + 32;                                                           // ����->ȭ�� ��ȯ ���� ���
}
double Ftemperature(double F)
{
	return (F - 32) * 5.0 / 9.0;                                                         // ȭ��->���� ��ȯ ���� ���
}