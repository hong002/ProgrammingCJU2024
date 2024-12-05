#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define GEN_RANDOM_NUMBER_ARRAY 100       // 랜덤으로 생성할 정수의 개수
#define CHOICE_NUMBER_ARRAY 10            // 추출할 정수의 개수
#define MIN_RANGE 0                       // 랜덤 정수의 최소 범위
#define MAX_RANGE 100                     // 랜덤 정수의 최대 범위

// 랜덤 시드 생성 함수
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
    return;
}

// 랜덤 정수 생성 함수
int GenRand_Number(int min, int max) 
{
    return min + rand() % (max - min + 1);      // [min, max] 범위의 정수 생성
}

// 배열에 랜덤 정수 채우는 함수
void GenRand_Number_Array(int* Array, int Size, int Min, int Max)
{
    for (int i = 0 ; i < Size ; i++) 
    {
        Array[i] = GenRand_Number(Min, Max);    // 배열에 범위 내의 랜덤 정수 배정
    }
    return;
}

// 오름차순 정렬 함수
void Ascending_Sort_Array(int* Array, int Array_Size)
{
    for (int i = 0; i < Array_Size - 1; i++)
    {
        for (int j = 0; j < Array_Size - i - 1; j++)
        {
            if (Array[j] > Array[j + 1])
            {
                // 순서에 맞지 않으면 값 바꾸기
                double temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }
    return;
}

// 배열 출력 함수
void Print_Array(int* Array, int Size, const char* Name) 
{
    printf("%s\n", Name);
    for (int i = 0; i < Size; i++) 
    {
        printf("%d ", Array[i]);
        if ((i + 1) % 10 == 0)                  // 10개씩 줄바꿈
            printf("\n");
    }
    printf("\n");
    return;
}

// 계산 함수
void Calculate_Stats(int* Array, int Size, double* Sum, double* Variance, double* Stddev) 
{
    *Sum = 0.0;
    *Variance = 0.0;
    double Average = 0.0;

    for (int i = 0; i < Size; i++) 
    {
        *Sum = *Sum + Array[i];                 // 합계 계산
    }

    Average = *Sum / Size;                      // 평균 계산

    for (int i = 0; i < Size; i++) 
    {
        *Variance = *Variance + pow(Array[i] - Average, 2);
    }
    *Variance = *Variance / Size;               // 분산 계산

    *Stddev = sqrt(*Variance);                  // 표준편차 계산

    return;
}

int main(void) 
{
    GenRandSeed();

    int Random_Number_Array[GEN_RANDOM_NUMBER_ARRAY];       // 100개의 랜덤 정수를 저장할 배열
    int Choice_Number_Array[CHOICE_NUMBER_ARRAY];           // 추출된 10개의 정수를 저장할 배열
    int User_Min, User_Max;                                 // 사용자로부터 입력 받을 추출 범위
    int Choice_Number_Count = 0;                            // 추출된 정수의 개수
    double Sum, Variance, Stddev;                           // 합계, 분산, 표준편차

    GenRand_Number_Array(Random_Number_Array, GEN_RANDOM_NUMBER_ARRAY, MIN_RANGE, MAX_RANGE);    // 100개의 랜덤 정수 생성
    Print_Array(Random_Number_Array, GEN_RANDOM_NUMBER_ARRAY, "랜덤으로 생성된 100개의 정수:");  // 생성된 100개의 정수 출력

    Ascending_Sort_Array(Random_Number_Array, GEN_RANDOM_NUMBER_ARRAY);                          // 오름차순 정렬
    Print_Array(Random_Number_Array, GEN_RANDOM_NUMBER_ARRAY, "오름차순 정렬된 배열:");          // 오름차순으로 정렬된 배열 출력

    printf("추출할 정수의 최소값과 최대값을 입력하시오. (0~100): ");
    scanf_s("%d %d", &User_Min, &User_Max);

    // 지정된 범위 내의 정수 추출
    for (int i = 0; i < GEN_RANDOM_NUMBER_ARRAY && Choice_Number_Count < CHOICE_NUMBER_ARRAY; i++)
    {
        if (Random_Number_Array[i] >= User_Min && Random_Number_Array[i] <= User_Max) 
        {
            Choice_Number_Array[Choice_Number_Count] = Random_Number_Array[i];
            Choice_Number_Count++;
        }
    }

    // 추출된 정수 출력
    Print_Array(Choice_Number_Array, Choice_Number_Count, "추출된 정수:");

    Calculate_Stats(Choice_Number_Array, Choice_Number_Count, &Sum, &Variance, &Stddev);

    printf("총합: %.2lf\n", Sum);
    printf("분산: %.2lf\n", Variance);
    printf("표준편차: %.2lf\n", Stddev);
    

    return 0;
}