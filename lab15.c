#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int matrix[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int matrixMatrix[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrixMatrix[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                matrixMatrix[i][j] += (matrix[i][k] * matrix[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrixMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
