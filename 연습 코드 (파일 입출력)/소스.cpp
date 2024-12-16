#include <stdio.h>

int main(void)
{
	FILE* fp;
	char str[] = "banana";
	int i;

	fopen_s(&fp, "b.txt", "w");
	if (fp == NULL)
	{
		printf("파일을 만들지 못했다.\n");
		return 0;
	}

	i = 0;
	while (str[i] != '\0')
	{
		fputc(str[i], fp);
		i++;
	}

	fputc('\n', fp);
	fclose(fp);

	return 0;
}