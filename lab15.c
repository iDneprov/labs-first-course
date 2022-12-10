#include <stdio.h>

#define N_MAX 8

int main(void) {
    int matrix[N_MAX][N_MAX];
    int n, p = -2147483647, ma = 2147483647, dir[8] = { 0, 0, 0, 0, 0, 0, 0, 0 }, mi[8] = { 0, 0, 0, 0, 0, 0, 0, 0 }, index = 0;
    scanf_s("%d", &n);
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            scanf_s("%d", &matrix[i][j]);
            if (matrix[i][j] > p) {
                p = matrix[i][j];
            }
            if (matrix[i][j] < ma) {
                ma = matrix[i][j];
                index = i;
            }
        }
    }
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            if (matrix[i][j] == p) {
                dir[i] = 1;
            }
            if (i == index) {
                mi[j] = matrix[i][j];
            }
        }
    }
    putchar('\n');
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            if (dir[i] == 1) {
                matrix[i][j] = mi[j];
            }
        }
    }
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
    }
}
