#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 열거형으로 과목 정의
typedef enum 
{
    SUBJECT_KOREAN,
    SUBJECT_ENGLISH,
    SUBJECT_MATH,
    SUBJECT_COUNT
} Subject;

// 구조체로 학생 정보 정의
typedef struct 
{
    char Student_Name[50];
    int Student_Number;
    int Student_Scores[SUBJECT_COUNT];
    double Average_Scores;
    int Student_ClassRank;
    int Student_All_Rank;
} Student;

void Load_Students(FILE* File, Student Students[], int* Student_Count);
void Calculate_Average(Student Students[], int Student_Count);
void Calculate_Rank(Student Students[], int Student_Count);
void Calculate_All_Rank(Student Students[], int Student_Count);
void Save_Result(const char* FileName, Student Students[], int Student_Count);
void Save_Class_Summary(const char* fileName, Student students1[], int nCount1, Student students2[], int nCount2);

// 학생 정보를 읽어오는 함수
void Load_Students(FILE* File, Student Students[], int* Student_Count) 
{
    while (fscanf_s(File, "%49s %d %d %d %d",
        Students[*Student_Count].Student_Name, (unsigned)_countof(Students[*Student_Count].Student_Name),
        &Students[*Student_Count].Student_Number,
        &Students[*Student_Count].Student_Scores[SUBJECT_KOREAN],
        &Students[*Student_Count].Student_Scores[SUBJECT_ENGLISH],
        &Students[*Student_Count].Student_Scores[SUBJECT_MATH]) == 5)
    {
        (*Student_Count)++;
    }
}

// 평균 점수를 계산하는 함수
void Calculate_Average(Student Students[], int Student_Count)
{
    for (int i = 0; i < Student_Count; i++)
    {
        int Scores_Total = 0;
        for (int j = 0; j < SUBJECT_COUNT; j++) 
        {
            Scores_Total = Scores_Total + Students[i].Student_Scores[j];
        }
        Students[i].Average_Scores = Scores_Total / (double)SUBJECT_COUNT;
    }
}

// 등수를 계산하는 함수
void Calculate_Rank(Student Students[], int Student_Count)
{
    for (int i = 0; i < Student_Count; i++)
    {
        int Rank = 1;
        for (int j = 0; j < Student_Count; j++)
        {
            if (Students[j].Average_Scores > Students[i].Average_Scores) 
            {
                Rank++;
            }
        }
        Students[i].Student_ClassRank = Rank;
    }
}

// 전체 등수를 계산하는 함수
void Calculate_All_Rank(Student Students[], int Student_Count)
{
    for (int i = 0; i < Student_Count; i++)
    {
        int Rank = 1;
        for (int j = 0; j < Student_Count; j++)
        {
            if (Students[j].Average_Scores > Students[i].Average_Scores)
            {
                Rank++;
            }
        }
        Students[i].Student_All_Rank = Rank;
    }
}

// 결과를 저장하는 함수
void Save_Result(const char* FileName, Student Students[], int Student_Count) 
{
    FILE* file;
    if (fopen_s(&file, FileName, "w") != 0) 
    {
        perror("파일 쓰기 실패, 다시 시도하시오");
        exit(1);
    }

    for (int i = 0; i < Student_Count; i++) 
    {
        fprintf(file, "학번: %d\n이름: %s\n국어: %d\n영어: %d\n수학: %d\n평균 점수: %.2f\n분반 내 등수: %d\n전체 등수: %d\n\n",
            Students[i].Student_Number,
            Students[i].Student_Name,
            Students[i].Student_Scores[SUBJECT_KOREAN],
            Students[i].Student_Scores[SUBJECT_ENGLISH],
            Students[i].Student_Scores[SUBJECT_MATH],
            Students[i].Average_Scores,
            Students[i].Student_ClassRank,
            Students[i].Student_All_Rank);
    }
    fclose(file);
}

// 요약 저장하는 함수
void Save_Class_Summary(const char* FileName, Student Students1[], int Count1, Student Students2[], int Count2) 
{
    FILE* file;
    if (fopen_s(&file, FileName, "w") != 0) 
    {
        perror("파일 쓰기 실패, 다시 시도하시오");
        exit(1);
    }

    double Sum_Class1 = 0, Sum_Class2 = 0;
    for (int i = 0; i < Count1; i++) 
    {
        Sum_Class1 = Sum_Class1 + Students1[i].Average_Scores;
    }
    for (int i = 0; i < Count2; i++) 
    {
        Sum_Class2 = Sum_Class2 + Students2[i].Average_Scores;
    }

    fprintf(file, "분반 1의 평균: %.2f\n", Count1 > 0 ? Sum_Class1 / Count1 : 0);
    fprintf(file, "분반 2의 평균: %.2f\n", Count2 > 0 ? Sum_Class2 / Count2 : 0);
    fprintf(file, "전체 평균: %.2f\n", (Count1 + Count2) > 0 ? (Sum_Class1 + Sum_Class2) / (Count1 + Count2) : 0);

    fclose(file);
}

int main(void) 
{
    Student Student_Class1[100], Student_Class2[100];
    int Student_Count1 = 0, Student_Count2 = 0;

    // 파일 포인터 생성
    FILE* file1;
    FILE* file2;

    if (fopen_s(&file1, "C:\\Users\\elsa3\\Downloads\\students_1.txt", "r") != 0) 
    {
        perror("students_1.txt 열기 실패, 다시 시도하시오.");
        exit(1);
    }

    if (fopen_s(&file2, "C:\\Users\\elsa3\\Downloads\\students_2.txt", "r") != 0) 
    {
        perror("students_2.txt 열기 실패, 다시 시도하시오.");
        fclose(file1);
        exit(1);
    }

    // 학생 정보 파일 로드
    Load_Students(file1, Student_Class1, &Student_Count1);
    Load_Students(file2, Student_Class2, &Student_Count2);

    fclose(file1);
    fclose(file2);

    // 평균 및 등수 계산
    Calculate_Average(Student_Class1, Student_Count1);
    Calculate_Average(Student_Class2, Student_Count2);
    Calculate_Rank(Student_Class1, Student_Count1);
    Calculate_Rank(Student_Class2, Student_Count2);

    // 파일 저장
    Save_Result("students_1_results.txt", Student_Class1, Student_Count1);
    Save_Result("students_2_results.txt", Student_Class2, Student_Count2);
    Save_Class_Summary("class_results.txt", Student_Class1, Student_Count1, Student_Class2, Student_Count2);

    printf("결과 파일이 성공적으로 생성되었습니다!\n");
    return 0;
}