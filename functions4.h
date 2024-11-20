#ifndef OP_FUNCTIONS4_H
#define OP_FUNCTIONS4_H
#include <stdio.h>
#include <conio.h>
#include <math.h>

double getX (char *string) {
    double value;
    printf("%s", string);

    while (scanf(" %lf", &value) != 1 || value< -360 || value > 360) {
        printf("\nInvalid input. Enter the number in range from -360 to 360");
        fflush(stdin);
        printf("%s", string);
    }

    return value;
}

double getD(double x1, double x2){
    double dx;

    do {
        printf("\nEnter dx - ");
        scanf("%lf", &dx);
        fflush(stdin);

        if (x1 != x2 && dx == 0) {
            printf("\nIn this case, dx cannot be equal to 0");

        } else if (x1 < x2 && dx < 0) {
            printf("\nIn this case, dx cannot be negative");

        } else if (x1 > x2 && dx > 0) {
            printf("\nIn this case, dx cannot be positive");

        }
    }while(x1 != x2 && dx == 0||
            x1 < x2 && dx < 0||
            x1 > x2 && dx > 0);
    return dx;
}

double getE(){
    double e;
    do {
        printf("\nEnter e in range from 1e-16 to 1e-1");
        scanf("%lf", &e);
        fflush(stdin);
        if (e > 1e-1) {
            printf("\nInvalid input. E cannot be more than 1e-1");
        } else if (e < 1e-16) {
            printf("\nInvalid input. E cannot be less than 1e-16");
        }
    }while(e > 1e-1 || e < 1e-16);
    return e;
}


int getPrecision(double e) {
    int precision = 0;
    while (e < 1) {
        e *= 10;
        precision++;
    }
    return precision;
}


int getOPT() {
    int opt = 0;

    printf("\nChoose sin(1) or cos(2): ");
    while (scanf("%d", &opt) != 1 || (opt != 1 && opt != 2)) {
        printf("\nInvalid input. Please enter 1 for sin or 2 for cos:");
        fflush(stdin);
    }

    return opt;
}

unsigned long long factorial (int n) {
    if (n == 0) return 1;

    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }

    return fact;
}

double sin_Taylor(double x, double e) {
    double delta = x;
    double result = x;
    int n = 1;

    while (fabs(delta) > e) {
        delta *= (-x * x) / ((2 * n) * (2 * n + 1)); // Наступний член
        result += delta; // Додати член до результату
        n++;
    }

    return result;
}

double cos_Taylor(double x, double e) {
    double delta = 1; // Перший член ряду Тейлора
    double result = 1; // Початкове значення
    int n = 1;

    while (fabs(delta) > e) {
        delta *= (-x * x) / (2 * n * (2 * n - 1));
        result += delta;
        n++;
    }

    return result;
}

#endif //OP_FUNCTIONS4_H
