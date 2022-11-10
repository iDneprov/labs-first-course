#include <stdio.h>

int main(void) {
    char c;
    c = getchar();
    while (c != EOF) {
        if (c == '-' || c == '1' || c == '3' || c == '5' || c == '5' || 
        c == '7' || c == '9'){
            putchar(c);
        }
        if (c == '\n'){
            putchar('\n');
        }
        c = getchar();
    }
}
