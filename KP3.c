#include <stdio.h>
#include <math.h>

#define RANGE_BEGIN 0.0l
#define RANGE_END 0.5l
#define STEP 0.005l

long double MachineEps() {
    long double e = 1.0l;
    while (1.0l + e * 0.5l > 1.0l) {
        e *= 0.5l;
    }
    return e;
}

long double Abs(long double a) {
    return a >= 0 ? a : -a;
}

long double F(long double x) {
    return x * (3 - x) / ((1 - x) * (1 - x) * (1 - x));
}

void Head() {
    for (int i = 0; i < 76; i++) {
        printf("_");
    }
    printf("\n| x");
    for (int i = 2; i < 7; i++) {
        printf(" ");
    }
    printf("| част. сумма ряда");
    for (int i = 17; i < 24; i++) {
        printf(" ");
    }
    printf("| значения функции");
    for (int i = 17; i < 24; i++) {
        printf(" ");
    }
    printf("| число итераций |\n");
    for (int i = 0; i < 76; i++) {
        printf("=");
    }
    printf("\n");
}

void End() {
    for (int i = 0; i < 76; i++) {
        printf("=");
    }
    printf("\n");
}

int Length(int n) {
    int k = -1;
    while (n > 0) {
        k += 1;
        n /= 10;
    }
    return k;
}

int main() {
    long double e = MachineEps();
    Head();
    for (long double x = RANGE_BEGIN; x <= RANGE_END; x += STEP) {
        double stepen = (double)x;
        long double summ = 0.0l, next = 3 * x;
        long double fX = F(x);
        int n = 1;
        for (; n <= 100 && Abs(next) > e; n++) {
            summ += next;
            stepen *= (double)x;
            next = (n + 1) * (n + 3) * (long double)stepen;
        }
        printf("| %.3Lf | %.20Lf | %.20Lf | %d", x, summ, fX, n);
        double length = Length(n);
        for (int i = length; i < 14; i++) {
            printf(" ");
        }
        printf("|\n");
    }
    End();
    return 0;
}
