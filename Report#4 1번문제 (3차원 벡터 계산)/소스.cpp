#include <stdio.h>

#define VECTOR_DIMENSION 3

int main (void)
{
    double Vector_A[VECTOR_DIMENSION];
    double Vector_B[VECTOR_DIMENSION];
    double* ptrA = Vector_A;               // ���� A�� ������
    double* ptrB = Vector_B;               // ���� B�� ������

    // ���� A�� ���� �Է�
    printf("���� A�� ������ �Է��Ͻÿ�. (Ax, Ay, Az): ");
    for (int i = 0; i < VECTOR_DIMENSION; i++)
    {
        scanf_s("%lf", ptrA + i);
    }

    // ���� B�� ���� �Է�
    printf("���� B�� ������ �Է��Ͻÿ�. (Bx, By, Bz): ");
    for (int i = 0; i < VECTOR_DIMENSION; i++)
    {
        scanf_s("%lf", ptrB + i);
    }

    // ���� ���
    double Cross_Product[VECTOR_DIMENSION];
    double* ptrCross = Cross_Product;
    ptrCross[0] = ptrA[1] * ptrB[2] - ptrA[2] * ptrB[1];
    ptrCross[1] = ptrA[2] * ptrB[0] - ptrA[0] * ptrB[2];
    ptrCross[2] = ptrA[0] * ptrB[1] - ptrA[1] * ptrB[0];

    // ���� ���
    double Dot_Product = 0.0;
    for (int i = 0; i < VECTOR_DIMENSION; i++)
    {
        Dot_Product = Dot_Product + (*(ptrA + i)) * (*(ptrB + i));
    }

    // ��� ���
    printf("���� ���: [%.2lf, %.2lf, %.2lf]\n", ptrCross[0], ptrCross[1], ptrCross[2]);
    printf("���� ���: %.2lf\n", Dot_Product);

    return 0;
}