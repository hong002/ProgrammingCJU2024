#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 통계 계산 함수
void Calculate_Stats(int* Array, int Size, double* Sum, double* Mean, double* Variance, double* Stddev)
{
    *Sum = 0.0;
    *Variance = 0.0;
    double Average = 0.0;

    // 합계 계산
    for (int i = 0; i < Size; i++)
    {
        *Sum += Array[i];
    }

    // 평균 계산
    Average = *Sum / Size;
    *Mean = Average;

    // 분산 계산
    for (int i = 0; i < Size; i++)
    {
        *Variance += pow(Array[i] - Average, 2);
    }
    *Variance /= Size;

    // 표준편차 계산
    *Stddev = sqrt(*Variance);
}

int main(void)
{
    int Size = 0;
    double Sum, Mean, Variance, Stddev;

    // 초기 배열 크기 입력 받기
    printf("초기 배열의 크기: ");
    scanf_s("%d", &Size);

    // 동적 메모리 할당
    int* Array = (int*)malloc(Size * sizeof(int));

    // 초기 배열 요소 입력 받기
    printf("입력된 값: ");
    for (int i = 0; i < Size; i++)
    {
        scanf_s("%d", &Array[i]);
    }

    // 초기 통계 계산
    Calculate_Stats(Array, Size, &Sum, &Mean, &Variance, &Stddev);

    // 초기 통계 결과 출력
    printf("합계: %.2lf\n", Sum);
    printf("평균: %.2lf\n", Mean);
    printf("분산: %.2lf\n", Variance);
    printf("표준편차: %.2lf\n", Stddev);

    // 추가할 배열 크기 입력 받기
    int Add_Size = 0;
    printf("추가할 배열의 크기: ");
    scanf_s("%d", &Add_Size);

    // 메모리 재할당
    int* Add_Array = (int*)realloc(Array, (Size + Add_Size) * sizeof(int));
    Array = Add_Array;

    // 추가 배열 요소 입력 받기
    printf("추가된 값: ");
    for (int i = Size; i < Size + Add_Size; i++)
    {
        scanf_s("%d", &Array[i]);
    }

    // 전체 배열 크기 업데이트
    Size += Add_Size;

    // 새로운 통계 계산
    Calculate_Stats(Array, Size, &Sum, &Mean, &Variance, &Stddev);

    // 새로운 통계 결과 출력
    printf("새로운 합계: %.2lf\n", Sum);
    printf("새로운 평균: %.2lf\n", Mean);
    printf("새로운 분산: %.2lf\n", Variance);
    printf("새로운 표준편차: %.2lf\n", Stddev);

    // 메모리 해제
    free(Array);

    return 0;
}