#include <stdio.h>
#include <math.h>


double degree_radian(double degree)                                        // 라디안 변환하는 식
{
	return degree * (3.14 / 180.0);
}

int main(void)
{
	double radians, degree;
	double sin_value, cos_value;

	printf("각도를 입력하시오 : ");
	scanf_s("%lf", &degree);

	radians = degree_radian(degree);

	sin_value = sin(radians);
	cos_value = cos(radians);

	if (degree < 0 || degree>180)
	{
		printf("다시 시도하시오.\n");
	}
	else
	{
		printf("sin(%lf) = %lf\n", degree, sin_value);
		printf("cos(%lf) = %lf\n", degree, cos_value);
	}

	return 0;
}