#ifndef OP_FUNCTIONS4_H
#define OP_FUNCTIONS4_H
#include <stdio.h>
#include <conio.h>
#include <tgmath.h>
double getX (char *string) {
    double value;
    printf("%s", string);

    while (scanf(" %lf", &value) != 1 || value< -360 || value > 360) {
        printf("\nEnter the number in range from -360 to 360");
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
            printf("\nE cannot be more than 1e-1");
        } else if (e < 1e-16) {
            printf("\nE cannot be less than 1e-16");
        }
    }while(e > 1e-1 || e < 1e-16);
}

#endif //OP_FUNCTIONS4_H
