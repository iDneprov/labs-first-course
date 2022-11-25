#include <stdio.h>
typedef enum {
    S0, S1, S2, S3, S4, S5, S6
} State;
int isSign(char c)
{
    if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}
int isNum(char c)
{
    if (c <= '9' && c >= '1') {
        return 1;
    }
    return 0;
}
int isSpace(char c)
{
    if (c == ' ' || c == '\n' || c == '\t') {
        return 1;
    }
    return 0;
}
int main(void)
{
    char c;
    long long a = 0;
    State state = S0;
    while ((c = getchar()) != EOF) {
        switch (state) {
            case S0:
                printf("\n");
                if (isSign(c)) {
                    printf("%c", c);
                    state = S4;
                } else if (isNum(c)) {
                    a = a * 10 + (c - '0');
                    state = S1;
                } else if (c == '0') {
                    printf("%c", c);
                    state = S6;
                } else {
                    printf("%c", c);
                    state = S2;
                }
                break;
            case S3:
                a = 0;
                if (isSign(c)) {
                    printf("%c", c);
                    state = S4;
                } else if (isNum(c)) {
                    a = a * 10 + (c - '0');
                    state = S1;
                } else if (c == '0') {
                    printf("%c", c);
                    state = S6;
                } else if (isSpace(c)) {
                    printf("%c", c);
                    state = S3;
                } else {
                    printf("%c", c);
                    state = S2;
                }
                break;
            case S1:
                if (isNum(c) || c == '0') {
                    a = a * 10 + (c - '0');
                    state = S1;
                } else if (isSpace(c)) {
                    printf("0%lld%c", a, c);
                    state = S3;
                } else {
                    printf("%lld%c", a, c);
                    state = S2;
                }
                break;
            case S2:
                if (isSpace(c)) {
                    printf("%c", c);
                    state = S3;
                } else {
                    printf("%c", c);
                    state = S2;
                }
                break;
            case S5:
                if (isNum(c) || c == '0') {
                    a = a * 10 + (c - '0');
                    state = S5;
                } else if (isSpace(c)) {
                    printf("0%lld%c", a, c);
                    state = S3;
                } else {
                    printf("%lld%c", a, c);
                    state = S2;
                }
                break;
            case S6:
                if (isSpace(c)) {
                    printf("0%c", c);
                    state = S3;
                } else if (c == '0') {
                    printf("0");
                    state = S6;
                } else if (isNum(c)) {
                    a = a * 10 + (c - '0');
                    state = S1;
                } else {
                    printf("%c", c);
                    state = S2;
                }
                break;
            
            case S4:
                if (isNum(c)) {
                    a = a * 10 + (c - '0');
                    state = S5;
                } else if (isSpace(c)) {
                    printf("%c", c);
                    state = S3;
                } else if (c == '0') {
                    printf("%c", c);
                    state = S6;
                } else {
                    printf("%c", c);
                    state = S2;
                }
        }
    }
    return 0;
}
