

#include <stdio.h>

#define NUM 1
#define SPACE 2
#define ENTER 3
#define END 4

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
    int n = 1, maxn = 100, state = 0, flag = 0, number = 0, inI = 0, inJ = 0;
    int a[maxn][maxn];
    char c;
    while (1) {
        c = getchar();
        state = StateUpdate(c);
        if (state == NUM) {
            number = ClayNum(c, number, flag);
            flag = 1;
        } else if (state == SPACE) {
            a[inJ][inI] = number;
            number = 0;
            inI += 1;
            flag = 0;
        } else if (state == ENTER){
            a[inJ][inI] = number;
            number = 0;
            inI = 0;
            inJ += 1;
            flag = 0;
        } else {
            a[inI][inJ] = number;
            break;
        }
    }
    
    n = inJ;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        putchar('\n');
    }

    putchar('\n');
    int tempI = 0;
    int tempJ = 0;
    for (int h = 0; h <= n * n - 2; h++) {
        if (h < n) { 
            if (h % 2 == 0) {
            tempI = h;
            tempJ = 0;
            for (int k = 0; k < h + 1; k++) {
                printf("%d ", a[tempI][tempJ]);
                tempI -= 1;
                tempJ += 1;
            }
            } else {
                tempI = 0;
                tempJ = h;
                for (int k = 0; k < h + 1; k++) {
                    printf("%d ", a[tempI][tempJ]);
                    tempI += 1;
                    tempJ -= 1;
                }
            }
        } else {
            if (h % 2 == 0) {
                tempJ = (h % n) + 1;
                tempI = n - 1;
                for (int k = 0; k < n + n - 1 - h ; k++) {
                    printf("%d ", a[tempI][tempJ]);
                    tempI -= 1;
                    tempJ += 1;
                }
            } else {
                tempJ = n - 1;
                tempI = (h % n) + 1;
                for (int k = 0; k < n + n - 1 - h; k++) {
                    printf("%d ", a[tempI][tempJ]);
                    tempI += 1;
                    tempJ -= 1;
                }
            }
        }
    }
}

