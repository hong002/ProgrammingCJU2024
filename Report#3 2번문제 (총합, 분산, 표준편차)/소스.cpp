#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MIN_RANGE 1                                                              // �ּ� ����
#define MAX_RANGE 100                                                            // �ִ� ����
#define NUM_RANDOM 10                                                            // ������ ������ ����

// generating the seed number using the time clock information (���� ���� ���� �Լ� �����)
void GenRandSeed()
{
    // generating the random number using the time seed
    srand((unsigned int)(time(NULL)));
    return;
}

// generating the random number (���� ���� �����)
unsigned int GenRandNumRandom(int min, int max)
{
    unsigned int nRes = 0;

    nRes = (rand() % (max - min + 1)) + min;                                     // Ư�� ���� �̳��� ������ �������� ����

    return nRes;
}

// main function loop
int main(void)
{
    // assigning seed
    GenRandSeed();

    // initializing variables
    unsigned int nNumRandom = 0;                                                 // ������ ���� ����
    unsigned int nSumNumRandom = 0;                                              // ������ ���� ������ ����
    unsigned int nSumNumRandomNumRandom = 0;                                     // ������ ���� ������ ������ ��
    double nAverageNumRandom = 0.0;                                              // ������ ���� ������ ���
    double nVarNumRandom = 0.0;                                                  // ������ ���� ������ �л�
    double nStdevNumRandom = 0.0;                                                // ������ ���� ������ ǥ������

    printf("������ ���� ����:");

    // infinite loop
    for (int i = 0; i < NUM_RANDOM; i++)
    {
        // generating the random number, Flip Coin, 0: Fwd, 1: Bwd
        nNumRandom = GenRandNumRandom(MIN_RANGE, MAX_RANGE);
        printf(" %d ", nNumRandom);

        nSumNumRandom = nSumNumRandom + nNumRandom;
        nSumNumRandomNumRandom = nSumNumRandomNumRandom + ((unsigned int)nNumRandom * nNumRandom);
    }

    nAverageNumRandom = (double)nSumNumRandom / (double)NUM_RANDOM;
    nVarNumRandom = ((double)nSumNumRandomNumRandom / (double)NUM_RANDOM) - (nAverageNumRandom * nAverageNumRandom);
    nStdevNumRandom = sqrt(nVarNumRandom);


    //����� ����ϱ�
    printf("\n����: %d\n", nSumNumRandom);
    printf("�л�: %.2lf\n", nVarNumRandom);
    printf("ǥ������: %.2lf\n", nStdevNumRandom);

    return 0;
}