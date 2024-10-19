/*  작성자 : 2021010507 홍혁진
    제목 : Report #1 1번 문제 */

#include <stdio.h>                                                                     // stdio.h 파일의 내용을 프로그램 안에 복사

int main(void)
{
	double a, b, c, d;                                                                 // double형 변수 a, b, c, d 선언
	double res1, res2, res3, res4 = 0.0;                                               // double형 변수 res1, res2, res3, res4 선언
	double Degree = 0.0;                                                               // double형 변수 Degree 선언
	
	a = 180.0;                                                                         // double형 변수 a에 실수 180.0 대입
	b = 1.0;                                                                           // double형 변수 b에 실수 1.0 대입
	c = -1.0;                                                                          // double형 변수 c에 실수 -1.0 대입
	d = 360.0;                                                                         // double형 변수 d에 실수 360.0 대입
	
	printf("계산할 각도값을 입력하시오\t (계산할 각도값이 360 이하값일 경우)");        // "계산할 각도값을 입력하시오"를 출력하고 탭 위치로 이동(\t) 후에 "(계산할 각도값이 360 이하값일 경우)"를 출력
	scanf_s("%lf", &Degree);                                                           // 계산할 각도값 Degree을 입력
	res1 = Degree * c + a;                                                             // 연산 결과를 res1에 저장
	res2 = Degree * b;                                                                 // 연산 결과를 res2에 저장
	Degree = (Degree > a) ? res1 : res2;                                               // Degree가 a보다 클 경우 res1값을 Degree에 저장하고, Degree가 a보다 크지않을 경우 res2값을 Degree에 저장
	printf("변환된 자세값 : %.2lf [deg.]\n", Degree);                                  // "변환된 자세값 : [deg.]"를 출력하고 줄 바꿈(\n)
	printf("계산할 각도값을 입력하시오\t (계산할 각도값이 360 초과값일 경우)");        // "계산할 각도값을 입력하시오"를 출력하고 탭 위치로 이동(\t) 후에 "(계산할 각도값이 360 초과값일 경우)"를 출력
	scanf_s("%lf", &Degree);                                                           // 계산할 각도값 Degree을 입력
	res3 = Degree * c + a + d;                                                         // 연산 결과를 res3에 저장
	res4 = Degree * b - d;                                                             // 연산 결과를 res4에 저장
	Degree = (Degree > (a + d)) ? res3 : res4;                                         // Degree가 (a+d)보다 클 경우 res3값을 Degree에 저장하고, Degree가 (a+d)보다 크지않을 경우 res4값을 Degree에 저장
	printf("변환된 자세값 : %.2lf [deg.]\n", Degree);                                  // "변환된 자세값 : [deg.]"를 출력하고 줄 바꿈(\n)

	return 0;                                                                          // 프로그램 종료
}