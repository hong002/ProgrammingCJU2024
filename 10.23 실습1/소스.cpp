#include <stdio.h>

int main(void)
{
	int Number;                                                  // 몇단을 계산할지 Number로 표현하겠다
	int i;

	printf("구구단 몇단을 계산할지 입력하시오 : ");
	scanf_s("%d", &Number);

	for (i = 1; i <= 9; i++)                                    // 9번 반복하여 표현하겠다
	{
		printf("%d * %d = %d\n", Number, i, (Number * i));
	}

	return 0;
}