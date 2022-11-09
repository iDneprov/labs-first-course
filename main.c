#include <stdio.h>

int main() {
    int k = 1, num;

    while(1) {
        num = getchar();
        if(num == EOF) {
            break;
        }
        if(k == 2) {
            k = 0;
        } else {
            putchar(num);
        }
        k = k + 1;
    }

    printf("\n");
    return 0;
}
