#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RANGE 1                                                              // �ּ� ����
#define MAX_RANGE 100                                                            // �ִ� ����
#define MAX_CHANCE 10                                                            // �ִ� ��ȸ Ƚ��

// generating the seed number using the time clock information (���� ���� ���� �Լ� �����)
void GenRandSeed()
{
    // generating the random number using the time seed
    srand((unsigned int)(time(NULL)));
    return;
}

// generating the random number (Ư�� ���� ������ ���� ���� �����)
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
    unsigned int nAnswerNumber = GenRandNumRandom(MIN_RANGE, MAX_RANGE);         // ���� ����
    unsigned int nPlayernAnswerNumber = 0;                                       // ����ڰ� �Է��ϴ� ���� ����
    int Chance = 0;                                                              // ��ȸ

    printf("%d���� %d ������ ���ڸ� %d���� ��ȸ ���� ���߽ÿ�.\n", MIN_RANGE, MAX_RANGE, MAX_CHANCE);

    for (Chance = 1; Chance <= MAX_CHANCE; Chance++)                             // ��ȸ�� ���� ������ �ݺ�
    {
        printf("�õ� %d: ���ڸ� �Է��ϼ��� (%d - %d): ", Chance, MIN_RANGE, MAX_RANGE);
        scanf_s("%d", &nPlayernAnswerNumber);

        if (nPlayernAnswerNumber < nAnswerNumber)                                // ���� ���ں��� ���� ���
        {
            printf("UP: �� ���� ���ڸ� �Է��Ͻÿ�.\n\n");
        }
        else if (nPlayernAnswerNumber > nAnswerNumber)                           // ���� ���ں��� ū ���
        {
            printf("DOWN: �� ���� ���ڸ� �Է��Ͻÿ�.\n\n");
        }
        else if (nPlayernAnswerNumber == nAnswerNumber)                          // ���� ���ڸ� ������ ���
        {
            printf("\n���� :) \n���� %d�� %d�� ���� ������ϴ�.\n", nAnswerNumber, Chance);
            break;
        }
        else                                                                     // ���� ���ڸ� ��ȸ�ȿ� ������ ���� ���
        {
            printf("\n���� :( \n������ %d�̾����ϴ�.\n", nAnswerNumber);
        }
    }

    return 0;
}