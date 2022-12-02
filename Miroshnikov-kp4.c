#include <stdio.h>
#include <math.h>

long double Abs(long double a) {
    return a > 0 ? a : -a;
}

long double MachineEps() {
    long double e = 1.0l;
    while (1.0l + e * 0.5l > 1.0l) {
        e *= 0.5l;
    }
    return e;
}

int main () {
    long double x;
    long double x0 = (1 + 2) / 2;
    long double e = MachineEps();
    long double razn = 1;
    printf("f(x) = 0,4 + arctg(sqrt(x))\n");
    while (Abs(razn) >= e) {
        x = 0.4 + atanl(sqrtl(x0));
        razn = x - x0;
        x0 = x;
    }
    printf("x = %Lf\n", x);
}
