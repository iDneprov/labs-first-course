#include <stdio.h>
#include <math.h>

long double Pow(long double a, int n) {
	long double res = 1;
	while (n)
		if (n & 1) {
			res *= a;
			--n;
		}
		else {
			a *= a;
			n >>= 1;
		}
	return res;
}

long long Factorial(int number) {
	if (number <= 1)
		return 1;
	else
		return number * Factorial(number - 1);
}

int main() {
    long double x = 0, y = 0, step, a = 0, b = 1, eps = 0.0000001, gipsin;
  	int n = 51, c = 1;
		step = (b - a) / n;
		printf("Значение функции sinh    ");
		printf("Значение ряда    ");
		printf("Число итераций\n");
		for (int i = 1; i < n; ++i) {
					x = x + step;
        	gipsin = sinh(x);
					printf("%.18Lf    ", gipsin);
					while (gipsin - y > eps) {
            y += (long double) Pow(x, 2 * c - 1) / Factorial(2 * c - 1);
						c++;
        	}
					printf("%.18Lf    ", y);
					printf("%.d\n", c);
					c = 1;
        	y = 0;
					printf("\n");
    }
    return 0;
}
