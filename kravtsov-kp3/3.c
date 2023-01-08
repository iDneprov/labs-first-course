#include <stdio.h> 
#include <math.h> 
#define BEGIN 0.0l 
#define END 0.5l 
#define STEP 0.005l 
#define ABS(a) (a < 0) ? -(a) : a 

long double MachineEpsilon() { 
    long double e = 1.0l; 
    while (1.0l + e * 0.5l > 1.0l) { 
        e *= 0.5l; 
    } 
    return e; 
} 

long double F(long double x) { 
    return (3.0l * x - 5.0l) / (x * x - 4.0l * x + 3.0l); 
} 

int main(void) { 
    long double e = MachineEpsilon();
    long double step; 
    printf("Machine epsilon = %.10Le\n", e); 
    printf("Table of values of Taylor series and standard function for (3x-5)/(x^2-4x+3)\n"); 
    printf("     x    |        sum of line      |         function       | iter  \n"); 
    printf("----------+-------------------------+------------------------+-------\n"); 
    for (long double x = BEGIN; x <= END; x += STEP) { 
        int n = 1; 
        long double sum = 0.0l; 
        for (; n <= 100; n++) { 
            step = (1 + 2 / powl(3, n + 1)) * powl(x, n);
            sum -= step;
            if (ABS(step) < e) { 
                break; 
            } 
        } 
        printf("   %.3Lf  | %.20Lf  | %.20Lf |  %d  \n", x, sum + (-5.0l / 3.0l), F(x), n); 
    } 
}
