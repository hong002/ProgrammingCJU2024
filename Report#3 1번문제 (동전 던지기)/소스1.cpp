#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COIN_FWD_FLIP 0
#define COIN_BWD_FLIP 1

#define NUM_FLIP 10000
#define COIN_FWD_STATUS 0
#define COIN_FWD_BWD 1

// ���� ���� ���� �Լ�
void GenRandSeed() {
    srand((unsigned int)(time(NULL)));
}

// ���� ������ �Լ�
unsigned int GenRandFlipCoin() {
    return rand() % 2; // 0 �Ǵ� 1 ��ȯ
}

// ���� ���� �� ��� ��� �Լ�
unsigned int CalcRpsGameRes(unsigned int nPlayerRps, unsigned int nComRps) {
    if (nPlayerRps == nComRps) return 0; // ���
    if ((nPlayerRps == 0 && nComRps == 2) || (nPlayerRps == 1 && nComRps == 0) || (nPlayerRps == 2 && nComRps == 1)) {
        return 1; // �÷��̾� �¸�
    }
    return 2; // ��ǻ�� �¸�
}

// ���� �Լ�
int main(void) {
    GenRandSeed();

    int nNumSumFwdFlip = 0;
    int nNumSumBwdFlip = 0;

    for (unsigned int i = 0; i < NUM_FLIP; i++) {
        unsigned int nStatusFlipCoin = GenRandFlipCoin();
        unsigned int nPlayerRps = rand() % 3; // ����(0), ����(1), ��(2)
        unsigned int nComRps = rand() % 3; // ����(0), ����(1), ��(2)

        unsigned int nGameRpsRes = CalcRpsGameRes(nPlayerRps, nComRps);

        // ��� ���
        if (nGameRpsRes == 0) {
            printf("���: �÷��̾� %d, ��ǻ�� %d\n", nPlayerRps, nComRps);
        }
        else if (nGameRpsRes == 1) {
            printf("�÷��̾� �¸�: �÷��̾� %d, ��ǻ�� %d\n", nPlayerRps, nComRps);
        }
        else {
            printf("��ǻ�� �¸�: �÷��̾� %d, ��ǻ�� %d\n", nPlayerRps, nComRps);
        }
    }

    return 0;
}