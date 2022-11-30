#include <stdio.h>

int Check(char s) {
    return ((s != EOF) && (s != '\n') && (s != '.') && (s != ',') && (s != ' '));
}

int LetterCheck(char s) {
    return ((s == 'p') || (s == 't') || (s == 'k') || (s == 'f') || (s == 's'));
}

int main(void) {
    int f = 1, flag = 0;
    char s;
    s = getchar();
    while (1) {
        if (Check(s)) {
            if (LetterCheck(s)) {
                f = 0;
            }
        }
        if (Check(s) == 0 && s != EOF) {
            if (f == 1) {
                flag = 1;
                break;
            } else {
                f = 1;
            }
        }
        if (s == EOF) {
            break;
        }
        s = getchar();
    }
    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
