/*  작성자 : 2021010507 홍혁진
	제목 : Report #1 2번 문제 */

#include <stdio.h>                                                     // stdio.h 파일의 내용을 프로그램 안에 복사

int main(void)
{    
	int input_money;                                                   // 투입할 금액을 input_money라 하고 int형 변수로 선언
	int price;                                                         // 구입할 물건의 값을 price라 하고 int형 변수로 선언
	int out_money;                                                     // 거스름돈을 out_money라 하고 int형 변수로 선언

	printf("투입할 금액을 입력하시오 : ");                             // "투입할 금액을 입력하시오 : " 출력
	scanf_s("%d", &input_money);                                       // 변수 input_money에 값 입력

	printf("구입할 물건의 값을 입력하시오 : ");                        // "구입할 물건의 값을 입력하시오 : " 출력
	scanf_s("%d", &price);                                             // 변수 price에 값 입력

	out_money = input_money - price;                                   // input_money - price의 결과값을 out_money에 저장

	printf("거스름돈 : %d원\n", out_money);                              // %d 위치에 거스름돈(out_money)를 출력

	int paper_money1000 = out_money / 1000;                            // 거스름돈 1000원의 갯수를 paper_money1000이라 하고, out_money / 1000의 결과값을 paper_money1000에 저장
	out_money = out_money % 1000;                                      // 나머지를 구하기 위해 out_money % 1000를 하고, 결과값을 out_money에 저장
	int coin500 = out_money / 500;                                     // 거스름돈 500원의 갯수를 coin500이라 하고, out_money / 500의 결과값을 coin500에 저장
	out_money = out_money % 500;                                       // 나머지를 구하기 위해 out_money % 500를 하고, 결과값을 out_money에 저장
	int coin100 = out_money / 100;                                     // 거스름돈 100원의 갯수를 coin100이라 하고, out_money / 100의 결과값을 coin100에 저장
	out_money = out_money % 100;                                       // 나머지를 구하기 위해 out_money % 100를 하고, 결과값을 out_money에 저장

	printf("거스름돈 1000원의 갯수 : %d개\n", paper_money1000);        // %d위치에 거스름돈 1000원의 갯수(paper_money1000)를 출력
	printf("거스름돈 500원의 갯수 : %d개\n", coin500);                 // %d위치에 거스름돈 500원의 갯수(coin500)를 출력
	printf("거스름돈 100원 갯수 : %d개\n", coin100);                   // %d위치에 거스름돈 100원의 갯수(coin100)를 출력

	return 0;                                                          // 프로그램 종료
}