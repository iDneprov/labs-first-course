#include <stdio.h>
#include <math.h>
#include <locale.h>

#define BEGIN -0.200
#define END 0.301
#define STEP 0.0051

long double MachineEpsilon() {
    long double e = 1.01;
    while (1.01 + e * 0.51 > 1.01) {
        e *= 0.51;
    }
    return e;
}

void HeaderView() {
    for (int i = 0; i < 77; i++) {
        printf("_");
    }
    printf("\n| x ");
    for (int i = 2; i < 7; i++) {
        printf(" ");
    }
    printf("| част. сумма ряда");
    for (int i = 17; i < 24; i++) {
        printf(" ");
    }
    printf("| значение функции");
    for (int i = 17; i < 24; i++) {
        printf(" ");
    }
    printf("| число итераций |\n");
    for (int i = 0; i < 77; i++) {
        printf("-");
    }
    printf("\n");
}

long double F(long double x) {
    return log(1 + x - (2 * x * x));
}

int main(void) {
    char* locale = setlocale(LC_ALL, "");
    long double e = MachineEpsilon(), teylor, f;
    HeaderView();
    for (long double x = BEGIN; x <= END; x += STEP) {
        int n = 1;
        f = F(x);
        long double summ = 0;
        teylor = 1;
        for (; n <= 100 && fabs(teylor) > e; ++n) {
            teylor = (((powl(-1, n + 1) * powl(2, n) - 1) / n) * powl(x, n));
            summ += teylor;
        }
        printf("%.3Lf | %.20Lf | %.20Lf | %d\n", x, summ, f, n);
        
    }
    return 0;
}
