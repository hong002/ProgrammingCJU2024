#include <stdio.h>
#include <math.h>

// 3���� ������ ���� ǥ���ϴ� ����ü �Լ�
struct Point
{
    double x;                // x ��ǥ
    double y;                // y ��ǥ
    double z;                // z ��ǥ
};

// �� �� ������ �Ÿ��� ����ϴ� �Լ�
double Calculate_Distance(struct Point p1, struct Point p2) 
{
    double res;
    res = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));      // �Ÿ� ��� ���� ����
    return res;
}

int main(void) 
{
    struct Point point1, point2;                                            // �� ���� ������ ����ü ���� ����

    printf("ù��° ���� ��ǥ�� �Է��Ͻÿ� (x, y, z): ");
    scanf_s("%lf %lf %lf", &point1.x, &point1.y, &point1.z);                // �� 1�� ���� ��ǥ �Է�

    printf("�ι�° ���� ��ǥ�� �Է��Ͻÿ� (x, y, z): ");
    scanf_s("%lf %lf %lf", &point2.x, &point2.y, &point2.z);                // �� 2�� ���� ��ǥ �Է�

    double Euclldean_Distance = Calculate_Distance(point1, point2);         // �Ÿ� ��� �Լ� ȣ��
    printf("The distance between the two points is: %.2f\n", Euclldean_Distance);

    return 0;
}