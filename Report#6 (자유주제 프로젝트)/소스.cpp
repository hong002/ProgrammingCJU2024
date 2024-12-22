#include <stdio.h>
#include <stdlib.h>

// ����ü�� ������ ���� ����
typedef struct 
{
    double Q;                // �ý��ۿ� ���� ��
    double W;                // �ý����� �� ��
    double delta_U;          // ���� �������� ��ȭ
} Thermodynamic_Data;

// �� Q�� ������ �о���� �Լ�
void Load_Data_Q(const char* FileName, Thermodynamic_Data data[], int* count) 
{
    FILE* file;
    if (fopen_s(&file, FileName, "r") != 0) 
    {
        perror("Q �� ���� ���� ����, �ٽ� �õ��Ͻÿ�.");
        exit(1);
    }

    while (fscanf_s(file, "%lf", &data[*count].Q) == 1) 
    {
        (*count)++;
    }

    fclose(file);
}

// �� W�� ������ �о���� �Լ�
void Load_Data_W(const char* FileName, Thermodynamic_Data data[], int count)
{
    FILE* file;
    if (fopen_s(&file, FileName, "r") != 0) 
    {
        perror("W �� ���� ���� ����, �ٽ� �õ��Ͻÿ�");
        exit(1);
    }

    for (int i = 0; i < count; i++) 
    {
        fscanf_s(file, "%lf", &data[i].W);
    }

    fclose(file);
}

// ���� ������ ��ȭ�� ����ϴ� �Լ�
void Calculate_Energy_Change(Thermodynamic_Data* data, int count)
{
    for (int i = 0; i < count; i++) 
    {
        data[i].delta_U = data[i].Q - data[i].W;       // ���� ������ ��ȭ ���
    }
}

// ����� �����ϴ� �Լ�
void Save_Results(const char* FileName, Thermodynamic_Data data[], int count)
{
    FILE* file;
    if (fopen_s(&file, FileName, "w") != 0) 
    {
        perror("��� ���� ���� ����, �ٽ� �õ��Ͻÿ�.");
        exit(1);
    }

    for (int i = 0; i < count; i++) 
    {
        fprintf(file, "Q: %.2f kJ,   W: %.2f kJ,   ��U: %.2f kJ\n", data[i].Q, data[i].W, data[i].delta_U);
    }

    fclose(file);
}

int main(void) 
{
    Thermodynamic_Data data[100];
    int count = 0;

    // Q �� ������ ���� �ε�
    Load_Data_Q("C:\\Users\\elsa3\\Downloads\\data_1.txt", data, &count);

    // W �� ������ ���� �ε�
    Load_Data_W("C:\\Users\\elsa3\\Downloads\\data_2.txt", data, count);

    // ���� ������ ��ȭ ���
    Calculate_Energy_Change(data, count);

    // ��� ���� ����
    Save_Results("results.txt", data, count);

    printf("����� results.txt�� ����Ǿ����ϴ�.\n");
    return 0;
}