#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[100];                        // 입력 문자열을 저장할 배열
    char word[100];                         // 개별 단어를 저장할 배열
    int index = 0;                          // 단어의 인덱스를 추적할 변수

    printf("문자열을 입력하시오 : ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';     // 개행 문자 제거

    char* ptr = input;                      // 입력 문자열을 순회할 포인터
    printf("뒤집힌 문자열 : ");

    while (*ptr != '\0')                    // 각 단어 뒤집기
    {
        // 단어 배열 초기화
        for (int i = 0; i < sizeof(word); i++) 
        {
            word[i] = '\0';                 // NULL 문자로 초기화
        }

        // 현재 단어 추출
        index = 0;
        while (*ptr != ' ' && *ptr != '\0') 
        {
            word[index++] = *ptr++;
        }
        word[index] = '\0';                 // 단어의 끝에 NULL 문자 추가

        // 단어 뒤집기
        for (int i = 0; i < index / 2; i++) 
        {
            char temp = word[i];
            word[i] = word[index - i - 1];
            word[index - i - 1] = temp;
        }

        // 뒤집힌 단어 출력
        printf("%s ", word);

        // 공백 문자 건너뛰기
        if (*ptr == ' ') 
        {
            ptr++;
        }
    }

    return 0;
}