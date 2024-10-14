#include <stdio.h>

int main(void)
{
	int a = 0;
	int b = 0;
	int c = 0;

	printf("원하는 연산을 선택하시오 (1.덧셈 2.뺄셈 3.곱셈 4.나눗셈) :\n");
	scanf_s("%d", &a);

	printf("사칙연산 입력(정수) :\n");
	scanf_s("%d %d", &b, &c);

	if (a == 1)
	{
		printf("결과값 : %d\n", b + c);
	}
	else if (a == 2)
	{
		printf("결과값 : %d\n", b - c);
	}
	else if (a == 3)
	{
		printf("결과값 : %d\n", b * c);
	}
	else if (a == 4)
	{
		printf("결과값 : %d\n", b / c);
	}

	return 0;
}