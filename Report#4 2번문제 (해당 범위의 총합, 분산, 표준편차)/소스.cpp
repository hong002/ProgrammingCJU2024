#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define GEN_RANDOM_NUMBER_ARRAY 100       // �������� ������ ������ ����
#define CHOICE_NUMBER_ARRAY 10            // ������ ������ ����
#define MIN_RANGE 0                       // ���� ������ �ּ� ����
#define MAX_RANGE 100                     // ���� ������ �ִ� ����

// ���� �õ� ���� �Լ�
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
    return;
}

// ���� ���� ���� �Լ�
int GenRand_Number(int min, int max) 
{
    return min + rand() % (max - min + 1);      // [min, max] ������ ���� ����
}

// �迭�� ���� ���� ä��� �Լ�
void GenRand_Number_Array(int* Array, int Size, int Min, int Max)
{
    for (int i = 0 ; i < Size ; i++) 
    {
        Array[i] = GenRand_Number(Min, Max);    // �迭�� ���� ���� ���� ���� ����
    }
    return;
}

// �������� ���� �Լ�
void Ascending_Sort_Array(int* Array, int Array_Size)
{
    for (int i = 0; i < Array_Size - 1; i++)
    {
        for (int j = 0; j < Array_Size - i - 1; j++)
        {
            if (Array[j] > Array[j + 1])
            {
                // ������ ���� ������ �� �ٲٱ�
                double temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }
    return;
}

// �迭 ��� �Լ�
void Print_Array(int* Array, int Size, const char* Name) 
{
    printf("%s\n", Name);
    for (int i = 0; i < Size; i++) 
    {
        printf("%d ", Array[i]);
        if ((i + 1) % 10 == 0)                  // 10���� �ٹٲ�
            printf("\n");
    }
    printf("\n");
    return;
}

// ��� �Լ�
void Calculate_Stats(int* Array, int Size, double* Sum, double* Variance, double* Stddev) 
{
    *Sum = 0.0;
    *Variance = 0.0;
    double Average = 0.0;

    for (int i = 0; i < Size; i++) 
    {
        *Sum = *Sum + Array[i];                 // �հ� ���
    }

    Average = *Sum / Size;                      // ��� ���

    for (int i = 0; i < Size; i++) 
    {
        *Variance = *Variance + pow(Array[i] - Average, 2);
    }
    *Variance = *Variance / Size;               // �л� ���

    *Stddev = sqrt(*Variance);                  // ǥ������ ���

    return;
}

int main(void) 
{
    GenRandSeed();

    int Random_Number_Array[GEN_RANDOM_NUMBER_ARRAY];       // 100���� ���� ������ ������ �迭
    int Choice_Number_Array[CHOICE_NUMBER_ARRAY];           // ����� 10���� ������ ������ �迭
    int User_Min, User_Max;                                 // ����ڷκ��� �Է� ���� ���� ����
    int Choice_Number_Count = 0;                            // ����� ������ ����
    double Sum, Variance, Stddev;                           // �հ�, �л�, ǥ������

    GenRand_Number_Array(Random_Number_Array, GEN_RANDOM_NUMBER_ARRAY, MIN_RANGE, MAX_RANGE);    // 100���� ���� ���� ����
    Print_Array(Random_Number_Array, GEN_RANDOM_NUMBER_ARRAY, "�������� ������ 100���� ����:");  // ������ 100���� ���� ���

    Ascending_Sort_Array(Random_Number_Array, GEN_RANDOM_NUMBER_ARRAY);                          // �������� ����
    Print_Array(Random_Number_Array, GEN_RANDOM_NUMBER_ARRAY, "�������� ���ĵ� �迭:");          // ������������ ���ĵ� �迭 ���

    printf("������ ������ �ּҰ��� �ִ밪�� �Է��Ͻÿ�. (0~100): ");
    scanf_s("%d %d", &User_Min, &User_Max);

    // ������ ���� ���� ���� ����
    for (int i = 0; i < GEN_RANDOM_NUMBER_ARRAY && Choice_Number_Count < CHOICE_NUMBER_ARRAY; i++)
    {
        if (Random_Number_Array[i] >= User_Min && Random_Number_Array[i] <= User_Max) 
        {
            Choice_Number_Array[Choice_Number_Count] = Random_Number_Array[i];
            Choice_Number_Count++;
        }
    }

    // ����� ���� ���
    Print_Array(Choice_Number_Array, Choice_Number_Count, "����� ����:");

    Calculate_Stats(Choice_Number_Array, Choice_Number_Count, &Sum, &Variance, &Stddev);

    printf("����: %.2lf\n", Sum);
    printf("�л�: %.2lf\n", Variance);
    printf("ǥ������: %.2lf\n", Stddev);
    

    return 0;
}