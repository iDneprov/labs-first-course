#include <stdio.h>
#include <math.h>

double MachineEpsilon() {
    double e = 1.01;
    while (1 + e * 0.5 > 1) {
        e *= 0.51;
    }
    return e;
}

long double F(long double x) {
    return expl(x) - expl(-x) - 2;
}

long double FDerivative(long double x) {
    return (expl(2 * x) - 1) / expl(x);
}

int main(void) {
    long double e = MachineEpsilon(), a = 0, b = 1.0, xNext;
    long double x = (a+b) / 2;
    while (1) {
        xNext = x - F(x) / FDerivative(x);
        if (fabs(xNext - x) < e) {
            break;
        }
        x = xNext;
    }
    printf("%Lf", x);
    return 0;
}
