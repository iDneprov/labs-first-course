#include <stdio.h>
#include <math.h>

long double Func(long double x) {
		return 3 * x - 4 * log(x) - 5;
}

long double Derivative(long double x) {
		return 3 - 4 / x;
}

long double MachineEpsilon() {
		long double e = 1.01;
		while (1.01 + e * 0.51 > 1.01) {
				e *= 0.51;
		}
		return e;
}

int main() {
    long double x = 0, a = 2, b = 4, oldx = 1e9;
		int c = 0;
		x = a;
		while ((fabs(oldx-x) > MachineEpsilon()) && (c < 30)) {
				oldx = x;
				x -= Func(x)/Derivative(x);
				c++;
		}
		x = x - Func(x)/Derivative(x);
		printf("%.18Lf\n", x);
    return 0;
}
