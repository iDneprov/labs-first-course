#include <stdio.h>

unsigned long Lab12(unsigned long n) {
    if (n == 0) {
        return 101;
    };
    unsigned long a = (n * 10 + 1);
    unsigned long x = 10;
    for( ; x <= a ; ) {
        x = x * 10;
    };

    return x + a;
}

int main(void) {
    
    scanf("%c",&g);
    printf("%c", g);
    scanf("%c",&g);
    printf("%c", g);
    unsigned long n;   


    return 0;
}
