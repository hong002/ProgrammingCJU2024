#include <stdio.h>

int main(void)
{
	char sentence[100];
	int cnt = 0;
	int i = 0;

	printf("������ �Է��Ͻÿ� :");
	fgets(sentence, sizeof(sentence), stdin);

	for (i = 0; sentence[i] != '\0'; i++)
	{
		if (sentence[i] >= 'A' && sentence[i] <= 'Z')
		{
			sentence[i] = sentence[i] + ('a' - 'A');
			cnt++;
		}
	}

	printf("��ȯ�� ���� : ");
	puts(sentence);
	printf("��ȯ�� ������ �� : %d\n", cnt);

	return 0;
}