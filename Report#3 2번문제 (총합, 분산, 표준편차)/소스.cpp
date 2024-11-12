#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MIN_RANGE 1                                                              // 최소 범위
#define MAX_RANGE 100                                                            // 최대 범위
#define NUM_RANDOM 10                                                            // 생성할 정수의 갯수

// generating the seed number using the time clock information (랜덤 숫자 생성 함수 만들기)
void GenRandSeed()
{
    // generating the random number using the time seed
    srand((unsigned int)(time(NULL)));
    return;
}

// generating the random number (랜덤 숫자 만들기)
unsigned int GenRandNumRandom(int min, int max)
{
    unsigned int nRes = 0;

    nRes = (rand() % (max - min + 1)) + min;                                     // 특정 범위 이내의 정수를 랜덤으로 생성

    return nRes;
}

// main function loop
int main(void)
{
    // assigning seed
    GenRandSeed();

    // initializing variables
    unsigned int nNumRandom = 0;                                                 // 생성된 랜덤 숫자
    unsigned int nSumNumRandom = 0;                                              // 생성된 랜덤 숫자의 총합
    unsigned int nSumNumRandomNumRandom = 0;                                     // 생성된 랜덤 숫자의 제곱의 합
    double nAverageNumRandom = 0.0;                                              // 생성된 랜덤 숫자의 평균
    double nVarNumRandom = 0.0;                                                  // 생성된 랜덤 숫자의 분산
    double nStdevNumRandom = 0.0;                                                // 생성된 랜덤 숫자의 표준편차

    printf("생성된 랜덤 정수:");

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


    //결과값 출력하기
    printf("\n총합: %d\n", nSumNumRandom);
    printf("분산: %.2lf\n", nVarNumRandom);
    printf("표준편차: %.2lf\n", nStdevNumRandom);

    return 0;
}