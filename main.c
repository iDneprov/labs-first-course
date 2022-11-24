#include <math.h>
#include <stdio.h>



#define RANGE_BEGIN 0.1l
#define RANGE_END 0.6l
#define STEP 0.005l

long double MachineEps() {
    long double e = 1.0l;
    while (1.0l + e * 0.5l > 1.0l) {
        e *= 0.5l;
    }
    return e;
}

long double Abs(long double a) {
    return a >= 0 ? a : -a;
}

long double F(long double x) {
    return powl(M_E, 2 * x);
}

int GetLine(int x){
    for (int i = 0; i < x; i++) {
        printf("=");
    }
    printf("\n");
    return 0;
}

int GetHeader(){
    printf("|| x");
    for (int i = 2; i < 7; i++) {
        printf(" ");
    }
    printf("|| част. сумма ряда");
    for (int i = 17; i < 24; i++) {
        printf(" ");
    }
    printf("|| значение функции");
    for (int i = 17; i < 24; i++) {
        printf(" ");
    }
    printf("|| число итераций ||\n");
    return 0;
}

int main() {
    long double eps = MachineEps();
    GetLine(81);
    GetHeader();
    GetLine(81);
    
    for (long double x = RANGE_BEGIN; x <= RANGE_END; x += STEP) {
        double factorialN = 1.0;
        long double sum = 1.0l, an = 2 * x;
        long double fX = F(x);
        int n = 1;
        
        for (; n <= 100 && Abs(an) > eps; n++) {
            sum += an;
            factorialN *= (double)(n + 1);
            an = an * (2 * x) / (long double)factorialN;
        }
        
        printf("|| %.3Lf || %.20Lf || %.20Lf || %d", x, sum, fX, n);
        double lengthOfN = n > 0 ? log10(n) : 1;
        for (int i = lengthOfN; i < 14; i++) {
            printf(" ");
        }
        printf("||\n");
    }
    GetLine(81);
    printf("\n");
    return 0;
}
