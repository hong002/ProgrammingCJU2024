#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLIP 10                 // 배열의 크기 10으로 설정
#define MIN_RANGE -100.0            // 랜덤 숫자 최솟값 -100.0
#define MAX_RANGE 100.0             // 랜덤 숫자 최댓값 100.0

// 랜덤 시드 생성 함수
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
    return;
}

// 랜덤 숫자 생성 함수 
double GenRand_Number(double Min, double Max)
{
    double scale = rand() / (double)RAND_MAX;   // [0.0, 1.0] 범위로 실수 생성
    return Min + scale * (Max - Min);           // [min, max] 범위로 설정
}

// 배열에 랜덤 숫자 채우는 함수
void Array_Rand_Number(double* Array, int Array_Size, double Min, double Max)
{
    for (int i = 0; i < Array_Size; i++)
    {
        Array[i] = GenRand_Number(Min, Max);    // 배열에 랜덤 실수 배정
    }
    return;
}

// 오름차순 정렬 함수
void Ascending_Sort_Array(double* Array, int Array_Size)
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

// 내림차순 정렬 함수
void Descending_Sort_Array(double* Array, int Array_Size)
{
    for (int i = 0; i < Array_Size - 1; i++)
    {
        for (int j = 0; j < Array_Size - i - 1; j++)
        {
            if (Array[j] < Array[j + 1])
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
void Print_Array(double* Array, int Array_Size, const char* Name_Function)
{
    printf("%s\n", Name_Function);
    for (int i = 0; i < Array_Size; i++)
    {
        printf("%.2lf ", Array[i]); // 소수점 둘째 자리까지 출력
        if ((i + 1) % 10 == 0)      // 10개씩 출력
            printf("\n");
    }
    printf("\n");

    return;
}

// 메인 함수
int main(void)
{
    GenRandSeed();

    double flips[NUM_FLIP];                                        // 랜덤 숫자 저장 배열

    Array_Rand_Number(flips, NUM_FLIP, MIN_RANGE, MAX_RANGE);      // 배열에 랜덤 숫자 배정

    Print_Array(flips, NUM_FLIP, "랜덤으로 생성된 초기 배열:");    // 초기 배열 출력

    Ascending_Sort_Array(flips, NUM_FLIP);                         // 오름차순 정렬
    Print_Array(flips, NUM_FLIP, "오름차순 정렬된 배열:");         // 오름차순으로 정렬된 배열 출력

    Descending_Sort_Array(flips, NUM_FLIP);                        // 내림차순 정렬
    Print_Array(flips, NUM_FLIP, "내림차순 정렬된 배열:");         // 내림차순으로 정렬된 배열 출력

    return 0;
}