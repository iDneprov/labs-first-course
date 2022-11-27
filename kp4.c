// x + cos(x^0,52 + 2) = 0 [a;b] = [0,5;1] итерации x ~ 0,9892 -0,52cos(x^0,52 + 2)
#include <stdio.h>
#include <math.h>

long double Abs(long double num) {
    return num > 0 ? num : -num;
}

long double MachineEpsilon() {
    long double e = 1.0l;
    while (1.0l + e * 0.5l > 1.0l) {
        e *= 0.5l;
    }
    return e;
}

int main() {
    long double x0 = (0.5 + 1) / 2, x, e = MachineEpsilon(), diff = 1;
    int n = 0;
    printf("alpha(x) = -0.52cos(x^0.52 + 2)\n");
    while (Abs(diff) >= e) {
        x = -cosl(powl(x0, 0.52) + 2);
        diff = x - x0;
        x0 = x;
        n += 1;
    }
    printf("x = %Lf\n", x);
}
