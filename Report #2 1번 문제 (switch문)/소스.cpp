/*  작성자 : 2021010507 홍혁진
	제목 : Report #2 1번 문제 */

#include <stdio.h>                                          // stdio.h 파일의 내용을 프로그램 안에 복사

int main(void)
{
	int Number = 0;                                         // 판별할 숫자를 Number라 하고, int형 변수 Number 선언

	printf("판별할 숫자를 입력하시오 : ");                  // "판별할 숫자를 입력하시오 : "를 출력
	scanf_s("%d", &Number);                                 // 판별할 숫자 Number를 입력 받는다

	Number = Number % 2;                                    // 홀수, 짝수를 구분하기 위해 Number % 2의 결과값을 Number에 저장

	switch (Number)                                         // Number의 값이 얼마인지 확인
	{
	case 0:                                                 // Number가 0이면, 즉 판별할 숫자가 짝수이면
		printf(" 해당 숫자는 짝수이다.\n");                 // " 해당 숫자는 짝수이다."를 출력
		break;

	default:                                                // Number가 0이 아니면, 즉 판별할 숫자가 홀수이면
		printf(" 해당 숫자는 홀수이다.\n");                 // " 해당 숫자는 홀수이다."를 출력
		break;
	}

	return 0;                                               // 프로그램 종료
}