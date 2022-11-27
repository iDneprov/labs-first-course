// 14 вариант
// (2 * x - 3) / (x - 1) ^ 2
// -3 - 4 * x - 5 * x ^ 2 - ... - (n + 3) * x ^ n
#include <stdio.h>
#include <math.h>

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
    return (2 * x - 3) / ((x - 1) * (x - 1));
}

long double Pow(long double x, long double n, long double i) {
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return x;
    }
    else if (n >= 1) {
        return x * i;
    }
}

int main() {
    long double e = MachineEps();
    long double b = 0.6, step, iter, result, temp, x;
    long double a = 0.1;
    int count = 0;
    printf("Print the iterations: ");
    scanf("%Lf", &iter);
    putchar('\n');
    step = (b - a) / iter;
    printf("Machine epsilon for long double = %.8Le\n", e);
    printf("Taylor series values table for f(x) = (2x-3)/(x-1)^2\n");
    printf(" ---------------------------------------------------------------\n");
    printf("| x \t| sum of line\t\t| function\t\t| iter  |\n");
    printf(" -------+-----------------------+-----------------------+-------\n");
    for (long double i = a; i <= b; i += step) {
        x = i;
        for (int n = 0; n < 999; ++n) {
            temp = -(n + 3) * Pow(x, n, i);
            result += temp;
            count += 1;
            if (n > 1) {
                x *= i;
            }
            if (Abs(temp) < e) {
                break;
            }
        }
        printf("| %.3Lf\t| %.19Lf| %.19Lf| %d\t|\n", i, result, F(i), count);
        result = 0;
        count = 0;
    }
    printf(" ----------------------------------------------------------------\n");
    return 0;
}
