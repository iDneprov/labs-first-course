#include <stdio.h>

#define MAX_N 8

void DeliteSameColumnsInMatrix() {
    int matrix[MAX_N][MAX_N], columns[MAX_N];
    char s = getchar();
    int elementInFirstString = 0, n = 0, flag = 0, k, sign = 1;
    if (s == '-') {
        sign = -1;
    } else {
        elementInFirstString = s - '0';
    }
    while (!(s == '\n' || s == EOF)) {
        s = getchar();
        if (s == ' ' || s == '\n' || s == EOF) {
            matrix[0][n] = sign * elementInFirstString;
            elementInFirstString = 0;
            n++;
            sign = 1;
        } else {
            if (s == '-') {
                sign = -1;
            } else {
                elementInFirstString = elementInFirstString * 10 + s - '0';
            }
        }
    }
    for (int i = 1; i < n; i++) {
        columns[i] = 1;
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    columns[0] = 1;
    for (int j = 0; j < n; j++) {
        k = j + 1;
        for (; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] != matrix[i][k]) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                columns[k] = 0;
            }
            flag = 0;
        }   
    }
    for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (columns[j]) {
                    printf("%d ", matrix[i][j]);
                }
            }
        printf("\n");
    }
    if (s != EOF) {
        DeliteSameColumnsInMatrix();
    }
}

int main(void) {
    DeliteSameColumnsInMatrix();
}

