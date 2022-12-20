#include <stdio.h>
 
int IsSign(char c) {
    return (c == '+' || c == '-');
}
 
int IsNum(char c) {
    return (c <= '9' && c >= '1');
}
 
int IsSpace(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}
 
/* PREVSYMB
 * ' ' init of program
 * '1' number
 * 'a' alpha
 * '_' space
 * '-' sign
 * 'n' num or zero
 * '0' zero
 */
int main(void) {
    char c;
    long long a = 0;
    char prevSymb = ' ';
    while ((c = getchar()) != EOF) {
        switch (prevSymb) {
            case ' ':
                printf("\n");
                if (IsSign(c)) {
                    putchar(c);
                    prevSymb = '-';
                } else if (IsNum(c)) {
                    a = a * 10 + (c - '0');
                    prevSymb = '1';
                } else if (c == '0') {
                    putchar(c);
                    prevSymb = '0';
                } else {
                    putchar(c);
                    prevSymb = 'a';
                }
                break;
            case '_':
                a = 0;
                if (IsSign(c)) {
                    putchar(c);
                    prevSymb = '-';
                } else if (IsNum(c)) {
                    a = a * 10 + (c - '0');
                    prevSymb = '1';
                } else if (c == '0') {
                    putchar(c);
                    prevSymb = '0';
                } else if (IsSpace(c)) {
                    putchar(c);
                    prevSymb = '_';
                } else {
                    putchar(c);
                    prevSymb = 'a';
                }
                break;
            case '1':
                if (IsNum(c) || c == '0') {
                    a = a * 10 + (c - '0');
                    prevSymb = '1';
                } else if (IsSpace(c)) {
                    printf("0%lld%c", a, c);
                    prevSymb = '_';
                } else {
                    printf("%lld%c", a, c);
                    prevSymb = 'a';
                }
                break;
            case 'a':
                if (IsSpace(c)) {
                    putchar(c);
                    prevSymb = '_';
                } else {
                    putchar(c);
                    prevSymb = 'a';
                }
                break;
            case 'n':
                if (IsNum(c) || c == '0') {
                    a = a * 10 + (c - '0');
                    prevSymb = 'n';
                } else if (IsSpace(c)) {
                    printf("0%lld%c", a, c);
                    prevSymb = '_';
                } else {
                    printf("%lld%c", a, c);
                    prevSymb = 'a';
                }
                break;
            case '0':
                if (IsSpace(c)) {
                    printf("0%c", c);
                    prevSymb = '_';
                } else if (c == '0') {
                    printf("0");
                    prevSymb = '0';
                } else if (IsNum(c)) {
                    a = a * 10 + (c - '0');
                    prevSymb = '1';
                } else {
                    putchar(c);
                    prevSymb = 'a';
                }
                break;
 
            case '-':
                if (IsNum(c)) {
                    a = a * 10 + (c - '0');
                    prevSymb = 'n';
                } else if (IsSpace(c)) {
                    putchar(c);
                    prevSymb = '_';
                } else if (c == '0') {
                    putchar(c);
                    prevSymb = '0';
                } else {
                    putchar(c);
                    prevSymb = 'a';
                }
        }
    }
    return 0;
}
