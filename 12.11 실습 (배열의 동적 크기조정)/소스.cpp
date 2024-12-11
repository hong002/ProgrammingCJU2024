#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ��� ��� �Լ�
void Calculate_Stats(int* Array, int Size, double* Sum, double* Mean, double* Variance, double* Stddev)
{
    *Sum = 0.0;
    *Variance = 0.0;
    double Average = 0.0;

    // �հ� ���
    for (int i = 0; i < Size; i++)
    {
        *Sum += Array[i];
    }

    // ��� ���
    Average = *Sum / Size;
    *Mean = Average;

    // �л� ���
    for (int i = 0; i < Size; i++)
    {
        *Variance += pow(Array[i] - Average, 2);
    }
    *Variance /= Size;

    // ǥ������ ���
    *Stddev = sqrt(*Variance);
}

int main(void)
{
    int Size = 0;
    double Sum, Mean, Variance, Stddev;

    // �ʱ� �迭 ũ�� �Է� �ޱ�
    printf("�ʱ� �迭�� ũ��: ");
    scanf_s("%d", &Size);

    // ���� �޸� �Ҵ�
    int* Array = (int*)malloc(Size * sizeof(int));

    // �ʱ� �迭 ��� �Է� �ޱ�
    printf("�Էµ� ��: ");
    for (int i = 0; i < Size; i++)
    {
        scanf_s("%d", &Array[i]);
    }

    // �ʱ� ��� ���
    Calculate_Stats(Array, Size, &Sum, &Mean, &Variance, &Stddev);

    // �ʱ� ��� ��� ���
    printf("�հ�: %.2lf\n", Sum);
    printf("���: %.2lf\n", Mean);
    printf("�л�: %.2lf\n", Variance);
    printf("ǥ������: %.2lf\n", Stddev);

    // �߰��� �迭 ũ�� �Է� �ޱ�
    int Add_Size = 0;
    printf("�߰��� �迭�� ũ��: ");
    scanf_s("%d", &Add_Size);

    // �޸� ���Ҵ�
    int* Add_Array = (int*)realloc(Array, (Size + Add_Size) * sizeof(int));
    Array = Add_Array;

    // �߰� �迭 ��� �Է� �ޱ�
    printf("�߰��� ��: ");
    for (int i = Size; i < Size + Add_Size; i++)
    {
        scanf_s("%d", &Array[i]);
    }

    // ��ü �迭 ũ�� ������Ʈ
    Size += Add_Size;

    // ���ο� ��� ���
    Calculate_Stats(Array, Size, &Sum, &Mean, &Variance, &Stddev);

    // ���ο� ��� ��� ���
    printf("���ο� �հ�: %.2lf\n", Sum);
    printf("���ο� ���: %.2lf\n", Mean);
    printf("���ο� �л�: %.2lf\n", Variance);
    printf("���ο� ǥ������: %.2lf\n", Stddev);

    // �޸� ����
    free(Array);

    return 0;
}