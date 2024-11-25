#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COIN_FWD_FLIP 0
#define COIN_BWD_FLIP 1

#define NUM_FLIP 10000
#define COIN_FWD_STATUS 0
#define COIN_FWD_BWD 1

// 랜덤 숫자 생성 함수
void GenRandSeed() {
    srand((unsigned int)(time(NULL)));
}

// 동전 던지기 함수
unsigned int GenRandFlipCoin() {
    return rand() % 2; // 0 또는 1 반환
}

// 가위 바위 보 결과 계산 함수
unsigned int CalcRpsGameRes(unsigned int nPlayerRps, unsigned int nComRps) {
    if (nPlayerRps == nComRps) return 0; // 비김
    if ((nPlayerRps == 0 && nComRps == 2) || (nPlayerRps == 1 && nComRps == 0) || (nPlayerRps == 2 && nComRps == 1)) {
        return 1; // 플레이어 승리
    }
    return 2; // 컴퓨터 승리
}

// 메인 함수
int main(void) {
    GenRandSeed();

    int nNumSumFwdFlip = 0;
    int nNumSumBwdFlip = 0;

    for (unsigned int i = 0; i < NUM_FLIP; i++) {
        unsigned int nStatusFlipCoin = GenRandFlipCoin();
        unsigned int nPlayerRps = rand() % 3; // 가위(0), 바위(1), 보(2)
        unsigned int nComRps = rand() % 3; // 가위(0), 바위(1), 보(2)

        unsigned int nGameRpsRes = CalcRpsGameRes(nPlayerRps, nComRps);

        // 결과 출력
        if (nGameRpsRes == 0) {
            printf("비김: 플레이어 %d, 컴퓨터 %d\n", nPlayerRps, nComRps);
        }
        else if (nGameRpsRes == 1) {
            printf("플레이어 승리: 플레이어 %d, 컴퓨터 %d\n", nPlayerRps, nComRps);
        }
        else {
            printf("컴퓨터 승리: 플레이어 %d, 컴퓨터 %d\n", nPlayerRps, nComRps);
        }
    }

    return 0;
}