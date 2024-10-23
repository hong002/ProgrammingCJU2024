#include <stdio.h>

int main(void)
{
	int a;                                                  // 몇단을 계산할지 Number로 표현하겠다
	int i, j;

	printf("구구단 몇단을 계산할지 입력하시오 : ");
	scanf_s("%d", &a);

	switch (a)
	{
	case 10:
		for (i = 1; i <= 9; i++)                                    // 9번 반복하여 표현하겠다
		{
			for (j = 1; j <= 9; j++)
			{
				printf("%d * %d = %2d\n", j, i, (j * i));
			}
			printf("\n");
		}
		break;
	default :
		for (i = 1; i <= 9; i++)
		{
			printf("%d * %d = %d\n", a, i, (a * i));
		}
		break;
	}

	return 0;
}