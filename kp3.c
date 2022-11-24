// [a; b] == [0;0,5] f(x) = arctg(x)

#include <stdio.h>
#include <math.h>

long double Abs(long double num) {
    return num > 0 ? num : -num;
}

long double Pow(long double num, long double base) {
    long double res = num;
    for (int i = 0; i < 2; i++) {
        res *= base;
    }
    return res;
}

long double MachineEpsilon() {
    long double e = 1.0l;
    while (1.0l + e * 0.5l > 1.0l) {
        e *= 0.5l;
    }
    return e;
}

int main(void) {
    long double e = MachineEpsilon();
    long double b = 0.5, step, iter, res, temp, num;
    int counter = 0;
    printf("Print the iterations: ");
    scanf("%Lf", &iter);
    putchar('\n');
    step = b / iter;
    printf("Machine epsilon for long double = %.8Le\n", e);
    printf("Taylor series values table for f(x) = arctan(x)\n");
	printf(" ---------------------------------------------------------------\n");
	printf("| x \t| sum of line\t\t| function\t\t| iter  |\n");
	printf(" -------+-----------------------+-----------------------+-------\n");
    for (long double i = 0; i <= b; i += step) {
        num = i;
        for (int n = 0; n < 999; n++) {
            if (n % 2 == 0) {
                temp = (num / (2 * n + 1));
            } else {
                temp = -(num / (2 * n + 1));
            }
            res += temp;
            counter += 1;
            num = Pow(num, i);
            if (Abs(temp) < e){
                break;
            }
        }
        printf("| %.3Lf\t| %.20Lf| %.20Lf| %d\t|\n", i, res, atanl(i), counter);
        res = 0;
        counter = 0;
	}
	printf(" ----------------------------------------------------------------\n");
	return 0;
}
