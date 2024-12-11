#include <stdio.h>

#define VECTOR_DIMENSION 3

int main (void)
{
    double Vector_A[VECTOR_DIMENSION];
    double Vector_B[VECTOR_DIMENSION];
    double* ptrA = Vector_A;               // 벡터 A의 포인터
    double* ptrB = Vector_B;               // 벡터 B의 포인터

    // 벡터 A의 성분 입력
    printf("벡터 A의 성분을 입력하시오. (Ax, Ay, Az): ");
    for (int i = 0; i < VECTOR_DIMENSION; i++)
    {
        scanf_s("%lf", ptrA + i);
    }

    // 벡터 B의 성분 입력
    printf("벡터 B의 성분을 입력하시오. (Bx, By, Bz): ");
    for (int i = 0; i < VECTOR_DIMENSION; i++)
    {
        scanf_s("%lf", ptrB + i);
    }

    // 외적 계산
    double Cross_Product[VECTOR_DIMENSION];
    double* ptrCross = Cross_Product;
    ptrCross[0] = ptrA[1] * ptrB[2] - ptrA[2] * ptrB[1];
    ptrCross[1] = ptrA[2] * ptrB[0] - ptrA[0] * ptrB[2];
    ptrCross[2] = ptrA[0] * ptrB[1] - ptrA[1] * ptrB[0];

    // 내적 계산
    double Dot_Product = 0.0;
    for (int i = 0; i < VECTOR_DIMENSION; i++)
    {
        Dot_Product = Dot_Product + (*(ptrA + i)) * (*(ptrB + i));
    }

    // 결과 출력
    printf("외적 결과: [%.2lf, %.2lf, %.2lf]\n", ptrCross[0], ptrCross[1], ptrCross[2]);
    printf("내적 결과: %.2lf\n", Dot_Product);

    return 0;
}