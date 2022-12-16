#include <stdio.h>
#include <math.h>

#define BEGIN 0.0l;
#define END 1.0l;

long double MachineEps() {
    long double eps = 1.0l;
    while (1.0l + eps > 1.0l) {
        eps *= 0.5l;
    }
    return eps;
}

long double Function(long double x) {
    return sqrtl(1 - x) - tanl(x);
}

long double Abs(long double x) {
    if(x < 0) {
        return -x;
    }
    return x;
}

int main() {
    long double eps = MachineEps(); 
    long double a, b;
    a = BEGIN;
    b = END;
    int f = 1;
    while (Abs(a-b) > eps) {
        if (Function(a) * Function((a + b) / 2) == 0) {
            if (Function(a) == 0){
                printf(" %.20Lf \n", a);
                f = 0;
                break;
            } else {
                printf(" %.20Lf \n", (a + b) / 2);
                f = 0;
                break;
            }
        } else if (Function(a) * Function((a + b) / 2) > 0) {
            a = (a + b) / 2;
        } else { 
            b = (a + b) / 2;
        }
    }
    if (f) {
        printf(" %.20Lf \n", (a + b) / 2);
    }
}

