#include <stdio.h>
#include <math.h>

// Структура для зберігання даних
struct Data {
    double x;
    double a;
    double b;
    double result;
};

// Функція перевірки вхідних змінних
int validateInput(struct Data data) {
    if (data.b == 0 || sin(data.b * data.x) == 0 || (data.x / data.a - 0.39) < 0) {
        return 0; // Неприпустимі значення
    }
    return 1; // Дані коректні
}

// Функція розрахунку математичної функції
double calculateFunction(struct Data data) {
    return ((pow(data.x, 2) + 1) - (1 / sin(data.b * data.x))) / cbrt(data.x / data.a - 0.39);
}

// Головна функція
int main() {
    struct Data data;

    // Введення даних
    printf("Введіть значення x: ");
    scanf("%lf", &data.x);
    printf("Введіть значення a: ");
    scanf("%lf", &data.a);
    printf("Введіть значення b: ");
    scanf("%lf", &data.b);

    // Перевірка вхідних даних
    if (!validateInput(data)) {
        printf("Помилка: введені некоректні значення, що не відповідають умовам задачі.\n");
        return 1;
    }

    // Обчислення функції
    data.result = calculateFunction(data);

    // Виведення результату
    printf("Результат обчислення: y = %.5lf\n", data.result);

    return 0;
}