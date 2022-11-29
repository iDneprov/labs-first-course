#include <stdio.h>
#include <math.h>

#define STEP 0.005l

long double MachineEpsilon() {
	long double e = 1.01;
	while (1.01 + e * 0.51 > 1.01) {
		e *= 0.51;
	}
	return e;
}

int main() {
    long double x, y, nexty, a = 0, b = 1, eps, gipsin;
  	int c = 1;
	x = a;
	eps = MachineEpsilon();
	printf("|  Значение функции sinh |  ");
	printf("   Значение ряда      |  ");
	printf("Число итераций |");
    printf(" Значение x |\n");
	while (x < b - STEP) {
		x = x + STEP;
       	gipsin = sinh(x);
		y = x;
		nexty = x;
		printf("|  %.18Lf  |  ", gipsin);
		while (nexty > eps && c < 101) {
       	    nexty = nexty*x*x/((2 * c) * (2 * c + 1));
			y += nexty;
			c++;
       	}
		printf("%.18Lf  |  ", y);
		printf("%15d|", c);
        printf("%12Lf|\n", x);
		c = 1;
       	y = 0;
		nexty = 1;
		for (int i = 0; i < 82; ++i) {
			printf("-");
		}
		printf("\n");
    }
    return 0;
}
