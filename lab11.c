#include <stdio.h>

int Check(char s) {
    if ((s != EOF) && (s != '\n') && (s != '.') && (s != ',') && (s != ' ')) {
        return 1;
    }
    return 0;
}

int main(void) {
    int len = 0, count = 0, f = 1;
    char s;
    s = getchar();
    while (1) {
        if (Check(s)) {
            len++;
        }
        else {
            if (s != EOF) {
                if (len >= 3) {
                    count++;
                }
                len = 0;
            }
            else {
                if (len >= 3) {
                    count++;
                }
                printf("%d\n", count);
                f = 0;
                break;
            }
        }
        s = getchar();
    }
    if (f) {
        f = 0;
        printf("%d\n", count);
    }
    if (len >= 3 && f) {
        printf("%d\n", 1);
    }
    return 0;
}
