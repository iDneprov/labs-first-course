#include <stdio.h>

void main() {
    char a = 0;
    while (1) {
        a = getchar();
        if (a == EOF) {
            break;
        } else if (a == '\n') {
            putchar(' ');
            putchar(a);
            putchar(' ');
        } else {
            putchar(a);
        }
    }
}
