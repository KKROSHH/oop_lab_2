#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

struct InputData {
    double a, b, x, y; // Параметри
    int flag; //Для вибору функції
};


int CheckBounds(double x) {
    if (x <= 1) return 1;
    if (x > 1 && x <= 3) return 2;
    if (x > 3) return 3;
    return 0;  // Для помилки, якщо значення некоректне
}

double func1(double x, double a) { // Випадок x <= 1
    return cbrt(x*x + fabs(a));  // Кубічний корінь і модуль значення
}

double func2(double x, double a, double b) { // Випадок 1 < x <= 3
    return pow(sin(a * x), 2) * pow(cos(b * x), 2);  // sin^2(ax) * cos^2(bx)
}

double func3(double x, double a, double b) { // Випадок x > 3
    return fabs(a + x + b);  // Модуль значення
}

void calculate(InputData &data) {
    switch (data.flag) {
        case 1:
            data.y = func1(data.x, data.a);
            break;
        case 2:
            data.y = func2(data.x, data.a, data.b);
            break;
        case 3:
            data.y = func3(data.x, data.a, data.b);
            break;
        default:
            cout << "Error: Invalid input." << endl;
            return;
    }
}


int main() {
    InputData data;

    // Введення значень a, b, x, y
    cout << "Enter a: ";
    cin >> data.a;
    cout << "Enter b: ";
    cin >> data.b;
    cout << "Enter x: ";
    cin >> data.x;

    // Визначення меж на основі значення x
    data.flag = CheckBounds(data.x);

    // Виклик функції для розрахунку
    calculate(data);

    // Виведення результату
    cout << "Input: a = " << data.a << ", b = " << data.b << ", x = " << data.x << endl;
    cout << "Result y = " << data.y << endl;
    system("pause");

}
