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
 
int main(void) { 
    long double x0 = 0.5, x = 0, delt = 1, e = MachineEpsilon(); 
    printf("alpha(x) = sin(sqrt(1 - 0.4 * x ^ 2))\n"); 
    while (Abs(delt) >= e) { 
        x = sinl(sqrt(1.0l - 0.4l * powl(x0, 2))); 
        delt = x - x0; 
        x0 = x; 
    } 
    printf("x = %Lf\n", x); 
}

