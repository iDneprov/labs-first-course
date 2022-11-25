#include <stdio.h>

int main(void) {
    char a, b = '\0';
    long long int c = 0;

        while (b != EOF) {
            b = getchar();
            
            if ((b != ' ') && (b != ',') && (b != '\n') && (b != EOF) && (b != '\t') && (b != '\v')) {
                a = b;
                c = c * 10 + (b - '0');
            } else {
                c = c / 10;
                if (c != 0) {
                    printf("%c%lld", a, c);
                    printf("%c", b);
                    c = 0;
                } else {
                    printf("%c%c", a, b);
                }
            }
        };

    return 0;

}
