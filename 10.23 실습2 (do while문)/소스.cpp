#include <stdio.h>

int main(void)
{
	int Number1, Number2;                                                     // 입력할 두가지 숫자를 각각 Number1, Number2라 한다
	int Result1, Result2 = 0;                                                 // 최대공약수는 Result1, 최소공배수는 Result2라 한다
	int i;

	printf("최대공약수, 최소공배수를 구한 두가지 숫자를 입력하시오 : ");
	scanf_s("%d %d", &Number1, &Number2);

	i = 2;                                                                    // i는 2부터 시작한다

	do
	{
		if (Number1 % i == 0 && Number2 % i == 0)                             // 두 수를 나누어서 둘 다 나누어 떨어지면 공약수이다
			Result1 = i;
		i = i++;
		break;
	} while (i <= Number1 && i <= Number2);                                   // i가 두 숫자보다 같거나 작으면 i를 1씩 증가시키면서 공약수를 찾는다

	Result2 = Number1 * Number2 / Result1;                                    // 두 숫자를 곱한 값을 최대공약수로 나누어 최소공배수를 구한다

	printf(" %d과 %d의 최대공약수는 %d이다.\n", Number1, Number2, Result1);
	printf(" %d과 %d의 최소공배수는 %d이다.\n", Number1, Number2, Result2);

	return 0;
}