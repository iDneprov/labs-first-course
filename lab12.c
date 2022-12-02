#include <stdio.h>

int Pow(int a, int b) {
	int res = 1;
	for(int i = 0; i < b; i++) {
		res *= a;
	}
	return res;
}

int main() {
	int n, w = 1, z = 1, zeros = 0, digs = 0;
	
	scanf("%d", &n);

	while(n % w != n) {
		w *= 10;
		digs++;
		if(n % (z*10) == 0) {
			z *= 10;	
			zeros++;
		}
	}
	
	int half = Pow(10, (digs - zeros) / 2);
	n = n - n % (z * half) + (n / z % half);
	
	printf("%d", n);
}	
