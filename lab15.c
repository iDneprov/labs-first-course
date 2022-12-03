#include <stdio.h>

int main() {
    int n, x, y, sumDiag;
    scanf("%i", &n);
    int m[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%i", &m[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        x = i;
        y = n - 1 - i;
        sumDiag = m[x][y];
        while ((x != 0) && (y != 0)) {
            x -= 1;
            y -= 1;
            sumDiag += m[x][y];
            sumDiag += m[n - 1 - y][n - 1- x];
        }
        m[i][n - 1 - i] = sumDiag;
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

