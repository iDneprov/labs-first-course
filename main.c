#include <stdio.h>

#define MAX_SIZE 8

int main() {
    int mat[MAX_SIZE][MAX_SIZE];
    int dir[MAX_SIZE];
    int n, min;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &mat[i][j]);
            if (i == 0 && j == 0) {
                min = mat[i][j];
            }
            if (mat[i][j] < min) {
                min = mat[i][j];
            }
        }
        dir[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == min) {
                dir[i] = 0;
                break;
            }
        }
        if (dir[i] == 1) {
            for (int j = 0; j < n; ++j) {
                printf("%d ", mat[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}
