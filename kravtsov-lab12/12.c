#include <stdio.h>

unsigned long Lab12(unsigned long n) {
    unsigned long a = (n * 10 + 1);
    unsigned long x = 10;
    for( ; x <= a ; ) {
        x = x * 10;
    };
    
    return x + a;
}

int main(void) {
    unsigned long n;   
    scanf("%d", &n);
    printf("%d", Lab12(n));

    return 0;
}
