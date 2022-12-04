#include <stdio.h>

int Check(char s) {
    return ((s != EOF) && (s != '\n') && (s != '.') && (s != ',') && (s != ' '));
}

int main(void) {
    int count = 0, f = 1, number = 0;
    char s;
    s = getchar();
    while (1) {
        if (Check(s)) {
            if ((s == '1' || s == '0') && f) {
                if (s == '1') {
                    number = (number * 10) + 1;
                } else {
                    number = number * 10;
                }
            } else {
                number = 0;
                f = 0;
            }
        }
        if (!Check(s)) {
            if (f) {
                ++count;
                if (count % 3 == 0) {
                    printf("%d", number);
                }
            }
            f = 1;
            number = 0;
        }
        if (s == EOF) {
            break;
        }
        s = getchar();
    }
    return 0;
}
