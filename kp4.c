#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "functions4.h"


int main() {
    printf("vb\n");

    do {
        double x1 = 0, x2 = 0, dx = 0, e = 0;
        //int opt = 0;

        x1 = getX("\nEnter x1 in range from -360 to 360 -  ");
        x2 = getX("\nEnter x2 in range from -360 to 360 -  ");
        dx = getD(x1, x2);
        e = getE();

        x1 = x1 * M_PI / 180.0;
        x2 = x2 * M_PI / 180.0;
        dx = dx * M_PI / 180.0;


        printf("\nPress ENTER to restart, any key to exit...");
    } while (getch() == 13);

    return 0;
}
