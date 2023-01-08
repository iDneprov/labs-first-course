#include <stdio.h>
#include <math.h>
#define ABS(a) (a < 0) ? -(a) : a 
#define A 2.0l
#define B 3.0l

long double MachineEpsilon() {
    long double e = 1.0l;
    while (1.0l + e * 0.5l > 1.0l) {
        e *= 0.5l;
    }
    return e;
}

long double F(long double x) {
    return sqrt(log(1 + x) + 3);
}

int main(void) {
    long double e = MachineEpsilon();
    long double prevX = (A + B) / 2.0l;
    long double nextX = F(prevX);
    while (ABS(prevX - nextX) >= e) {
        prevX = nextX;
        nextX = F(prevX);
    }
    printf("Machine epsilon = %.10Le\n", e); 
    printf("Result = %.20Lf\n", nextX);
    return 0;
}
