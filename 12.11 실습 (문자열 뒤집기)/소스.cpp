#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[100];                        // �Է� ���ڿ��� ������ �迭
    char word[100];                         // ���� �ܾ ������ �迭
    int index = 0;                          // �ܾ��� �ε����� ������ ����

    printf("���ڿ��� �Է��Ͻÿ� : ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';     // ���� ���� ����

    char* ptr = input;                      // �Է� ���ڿ��� ��ȸ�� ������
    printf("������ ���ڿ� : ");

    while (*ptr != '\0')                    // �� �ܾ� ������
    {
        // �ܾ� �迭 �ʱ�ȭ
        for (int i = 0; i < sizeof(word); i++) 
        {
            word[i] = '\0';                 // NULL ���ڷ� �ʱ�ȭ
        }

        // ���� �ܾ� ����
        index = 0;
        while (*ptr != ' ' && *ptr != '\0') 
        {
            word[index++] = *ptr++;
        }
        word[index] = '\0';                 // �ܾ��� ���� NULL ���� �߰�

        // �ܾ� ������
        for (int i = 0; i < index / 2; i++) 
        {
            char temp = word[i];
            word[i] = word[index - i - 1];
            word[index - i - 1] = temp;
        }

        // ������ �ܾ� ���
        printf("%s ", word);

        // ���� ���� �ǳʶٱ�
        if (*ptr == ' ') 
        {
            ptr++;
        }
    }

    return 0;
}