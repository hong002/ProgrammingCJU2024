#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Rock_Paper_Scissors 3
#define Rock 0
#define Paper 1
#define Scissors 2
#define INITSTATUS 100
#define END_COND 999

#define PLAYER_WIN 11
#define PLAYER_LOSE 12
#define DRAW 13

// generating the seed number using the time clock information
void GenRandSeed()
{
    // generating the random number using the time seed
    srand((unsigned int)(time(NULL)));
    return;
}

// generating the random number
unsigned int GenRandNum(unsigned int nRange)
{
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    nRes = ((unsigned int)(nNum) % (nRange));
    return nRes;
}

int main(void)
{
    // assigning seed
    GenRandSeed();

    unsigned int nComRps = INITSTATUS;
    unsigned int nPlayerRps = INITSTATUS;

    // initializing variables
    int nRange = 0;

    while (1)
    {
        // generating the input information
        printf("Input your Status (Rock: 0, Paper: 1, Scissors: 2) :\n");
        printf("if you want to end the loop, please input 999\n");
        scanf_s("%d", &nPlayerRps);

        // escaping the while loop
        if (nPlayerRps == END_COND)
        {
            printf("end of the infinite while loop RPS game...\n");
            break;
        }
        if ((nPlayerRps < 0) || (nPlayerRps >= Rock_Paper_Scissors))
        {
            printf("check your input condition..\n");
            continue;
        }

       int nComRps = GenRandNum(nRange = Rock_Paper_Scissors);

        printf("(Player, Computer):(%d, %d)\n\n", nPlayerRps, nComRps);

        if (nPlayerRps == nComRps)
        {
            return DRAW;
        }
        if ((nPlayerRps == Rock) && (nComRps == Scissors))
        {
            return PLAYER_WIN;
        }
        else if ((nPlayerRps == Scissors) && (nComRps == Rock))
        {
            return PLAYER_LOSE;
        }
        else
        {
            if (nPlayerRps < nComRps)
            {
                return PLAYER_LOSE;
            }
            else
            {
                return PLAYER_WIN;
            }
        }

        switch (nGameRps)

    }

    system("pause");
    return 0;
}