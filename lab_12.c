#include <stdio.h>

int main(void) {
    char a, b = '\0';
    long long int c = 0;
    int flag = 1;

        while (b != EOF) {
            b = getchar();
            
            if ((b != ' ') && (b != ',') && (b != '\n') && (b != EOF) && (b != '\t') && (b != '\v')) {
                a = b;
                c = c * 10 + (b - '0');
                flag = 1;
            } else if (flag == 1) {
                c = c / 10;
                if (c != 0) {
                    printf("%c%lld", a, c);
                    c = 0;
                } else {
                    printf("%c", a);
                };
                if (b != EOF) {
                    printf("%c", b);
                };

                flag = 0;
            }
        };

    return 0;

}
