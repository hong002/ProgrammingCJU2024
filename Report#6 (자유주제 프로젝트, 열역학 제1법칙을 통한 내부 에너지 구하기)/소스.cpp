#include <stdio.h>
#include <stdlib.h>

// 구조체로 열역학 정보 정의
typedef struct 
{
    double Q;                // 시스템에 들어온 열
    double W;                // 시스템이 한 일
    double delta_U;          // 내부 에너지의 변화
} Thermodynamic_Data;

// 열 Q의 정보를 읽어오는 함수
void Load_Data_Q(const char* FileName, Thermodynamic_Data data[], int* count) 
{
    FILE* file;
    if (fopen_s(&file, FileName, "r") != 0) 
    {
        perror("Q 값 파일 열기 실패, 다시 시도하시오.");
        exit(1);
    }

    while (fscanf_s(file, "%lf", &data[*count].Q) == 1) 
    {
        (*count)++;
    }

    fclose(file);
}

// 일 W의 정보를 읽어오는 함수
void Load_Data_W(const char* FileName, Thermodynamic_Data data[], int count)
{
    FILE* file;
    if (fopen_s(&file, FileName, "r") != 0) 
    {
        perror("W 값 파일 열기 실패, 다시 시도하시오");
        exit(1);
    }

    for (int i = 0; i < count; i++) 
    {
        fscanf_s(file, "%lf", &data[i].W);
    }

    fclose(file);
}

// 내부 에너지 변화를 계산하는 함수
void Calculate_Energy_Change(Thermodynamic_Data* data, int count)
{
    for (int i = 0; i < count; i++) 
    {
        data[i].delta_U = data[i].Q - data[i].W;       // 내부 에너지 변화 계산
    }
}

// 결과를 저장하는 함수
void Save_Results(const char* FileName, Thermodynamic_Data data[], int count)
{
    FILE* file;
    if (fopen_s(&file, FileName, "w") != 0) 
    {
        perror("결과 파일 쓰기 실패, 다시 시도하시오.");
        exit(1);
    }

    for (int i = 0; i < count; i++) 
    {
        fprintf(file, "Q: %.2f kJ,   W: %.2f kJ,   ΔU: %.2f kJ\n", data[i].Q, data[i].W, data[i].delta_U);
    }

    fclose(file);
}

int main(void) 
{
    Thermodynamic_Data data[100];
    int count = 0;

    // Q 값 데이터 파일 로드
    Load_Data_Q("C:\\Users\\elsa3\\Downloads\\data_1.txt", data, &count);

    // W 값 데이터 파일 로드
    Load_Data_W("C:\\Users\\elsa3\\Downloads\\data_2.txt", data, count);

    // 내부 에너지 변화 계산
    Calculate_Energy_Change(data, count);

    // 결과 파일 저장
    Save_Results("results.txt", data, count);

    printf("결과가 results.txt에 저장되었습니다.\n");
    return 0;
}