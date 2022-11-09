#include <stdio.h>
#include <stdlib.h>

#define MAX_N 8


int Ans(int **mat, int len, int maxim) {
    int arr[MAX_N] = {1, 1, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (mat[i][j] == maxim) {
                arr[j] = 0;
            }
        }
    }

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (arr[j] == 1) {
                printf("%d ", mat[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}

int main(void) {
    int i = 0, j = 0, x, c = ' ', cur_row = -1, maxim = 0;
    int** mat = (int **)malloc(sizeof(int *) * MAX_N);
    for (int i = 0; i < MAX_N; ++i) {
        mat[i] = (int *)malloc(sizeof(int) * MAX_N);
    }
    while (c != EOF) {
        if (c == '\n') {
            if (cur_row == -1) {
              /*Матрица началась*/
                cur_row = j - 1;
            }
            if (i == cur_row) {
              /*Матрица считалась*/
                Ans(mat, cur_row + 1, maxim);
                i = -1;
                j = -1;
                cur_row = -1;
                maxim = 0;

            }
            j = 0;
            ++i;
        }
        scanf("%d", &x);
        if (x > maxim) {
            maxim = x;
        }
        mat[i][j] = x;
        ++j;
        c = getchar();
    }
}
