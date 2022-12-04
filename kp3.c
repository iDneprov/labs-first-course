#include <stdio.h>
#include <math.h>

#define RANGE_BEGIN 0.0l
#define RANGE_END 0.5l
#define STEP 0.005l

long double MachineEpsilon() {
    long double e = 1.0l;
    while (1.0l + e * 0.5l > 1.0l) {
        e *= 0.5l;
    }
    return e;
}

long double F(long double x) {
    return (x * (3 - x)) / powl((1 - x), 3);
}

int main(void) {
    long double e = MachineEpsilon(), x, part;
    printf("Machine epsilon for long double = %.8Le\n", e);
    printf("Table of values of Taylor series and standard function for x*(3 - x) / ((1 - x)^ 3)\n");
        printf("------------------------------------------------------------------\n");
	    printf("| x \t| sum of line\t\t | function\t\t  | iter |\n");
	    printf("--------+------------------------+------------------------+-------\n");
    for (long double i = RANGE_BEGIN; i <= RANGE_END; i += STEP) {
        int n = 1;
        long double sum = 0.0;
        x = i;
        for (; n <= 100; n++) {
            part = n * (n + 2) * powl(x, n);
            sum += part;
            if (part < e) {
                break;
            }  
        }
        printf("| %.3Lf | %.20Lf | %.20Lf | %d \t |\n", x, sum, F(x), n);
    }
    printf("------------------------------------------------------------------\n");
    return 0;
}
