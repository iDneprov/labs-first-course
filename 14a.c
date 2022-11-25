#include <stdio.h>

#define MAX_N 7

void MatrixPrintElements() {
    int matrix[MAX_N][MAX_N], variations[4] = {1, 0, -1, 0};
    char s = getchar();
    int elementInFirstString = 0, n = 0, sign = 1;
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
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int len = n, p = 0, i = -1, j = n - 1;
    while (len > 0) {
        for (int k = 0; k < len; k++) {
            i += variations[p % 4];
            j += variations[(p + 1) % 4];
            printf("%d ", matrix[i][j]);
        }
        p++;
        len -= p % 2;
    }
    if (s != EOF) {
        printf("\n");
        MatrixPrintElements();
    } 
}

int main(void) {
    MatrixPrintElements();
}