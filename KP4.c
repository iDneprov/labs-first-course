#include <stdio.h>
#include <math.h>

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

int main() {
    long double x0 = 0.5, x, diff = 1, e = MachineEps();
    printf("alpha(x) = cos((1 - 0.3x^3)^0.5)\n");
    while (Abs(diff) >= e) {
        x = cos(powl(1 - 0.3 * powl(x0, 3), 0.5));
        diff = x - x0;
        x0 = x;
    }
    printf("x = %Lf\n", x);
    return 0;
}
