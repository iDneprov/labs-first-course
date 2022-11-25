#include <stdio.h>
 
 
int main() {
 
    int k = 0, c, d = 0, e = 0;
    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') {
            break;
        }
        if (!(c > 47 && c < 58)) {
            if (k != 0) {
                printf("%d", k);
                for (int j = 0; j < d; j++) {
                    printf("%d", 0);
                }
            }
            k = 0;
            continue;
        }
 
        k = k * 10 + (c - '0');
        if ((c - '0') == 0) {
            d += 1;
        }
    }
 
 
}