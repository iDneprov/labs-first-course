#include <stdio.h>
#include <math.h>

double MachineEpsilon() {
    double e = 1.0l;
    while (1 + e * 0.5 > 1) {
        e *= 0.5;
    }
    return e;
}

long double Func(double x) {
    return (cosl(2.0/x) - (2.0 * sinl(1.0/x)) + (1.0/x));
}

long double Dihotomia(double a, double b) { 
    while (fabs(a - b) > MachineEpsilon()) {
        if (Func(a) * Func((a + b) / 2) < 0) {
            b = (a + b) / 2;
        } else {
            a = (a + b) / 2;
        }
    }
    return (a + b) / 2;
}

int main() {
    double a = 1.0;
    double b = 2.0;
    printf("||==========||\n");
    printf("||x = %.4Lf||\n",Dihotomia(a,b));
    printf("||==========||\n");
}

