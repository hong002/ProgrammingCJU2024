#include <stdio.h>

int main(void)
{
	double ft = 0.0;
	double inch = 0.0;
	double kg = 0.0;

	printf("ft, inch, kg�� �Է��Ͻÿ�");
	scanf_s("%lf %lf %lf", &ft, &inch, &kg);
	printf("ft, m ��ȯ : %.4lf\n", ft * 1 / 3.28);
	printf("inch, m ��ȯ : %.4lf\n", inch * 1 / 39.37);
	printf("kg, slug ��ȯ : % .4lf\n", kg * 1 / 14.59);

	return 0;
}