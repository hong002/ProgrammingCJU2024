#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLIP 10                 // �迭�� ũ�� 10���� ����
#define MIN_RANGE -100.0            // ���� ���� �ּڰ� -100.0
#define MAX_RANGE 100.0             // ���� ���� �ִ� 100.0

#define MAX_EVEN_NUMBER 10            // ¦�� ������ �ִ� ����
#define MAX_ODD_NUMBER 10             // Ȧ�� ������ �ִ� ����

// ���� �õ� ���� �Լ�
void GenRandSeed()
{
    srand((unsigned int)(time(NULL))); // ���� �ð��� �õ�� ����
    return;
}

// ���� ���� ���� �Լ� 
double GenRand_Number(double Min, double Max)
{
    double scale = rand() / (double)RAND_MAX;   // [0.0, 1.0] ������ �Ǽ� ����
    return Min + scale * (Max - Min);           // [Min, Max] ������ ����
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

// ¦���� Ȧ���� �и��ϴ� �Լ�
void Calc_Even_Odd_Array(double* Array, int Array_Size, int* Even_Array, int* Odd_Array, int* Even_Count, int* Odd_Count)
{
    for (int i = 0; i < Array_Size; i++)
    {
        int num = (int)Array[i]; // �Ǽ��� ������ ��ȯ

        if (num % 2 == 0)
        {
            if (*Even_Count < MAX_EVEN_NUMBER)
            {
                Even_Array[*Even_Count] = num; // ¦�� �迭�� ����
                (*Even_Count)++;
            }
        }
        else
        {
            if (*Odd_Count < MAX_ODD_NUMBER)
            {
                Odd_Array[*Odd_Count] = num;   // Ȧ�� �迭�� ����
                (*Odd_Count)++;
            }
        }
    }
}

// ¦���� Ȧ�� �迭�� ����ϴ� �Լ�
void Print_Even_Odd_Array(int* Even_Array, int Even_Count, int* Odd_Array, int Odd_Count)
{
    printf("¦�� ���� �迭:\n");
    for (int i = 0; i < MAX_EVEN_NUMBER; i++)
    {
        if (i < Even_Count)
        {
            printf("%d ", Even_Array[i]);  // ����� ¦�� ���
        }
        else
        {
            printf(" X ");                   // ������ ���� �ε��� ǥ��
        }
    }
    printf("\n");

    printf("Ȧ�� ���� �迭:\n");
    for (int i = 0; i < MAX_ODD_NUMBER; i++)
    {
        if (i < Odd_Count)
        {
            printf("%d ", Odd_Array[i]);  // ����� Ȧ�� ���
        }
        else
        {
            printf(" X ");                  // ������ ���� �ε��� ǥ��
        }
    }
    printf("\n");
}

// ���� �Լ�
int main(void)
{
    GenRandSeed(); // ���� �õ� ����

    double flips[NUM_FLIP];                                                 // ���� ���� ���� �迭

    Array_Rand_Number(flips, NUM_FLIP, MIN_RANGE, MAX_RANGE);               // �迭�� ���� ���� ����

    Print_Array(flips, NUM_FLIP, "�������� ������ �ʱ� �迭: ");            // �ʱ� �迭 ���

    int Even_Array[MAX_EVEN_NUMBER];                                        // ¦�� ���� �迭
    int Odd_Array[MAX_ODD_NUMBER];                                          // Ȧ�� ���� �迭
    int Even_Count = 0;
    int Odd_Count = 0;

    Calc_Even_Odd_Array(flips, NUM_FLIP, Even_Array, Odd_Array, &Even_Count, &Odd_Count);

    Print_Even_Odd_Array(Even_Array, Even_Count, Odd_Array, Odd_Count);     // ¦���� Ȧ�� �迭 ���

    return 0;
}