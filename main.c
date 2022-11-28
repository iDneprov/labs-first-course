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
    long double x;
    long double x0 = (2 + 3) / 2, diff = 1, eps = MachineEpsilon();
    int n = 0;
    printf("alpha(x) = (ln(1 + x) + 3)^0.5\n");
    while (Abs(diff) >= eps) {
        x = powl(log(1 + x0) + 3, 0.5);
        diff = x - x0;
        x0 = x;
    }
    printf("x = %Lf\n", x);
}
