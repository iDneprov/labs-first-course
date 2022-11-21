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
    if (n == 1) {
        printf("%d\n", matrix[0][0]);
    } else {
        int i = 0;
        int j = 0;
        int above_diagonal = -1;
        int move_up = 0;
        while (1) {
            if (above_diagonal == -1) {
                if (i != n - 1) {
                    printf("%d ", matrix[i][j]);
                    ++i;
                    ++j;
                } else {
                    printf("%d ", matrix[i][j]);
                    move_up = 1;
                    above_diagonal = 1;
                    --i;
                }
            }
            if (i == 0 && j == n - 1) {
                printf("%d %d\n", matrix[i][j], matrix[n - 1][0]);
                break;
            }
            if (j == 0 && i == n - 1) {
                printf("%d %d\n", matrix[i][j], matrix[0][n - 1]);
                break;
            }
            if (above_diagonal == 1) {
                if (move_up == 1) {
                    if (i != 0) {
                        printf("%d ", matrix[i][j]);
                        --i;
                        --j;
                    } else {
                        printf("%d ", matrix[i][j]);
                        j = (n - j - 1) + i;
                        i = n - 1;
                        above_diagonal = 0;
                    }
                } else {
                    if (j != n - 1) {
                        printf("%d ", matrix[i][j]);
                        ++i;
                        ++j;
                    } else {
                        printf("%d ", matrix[i][j]);
                        move_up = 1;
                        --i;
                    }
                }
            } 
            if (above_diagonal == 0) {
                if (move_up == 1) {
                    if (j != 0) {
                        printf("%d ", matrix[i][j]);
                        --i;
                        --j;
                    } else {
                        printf("%d ", matrix[i][j]);
                        move_up = 0;
                        ++i;
                    }
                } else {
                    if (i != n - 1) {
                        printf("%d ", matrix[i][j]);
                        ++i;
                        ++j;
                    } else {
                        printf("%d ", matrix[i][j]);
                        above_diagonal = 1;
                        j = n - 1 - j;
                        i = 0;
                    }
                }
            }
        }
    }
    return 0;
}