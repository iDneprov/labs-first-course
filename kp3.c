// [a; b] == [0;0,5] f(x) = arctg(x)

#include <stdio.h>

long double MachineEpsilon() {
    long double e = 1.0l;
    while (1.0l + e * 0.5l > 1.0l) {
        e *= 0.5l;
    }
    return e;
}

int main(void) {
    long double e = MachineEpsilon();
    int n;
    long double b = 0.5, step;
    printf("Print the accuracy ");
    scanf("%d", n);
    step = b / n;
    printf("%LF", step);



}
