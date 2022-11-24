#include <stdio.h>

#define NUM 1
#define SPACE 2
#define ENTER 3
#define END 4
#define MAX_N 8
#define GROUP 110


int StateUpdate(char c) {
    if (c == '\n') {
        return ENTER;
    } else if (c == ' ') {
        return SPACE;
    } else if (c >= '0' && c <= '9') {
        return NUM;
    } else {
        return END;
    }
}

int ClayNum(char c, int num, int flag) {
    if (flag == 1) {
        num *= 10;
    }
    num += c - '0';
    return num;
}

int main() {
    int n = 1, state = 0, flag = 0, number = 0, inI = 0, inJ = 0;
    int a[MAX_N][MAX_N];
    int b[MAX_N][MAX_N];
    char c;
    while (1) {
        c = getchar();
        state = StateUpdate(c);
        if (state == NUM) {
            number = ClayNum(c, number, flag);
            flag = 1;
        } else if (state == SPACE) {
            a[inJ][inI] = number;
            b[inJ][inI] = number;
            number = 0;
            inI += 1;
            flag = 0;
        } else if (state == ENTER) {
            a[inJ][inI] = number;
            b[inJ][inI] = number;
            number = 0;
            if (inJ == 0) {
                n = inI + 1;
            }
            inI = 0;
            inJ += 1;
            flag = 0;
        } else {
            a[inI][inJ] = number;
            b[inJ][inI] = number;
            inJ += 1;
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = b[(i + (GROUP % n)) % n][j];
            printf("%d ", a[i][j]);
        }
        putchar('\n');
    }
}
