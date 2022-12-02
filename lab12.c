#include <stdio.h>
#include <stdlib.h>

int Pow(int a, int b) {
	int res = 1;
	for (int i = 0; i < b; i++) {
		res *= a;
	}
	return res;
}

long long Shift(long long n, int digs) {
	long long w = 1, z = 1, copy = n;
	int bot = 0, count = 1, bc = 1;    
    
       	while (copy % 10 != 0 && count * 2 <= digs){
	       	bot = bot + copy % 10 * bc;   
		copy /= 10;
		++count;
		bc *= 10;
	}
	if ((count - 1) * 2 <= digs){
		while (copy % 10 == 0 && count * 2 <= digs) {
			copy /= 10;
			++zeros;
			++count;
		}
		n = (n - bot) / Pow(10, zeros) + bot;
	}
	bot = (n % Pow(10, digs / 2));
	n = (n - bot) * Pow(10, zeros) + bot;
	return n;
}



int main() {
	long long n = 0;
	int sign = 1, digs = 0;	
	char c;
	c = getchar();
	if (c == '-') {
		sign = -1;
		c = getchar();
	}
	while (c != EOF) {
		if (c == '\n') {
			n = Shift(n, digs);
			n *= sign;
			printf("%lld\n", n);
			n = 0;
			digs = 0;
		} else if (c == '-') {
			sign = -1;
		} else {
			n *= 10;
			n += (int)(c - '0');
			++digs;
		} 
		c = getchar();
	}
}	
