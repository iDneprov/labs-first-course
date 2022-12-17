#include <stdio.h> 
#include <math.h> 
 
#define RANGE_BEGIN -1.0l 
#define RANGE_END 1.005l 
#define STEP 0.005l 
 
long double ABS(long double x) { 
    return (x > 0) ? x : -x; 
} 

long double MachineEpsilon() { 
    long double e = 1.0l; 
    while (1.0l + e * 0.5l > 1.0l) { 
        e *= 0.5l; 
    } 
    return e; 
} 
 
long double Ln(long double x) { 
    return log(2 + x); 
} 
 
long double MyPow(long double x, int y) { 
    long double z = 1; 
    while (y > 0) { 
        if (y & 1) { 
            z *= x; 
        } 
        x *= x; 
        y = y >> 1; 
    } 
    return z; 
} 

int main(void) { 
    long double e = MachineEpsilon(), stepX; 
    printf("Machine epsilon for long double = %.10Le\n", e); 
    printf("Table of values of Taylor series and standard function for ln(x + 2)\n"); 
    printf("     x    |        sum of line      |         function       | iter  \n"); 
    printf("----------+-------------------------+------------------------+-------\n"); 
    for (long double x = RANGE_BEGIN; x <= RANGE_END; x += STEP) { 
        int n = 1; 
        long double sum = 0.0l; 
        for (; n <= 100; n++) { 
            stepX = MyPow(x, n) / (n * MyPow(2, n)); 
            if (n % 2) { 
                sum += stepX; 
            } else { 
                sum -= stepX; 
            } 
            if (ABS(stepX) < e) { 
                break; 
            } 
        } 
        if (x < 0) { 
            printf("  %.3Lf  | %.20Lf  | %.20Lf |  %d  \n", x, sum + log(2), Ln(x), n); 
        } else { 
            printf("   %.3Lf  | %.20Lf  | %.20Lf |  %d  \n", x, sum + log(2), Ln(x), n); 
        } 
    } 
}

