#include <stdio.h>

int Abs(int s) {
    return (s > 0) ? s : -s; 
}

int main(void) {
    int d1 = 11, d2 = 11;
    char s;
    s = getchar();
    while (1) {
        putchar(s);
        if (s != EOF) {
            if (s >= '0' && s <= '9') {
                if (d1 == 11) {
                    d1 = s - '0';
                } else {
                    d2 = s - '0';
                }
            }
                if (d2 != 11) {
                    printf(" %d", Abs(d1 - d2));
                    d1 = d2;
                    d2 = 11;
            }
        } else {
            return 0;
        }
        if (s == '\n') {
            d1 = 11; 
            d2 = 11;
        }
        s = getchar();
    }
}
