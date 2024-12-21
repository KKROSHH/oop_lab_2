#include <stdio.h>
#include <math.h>

// ��������� ��� ��������� �����
struct Data {
    double x;
    double a;
    double b;
    double result;
};

// ������� �������� ������� ������
int validateInput(struct Data data) {
    if (data.b == 0 || sin(data.b * data.x) == 0 || (data.x / data.a - 0.39) < 0) {
        return 0; // ����������� ��������
    }
    return 1; // ��� �������
}

// ������� ���������� ����������� �������
double calculateFunction(struct Data data) {
    return ((pow(data.x, 2) + 1) - (1 / sin(data.b * data.x))) / cbrt(data.x / data.a - 0.39);
}

// ������� �������
int main() {
    struct Data data;

    // �������� �����
    printf("������ �������� x: ");
    scanf("%lf", &data.x);
    printf("������ �������� a: ");
    scanf("%lf", &data.a);
    printf("������ �������� b: ");
    scanf("%lf", &data.b);

    // �������� ������� �����
    if (!validateInput(data)) {
        printf("�������: ������ ��������� ��������, �� �� ���������� ������ ������.\n");
        return 1;
    }

    // ���������� �������
    data.result = calculateFunction(data);

    // ��������� ����������
    printf("��������� ����������: y = %.5lf\n", data.result);

    return 0;
}