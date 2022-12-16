#include <stdio.h>
#include <math.h>

long double MachineEpsilon() {
    long double e = 1.0l;
    while (1.01l + e * 0.5l > 1.01) {
        e *= 0.5l;
    }
    return e;
}

long double F(long double x) {
    return 1.0l / 2.0l * log(x);
}

long double Teylor(long double x, long double n) {
    return (1.0l / (2.0l * n + 1.0l)) * (powl((x - 1.0l) / (x + 1.0l), 2.0l * n + 1.0l));
}

int main (void) {
    long double e = MachineEpsilon();
    printf("x | частичная сумма ряда для функции | значение функции | число итераций\n"); 
    for (long double x = 0.2; x < 0.7; x += 0.005l) {
        long double valueTeylor = 0.0l;
        int n = 0;
        long double nextAddition = Teylor(x, n);
        long double valueF = F(x);
        for (n = 1; n <= 101 && fabs(nextAddition) > e; ++n) {
            valueTeylor += nextAddition;
            nextAddition = Teylor(x, n);
        }
        printf("%.3Lf | %.20Lf | %.20Lf | %d\n", x, valueF, valueTeylor, n);
    }
    return 0;
}
