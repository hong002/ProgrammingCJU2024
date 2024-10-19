/*  작성자 : 2021010507 홍혁진
	제목 : Report #2 3번 문제 */

#include <stdio.h>                                       // stdio.h 파일의 내용을 프로그램 안에 복사

int main(void)
{
	double Score;                                        // 입력할 점수를 Score라 하고, double형 변수 선언
	int Grade;                                           // 학점을 Grade라 하고, int형 변수 선언

	printf("점수를 입력하시오 : ");                      // "점수를 입력하시오 : "를 출력
	scanf_s("%lf", &Score);                              // 입력할 점수 Score를 입력받는다

	Grade = Score / 10;                                  // 점수대별로 학점을 나누기 위해 Score / 10의 결과값을 Grade에 저장

	switch (Grade)                                       // Grade의 값이 얼마인지 확인
	{
	case 10:                                             // Grade가 10이면, 즉 점수가 90점 이상이면
		printf("학점 : A\n");                            // "학점 : A"를 출력
		break;

	case 9:                                              // Grade가 9이면, 즉 점수가 90점 이상이면
		printf("학점 : A\n");                            // "학점 : A"를 출력
		break;

	case 8:                                              // Grade가 8이면, 즉 점수가 90점 미만이자 80점 이상이면
		printf("학점 : B\n");                            // "학점 : B"를 출력
		break;

	case 7:                                              // Grade가 7이면, 즉 점수가 80점 미만이자 70점 이상이면
		printf("학점 : C\n");                            // "학점 : C"를 출력
		break;

	case 6:                                              // Grade가 6이면, 즉 점수가 70점 미만이자 60점 이상이면
		printf("학점 : D\n");                            // "학점 : D"를 출력
		break;

	default:                                             // 위 상황에 모두 해당하지 않으면, 즉 점수가 60점 미만이면
		printf("학점 : F\n");                            // "학점 : F"를 출력
		break;
	}

	return 0;                                            // 프로그램 종료
}