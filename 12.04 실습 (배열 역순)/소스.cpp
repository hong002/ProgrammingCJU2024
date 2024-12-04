#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLIP 10                 // �迭�� ũ�� 10���� ����
#define MIN_RANGE -100.0            // ���� ���� �ּڰ� -100.0
#define MAX_RANGE 100.0             // ���� ���� �ִ� 100.0

// ���� �õ� ���� �Լ�
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
    return;
}

// ���� ���� ���� �Լ� 
double GenRand_Number(double Min, double Max)
{
    double scale = rand() / (double)RAND_MAX;   // [0.0, 1.0] ������ �Ǽ� ����
    return Min + scale * (Max - Min);           // [min, max] ������ ����
}

// �迭�� ���� ���� ä��� �Լ�
void Array_Rand_Number(double* Array, int Array_Size, double Min, double Max)
{
    for (int i = 0; i < Array_Size; i++)
    {
        Array[i] = GenRand_Number(Min, Max);    // �迭�� ���� �Ǽ� ����
    }
    return;
}

// �迭 ��� �Լ�
void Print_Array(double* Array, int Array_Size, const char* Name_Function)
{
    printf("%s\n", Name_Function);
    for (int i = 0; i < Array_Size; i++)
    {
        printf("%.2lf ", Array[i]);            // �Ҽ��� ��° �ڸ����� ���
        if ((i + 1) % 10 == 0)                 // 10���� ���
            printf("\n");
    }
    printf("\n");

    return;
}

// �迭�� ���� ��� �Լ�
void Reverse_Sort_Array(double* Array, int Array_Size)
{
    printf("�������� ���ĵ� �迭: \n");
    for (int i = Array_Size - 1; i >= 0; i--)
    {
        printf("%.2lf ", Array[i]);            // �Ҽ��� ��° �ڸ����� ���

        if ((Array_Size - i) % 10 == 0)        // 10���� ���
            printf("\n");
    }
    printf("\n");
    return;
}

// ���� �Լ�
int main(void)
{
    GenRandSeed();

    double flips[NUM_FLIP];                                         // ���� ���� ���� �迭

    Array_Rand_Number(flips, NUM_FLIP, MIN_RANGE, MAX_RANGE);       // �迭�� ���� ���� ����

    Print_Array(flips, NUM_FLIP, "�������� ������ �ʱ� �迭: ");    // �ʱ� �迭 ���

    Reverse_Sort_Array(flips, NUM_FLIP);                            // �迭�� ���� ���

    return 0;
}