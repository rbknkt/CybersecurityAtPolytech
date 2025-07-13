#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>

double factorial(double a) {
    if (a == 0) {
        return 1.0;
    }
    else {
        double result = 1.0f;
        for (int q = 1; q <= a; q++) {
            result = result * q;
        }
        return result;
    }
}

double func(double x, unsigned int i) {
    double a = 2 * i - 1;
    return ((pow(-1, i + 1) * pow(x, 2 * i - 1)) / factorial(a));
}

int main(void) {
    SetConsoleOutputCP(1251);
    double x;
    unsigned int n;
    printf("Введите x: ");
    scanf_s("%lf", &x);
    printf("Введите n: ");
    scanf_s("%u", &n);
    double sn = 0.0f;
    double se = 0.0f;
    for (unsigned int i = 1; i <= n; i++) {
        if (sn + func(x, i) == sn) {
            break;
        }
        else {
            sn = sn + func(x, i);
        }
    }
    printf("Для указанного количества n: %.32lf\n", sn);
    while (x > 6.283185307179586476925286766559)
    {
        x -= 6.283185307179586476925286766559;
    }
    for (long i = 1; i < 4292967295; i++) {
        if (se + func(x, i) == se) {
            printf("Сумма с максимальной точностью для %ld членов: %.32lf\n", i, se);
            break;
        }
        else {
            se = se + func(x, i);
        }
    }
    _getch();
    return 0; 
}