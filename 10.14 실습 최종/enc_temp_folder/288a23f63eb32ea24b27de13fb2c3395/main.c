#include <stdio.h>

int main(void)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	printf("¿øÇÏ´Â ¿¬»êÀ» ¼±ÅÃÇÏ½Ã¿À(1.µ¡¼À 2.»¬¼À 3.°ö¼À 4.³ª´°¼À :\n");
	scanf_s("%d", &a);

	printf("»çÄ¢¿¬»ê ÀÔ·Â(Á¤¼ö) :\n");
	scanf_s("%d %d, &b, &c");

	if (a == 1)
	{
		printf("%d, b+c");
	}
	else if (a == 2)
	{
		printf("%d, b-c");
	}
	else if (a == 3)
	{
		printf("%d, b*c");
	}
	else if (a == 4)
	{
		d = b / c;
	}

	printf("°á°ú°ª : %d\n", d);

	return 0;
}