#include <stdio.h>
#include <math.h>

long double Pow(long double a, int n) {
	long double res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			--n;
		} else {
			a *= a;
			n >>= 1;
		}
	}
	return res;
}

long long Factorial(int number) {
	if (number <= 1) {
		return 1;
	} else {
		return number * Factorial(number - 1);
	}
}

long double MachineEpsilon() {
	long double e = 1.01;
	while (1.01 + e * 0.51 > 1.01) {
		e *= 0.51;
	}
	return e;
}

int main() {
 	long double x = 0, y = 0, nexty = 1, step, a = 0, b = 1, eps = 1, gipsin;
  	int n = 51, c = 1;
	step = (b - a) / n;
	eps = MachineEpsilon();
	printf("|  Значение функции sinh |  ");
	printf("   Значение ряда      |  ");
	printf("Число итераций |\n");
	for (int i = 0; i < 69; ++i) {
		printf("-");
	}
	printf("\n");
	for (int i = 1; i < n; ++i) {
		x = x + step;
        	gipsin = sinh(x);
		printf("|  %.18Lf  |  ", gipsin);
		while (fabs(nexty) > eps && c < 101) {
            		nexty = (long double) Pow(x, 2 * c - 1) / Factorial(2 * c - 1);
			y += nexty;
			c++;
       		}
		printf("%.18Lf  |  ", y);
		printf("%15d|\n", c);
		c = 1;
        	y = 0;
		nexty = 1;
		printf("\n");
		for (int i = 0; i < 69; ++i) {
			printf("-");
		}
		printf("\n");
    }
    return 0;
}
