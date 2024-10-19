/*  작성자 : 2021010507 홍혁진
	제목 : Report #2 1번 문제 */

#include <stdio.h>                                          // stdio.h 파일의 내용을 프로그램 안에 복사

int main(void)
{
	int Number = 0;                                         // 판별할 숫자를 Number라 하고, int형 변수 Number 선언

	printf("판별할 숫자를 입력하시오 : ");                  // "판별할 숫자를 입력하시오 : "를 출력
	scanf_s("%d", &Number);                                 // 판별할 숫자 Number를 입력 받는다

	Number = Number % 2;

	switch (Number)
	{
	case 0:
		printf(" 해당 숫자는 짝수이다.\n");
		break;

	default:
		printf(" 해당 숫자는 홀수이다.\n");
		break;
	}

	return 0;                                               // 프로그램 종료
}