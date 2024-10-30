#include <stdio.h>

double Ctemperature(double C);                                                           // ¼·¾¾¿Âµµ ¼±¾ð
double Ftemperature(double F);                                                           // È­¾¾¿Âµµ ¼±¾ð

int main(void)
{
	int choice;
	double C, F;
	double result;                                                                       // º¯È¯µÈ °ª ¼±¾ð

	printf("º¯È¯ÇÒ ¿ÂµµÁ¾·ù¸¦ ¼±ÅÃÇÏ½Ã¿À. (1¹ø: ¼·¾¾->È­¾¾. 2¹ø: È­¾¾->¼·¾¾) : ");
	scanf_s("%d", &choice);
	
	if (choice == 1)                                                                     // ¼·¾¾->È­¾¾ ¸¦ ¿øÇÒ °æ¿ì
	{
		printf("¼·¾¾ ¿Âµµ¸¦ ÀÔ·ÂÇÏ½Ã¿À : ");
		scanf_s("%lf", &C);
		result = Ctemperature(C);
		printf("È­¾¾ ¿Âµµ : %.2lf\n", result);
	}
	else if (choice == 2)                                                                // È­¾¾->¼·¾¾ ¸¦ ¿øÇÒ °æ¿ì
	{
		printf("È­¾¾ ¿Âµµ¸¦ ÀÔ·ÂÇÏ½Ã¿À : ");
		scanf_s("%lf", &F);
		result = Ftemperature(F);
		printf("¼·¾¾ ¿Âµµ : %.2lf\n", result);
	}
	else
	{
		printf("´Ù½Ã ½ÃµµÇÏ½Ã¿À");
	}

	return 0;
}

double Ctemperature(double C)
{
	return C * 9.0 / 5.0 + 32;                                                           // ¼·¾¾->È­¾¾ º¯È¯ °ø½Ä »ç¿ë
}
double Ftemperature(double F)
{
	return (F - 32) * 5.0 / 9.0;                                                         // È­¾¾->¼·¾¾ º¯È¯ °ø½Ä »ç¿ë
}