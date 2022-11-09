#include <stdio.h>

int main() {
    int k = 1;

    while(1) {
        int num = getchar();
        if(num == ' ' || num == '\n') {
            k = 0;
        }
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
