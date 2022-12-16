#include <stdio.h>
#include <math.h>

#define A 2.0l
#define B 3.0l

long double MachineEpsilon() {
    long double e = 1.0l;
    while (1.0l + e * 0.5l > 1.0l) {
        e *= 0.5l;
    }
    return e;
}

long double Abs(long double a) {
    return a > 0 ? a : -a;
}
long double F(long double x) {
    return log(x) + 1.8l;
}

int main(void) {
    long double e = MachineEpsilon();
    long double xPrevious = (A + B) / 2.0;
    long double xNext = F(xPrevious);
    while (Abs(xPrevious - xNext) >= e) {
        xPrevious = xNext;
        xNext = F(xPrevious);
    }
    printf("%.20Lf\n", xNext);
    return 0;
}
