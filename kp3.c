#include <stdio.h>
#include <math.h>

#define BEGIN 0.0l
#define END 1.0l
#define STEP 0.005l

long double MachineEps() {
    long double eps = 1.0l;
    while (1.0l + eps > 1.0l) {
        eps *= 0.5l;
    }
    return eps;
}

void DrawTheTableHeader() {
    for (int i = 0; i < 77; i++) {
        printf("-");
    }
    printf("\n| x ");
    for (int i = 2; i < 7; i++) {
        printf(" ");
    }
    printf("| част. сумма ряда");
    for (int i = 17; i < 24; i++) {
        printf(" ");
    }
    printf("| значение функции");
    for (int i = 17; i < 24; i++) {
        printf(" ");
    }
    printf("| число итераций |\n");
    for (int i = 0; i < 77; i++) {
        printf("-");
    }
    printf("\n");
}

long double Function(long double x) {
    long double y = powl (x, 2);
    return powl(M_E, y);
}

int main() { 
    long double eps = MachineEps(); 
    int n;
    long double sum, summand, fX, numerator;
    double factorialN, lengthOfN; 
    DrawTheTableHeader();
    for (long double x = BEGIN; x <= END; x += STEP) {      
        n = 1;
        sum = 1.0l;
        summand = 1l;
        fX = Function(x);
        numerator = 1;
        factorialN = 1.0;      
        while (n <= 100 && summand > eps) {   
            factorialN *= n;
            numerator *= powl(x, 2);
            summand = (numerator / factorialN);
            sum += summand;
            ++n;
        }   
        printf("| %.4Lf | %.20Lf | %.20Lf | %d", x, sum, fX, n - 1);
        lengthOfN = log10(n-1);
        for (int i = lengthOfN; i < 14; i++) {
            printf(" ");
        }
        printf("|\n");
    }
    for (int i = 0; i < 77; i++) {
        printf("-");
    }
    printf("\n");
    return 0;
}

