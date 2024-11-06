#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_FLIP 10000                        // ���� ���� ��
#define COIN_FWD_STATUS 1
#define COIN_BWD_STATUS 2
#define COIN_FWD_BWD 3
#define INITSTATUS 100
#define END_COND 999

// generating the seed number using the time clock information
// ���� ���� ���� �Լ� �����
void GenRandSeed()
{
    // generating the random number using the time seed
    // ���� ���ڸ� ��������� ���� �Լ��� ���
    srand((unsigned int)(time(NULL)));
    return;
}

// generating the random number
// ���� ���� �����
unsigned int GenRandFlipCoin(unsigned int nRange)
{
    unsigned int nRes = 0;
    while (1)
    {
        nRes = ((unsigned int)(rand()) % (nRange));
        if ((nRes == COIN_FWD_STATUS) || (nRes == COIN_BWD_STATUS))
            break;
    }
    return nRes;
}


// main function loop
int main(void)
{
    // assigning seed
    GenRandSeed();

    // initializing variables
    int nNumSumFwdFlip = 0;
    int nNumSumBwdFlip = 0;
    double dVarFwdFlip = 0.0;
    double dVarBwdFlip = 0.0;
    double dStdevFwdFlip = 0.0;
    double dStdevBwdFlip = 0.0;

    // infinite loop
    for (unsigned int i = 0; i < NUM_FLIP; i++)
    {
        // generating the random number, Flip Coin, 0: Fwd, 1: Bwd
        unsigned int nStatusFlipCoin = GenRandFlipCoin(COIN_FWD_BWD);

        // printing result
        switch (nStatusFlipCoin)
        {
        case COIN_FWD_STATUS:
           {
                nNumSumFwdFlip++;
                break;
            }
        case COIN_BWD_STATUS:
           {
                nNumSumBwdFlip++;
                break;
            }
        default:
           {
                printf("�ٽ� �õ��Ͻÿ�");
            }
         }
    }

    //����� ����ϱ�
    printf("Summation Result: (FWD, BWD):(%d, %d)\n", nNumSumFwdFlip, nNumSumBwdFlip);
    printf("Probability: (FWD, BWD):(%.2lf, %.2lf)\n", (double)(nNumSumFwdFlip) / (NUM_FLIP), (double)(nNumSumBwdFlip) / (NUM_FLIP));

    return 0;
}