#include <stdio.h>

int main(void)
{
	int length = 0;
	int height = 0;
	double radius = 0.0;

	printf("길이와 넓이, 반지름을 입력하시오");
	scanf_s("%d %d %lf", &length, &height, &radius);
	printf("삼각형의 넓이 : %d\n", length * height*1/2);
	printf("사각형의 넓이 : %d\n", length * height);
	printf("원의 넓이 : %.2lf\n", radius * radius * 3.14);
	printf("구의 표면적 : %.2lf\n", radius * radius * 3.14 * 4);
	printf("구의 체적 : %.2lf\n", radius * radius * radius * 3.14 * 4 / 3);

	return 0;
}