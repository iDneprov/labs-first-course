#include <stdio.h>
#include <math.h>

#define RANGE_BEGIN 0.0l
#define RANGE_END 2.0l
#define STEP 0.25l

long double MachineEpsilon() {
    long double e = 1.0l;
    while (1.0l + e * 0.5l > 1.0l) {
        e *= 0.5l;
    }
    return e;
}

long double F(long double x) {
    return 1 / (2*x - 5);

}

int main(void) {
    long double e = MachineEpsilon(), x, part;
    printf("Machine epsilon for long double = %.8Le\n", e);
    printf("Table of values of Taylor series and standard function for x*(3 - x) / ((1 - x)^ 3)\n");
        printf("-------------------------------------------------\n");
	    printf("| x \t| sum of line\t | function\t | iter |\n");
	    printf("--------+----------------+---------------+-------\n");
    for (long double i = RANGE_BEGIN; i <= RANGE_END; i += STEP) {
        int n = 1;
        long double sum = 0.0;
        x = i;
        for (; n <= 100; n++) {
            part = powl(2, (n - 1)) * powl(x, (n - 1)) / powl(5, n);
            sum -= part;
            if (part < e) {
                break;
            }  
        }
        printf("| %.3Lf | %.10Lf  | %.10Lf | %d \t|\n", x, sum, F(x), n);
    }
    printf("-------------------------------------------------\n");
    return 0;
}
