#include <stdio.h>
#include <math.h>

// 3차원 공간의 점을 표현하는 구조체 함수
struct Point
{
    double x;                // x 좌표
    double y;                // y 좌표
    double z;                // z 좌표
};

// 두 점 사이의 거리를 계산하는 함수
double Calculate_Distance(struct Point p1, struct Point p2) 
{
    double res;
    res = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));      // 거리 계산 공식 적용
    return res;
}

int main(void) 
{
    struct Point point1, point2;                                            // 두 점을 저장할 구조체 변수 선언

    printf("첫번째 점의 좌표를 입력하시오 (x, y, z): ");
    scanf_s("%lf %lf %lf", &point1.x, &point1.y, &point1.z);                // 점 1에 대한 좌표 입력

    printf("두번째 점의 좌표를 입력하시오 (x, y, z): ");
    scanf_s("%lf %lf %lf", &point2.x, &point2.y, &point2.z);                // 점 2에 대한 좌표 입력

    double Euclldean_Distance = Calculate_Distance(point1, point2);         // 거리 계산 함수 호출
    printf("The distance between the two points is: %.2f\n", Euclldean_Distance);

    return 0;
}