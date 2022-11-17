#include <stdio.h>

int IsEvenDigit(char c) {
    return (c >= '0') && (c <= '9') && ((c - '0') % 2 != 0);
}

int main(void) {
    char c;
    c = getchar();
    while (c != EOF) {
        if (IsEvenDigit(c) || c == '\n') {
            putchar(c);
        }
        c = getchar();
    }
}
