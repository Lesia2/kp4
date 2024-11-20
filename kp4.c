#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "function4.h"
#define max 1000 // Максимальна кількість значень для зберігання у масивах

int main() {
    printf("This program calculates sin(x)/cos(x) using Taylor row and compares results with table values \n");

    do {
        double x1 = 0, x2 = 0, dx = 0, e = 0;
        int opt = 0;

        // Отримуємо вхідні дані
        x1 = getX("\nEnter x1 in range from -360 to 360 -  ");
        x2 = getX("\nEnter x2 in range from -360 to 360 -  ");
        dx = getD(x1, x2);
        e = getE();

        int precision = getPrecision(e);
        char format[50];
        snprintf(format, sizeof(format), "%%17.f %%17.%df %%17.%df %%17.6e\n", precision, precision);

        opt = getOPT();

        x1 = x1 * M_PI / 180.0;
        x2 = x2 * M_PI / 180.0;
        dx = dx * M_PI / 180.0;

        // Ініціалізація масивів
        double x_values[max], table_values[max], taylor_values[max], differences[max];
        int count = 0;

        if (opt == 1) { // Для sin(x)
            printf("\n%17s %17s %17s %17s\n", "x(deg)", "sin(x)", "sin_Taylor", "Difference");
            printf("%17s %17s %17s %17s\n", "-----------------", "-----------------", "-----------------", "-----------------");

            // Заповнення
            for (double x = x1; (dx > 0) ? (x <= x2) : (x >= x2); x += dx) {
                double sin_x = sin(x);
                double sin_T = sin_Taylor(x, e);

                x_values[count] = x * 180.0 / M_PI; // Перетворюємо у градуси
                table_values[count] = sin_x;
                taylor_values[count] = sin_T;
                differences[count] = fabs(sin_x - sin_T);

                count++;
            }

            // Виведення результатів
            for (int i = 0; i < count; i++) {
                printf(format,
                       x_values[i],
                       table_values[i],
                       taylor_values[i],
                       differences[i]);
            }
        }

        if (opt == 2) { // Для cos(x)
            printf("\n%17s %17s %17s %17s\n", "x(deg)", "cos(x)", "cos_Taylor", "Difference");
            printf("%17s %17s %17s %17s\n", "---------------", "---------------", "---------------", "---------------");

            for (double x = x1; (dx > 0) ? (x <= x2) : (x >= x2); x += dx) {
                double cos_x = cos(x);
                double cos_T = cos_Taylor(x, e);

                x_values[count] = x * 180.0 / M_PI; //градуси
                table_values[count] = cos_x;
                taylor_values[count] = cos_T;
                differences[count] = fabs(cos_x - cos_T);

                count++;
            }


            for (int i = 0; i < count; i++) {
                printf(format,
                       x_values[i],
                       table_values[i],
                       taylor_values[i],
                       differences[i]);
            }
        }

        printf("\nPress ENTER to restart, any key to exit...");
    } while (getch() == 13);

    return 0;
}
