#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RANGE 1                                                              // 최소 범위
#define MAX_RANGE 100                                                            // 최대 범위
#define MAX_CHANCE 10                                                            // 최대 기회 횟수

// generating the seed number using the time clock information (랜덤 숫자 생성 함수 만들기)
void GenRandSeed()
{
    // generating the random number using the time seed
    srand((unsigned int)(time(NULL)));
    return;
}

// generating the random number (특정 범위 사이의 랜덤 숫자 만들기)
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
    unsigned int nAnswerNumber = GenRandNumRandom(MIN_RANGE, MAX_RANGE);         // 정답 숫자
    unsigned int nPlayernAnswerNumber = 0;                                       // 사용자가 입력하는 정답 숫자
    int Chance = 0;                                                              // 기회

    printf("%d부터 %d 사이의 숫자를 %d번의 기회 내로 맞추시오.\n", MIN_RANGE, MAX_RANGE, MAX_CHANCE);

    for (Chance = 1; Chance <= MAX_CHANCE; Chance++)                             // 기회가 끝날 때까지 반복
    {
        printf("시도 %d: 숫자를 입력하세요 (%d - %d): ", Chance, MIN_RANGE, MAX_RANGE);
        scanf_s("%d", &nPlayernAnswerNumber);

        if (nPlayernAnswerNumber < nAnswerNumber)                                // 정답 숫자보다 작은 경우
        {
            printf("UP: 더 높은 숫자를 입력하시오.\n\n");
        }
        else if (nPlayernAnswerNumber > nAnswerNumber)                           // 정답 숫자보다 큰 경우
        {
            printf("DOWN: 더 낮은 숫자를 입력하시오.\n\n");
        }
        else if (nPlayernAnswerNumber == nAnswerNumber)                          // 정답 숫자를 맞췄을 경우
        {
            printf("\n성공 :) \n정답 %d을 %d번 만에 맞췄습니다.\n", nAnswerNumber, Chance);
            break;
        }
        else                                                                     // 정답 숫자를 기회안에 맞추지 못할 경우
        {
            printf("\n실패 :( \n정답은 %d이었습니다.\n", nAnswerNumber);
        }
    }

    return 0;
}