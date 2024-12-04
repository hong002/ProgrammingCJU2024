#include <stdio.h>

int main(void)
{
	char sentence[100];
	int cnt = 0;
	int i = 0;

	printf("문장을 입력하시오 :");
	fgets(sentence, sizeof(sentence), stdin);

	for (i = 0; sentence[i] != '\0'; i++)
	{
		if (sentence[i] >= 'A' && sentence[i] <= 'Z')
		{
			sentence[i] = sentence[i] + ('a' - 'A');
			cnt++;
		}
	}

	printf("변환된 문장 : ");
	puts(sentence);
	printf("변환된 문자의 수 : %d\n", cnt);

	return 0;
}