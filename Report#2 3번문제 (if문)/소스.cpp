/*  작성자 : 2021010507 홍혁진
	제목 : Report #2 3번 문제 */

#include <stdio.h>                                       // stdio.h 파일의 내용을 프로그램 안에 복사

int main(void)
{
	double Score;                                        // 입력할 점수를 Score라 하고, double형 변수 선언

	printf("점수를 입력하시오 : ");                      // "점수를 입력하시오 : "를 출력
	scanf_s("%lf", &Score);                              // 입력할 점수 Score를 입력받는다

	if (Score >= 90.0)                                   // 점수가 90점 이상인 경우
	{
		printf("학점 : A\n");                            // "학점 : A"를 출력
	}
	else if (Score >= 80.0)                              // 점수가 90점 미만이고, 80점 이상인 경우
	{
		printf("학점 : B\n");                            // "학점 : B"를 출력
	}
	else if (Score >= 70.0)                              // 점수가 80점 미만이고, 70점 이상인 경우
	{
		printf("학점 : C\n");                            // "학점 : C"를 출력
	}
	else if (Score >= 60.0)                              // 점수가 70점 미만이고, 60점 이상인 경우
	{
		printf("학점 : D\n");                            // "학점 : D"를 출력
	}
	else                                                 // 점수가 60점 미만인 경우
	{
		printf("학점 : F\n");                            // "학점 : F"를 출력
	}

	return 0;                                            // 프로그램 종료
}