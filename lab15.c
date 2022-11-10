#include <stdio.h>
#include <stdlib.h>

#define MAX_N 8


int Ans(int **mat, int len, int maxim) {
    int arr[MAX_N];
    for (int i = 0; i < MAX_N; ++i) {
        arr[i] = 1;
    }
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
    for (int i = 0; i < MAX_N; ++i) {
        arr[i] = 1;
    }
    return 0;
}

int main(void) {
    int i = 0, j = 0, x, c = ' ', curRow = -1, maxim = 0, flag = 1;
    int** mat = (int **)malloc(sizeof(int *) * MAX_N);
    for (int i = 0; i < MAX_N; ++i) {
        mat[i] = (int *)malloc(sizeof(int) * MAX_N);
    }
    while (c != EOF) {
        if (c == '\n') {
            if (curRow == -1) {
              /*Матрица началась*/
                curRow = j - 1;
            }
            if (i == curRow) {
              /*Матрица считалась*/
                Ans(mat, curRow + 1, maxim);
                i = -1;
                j = -1;
                curRow = -1;
                maxim = 0;

            }
            j = 0;
            ++i;
        }
        scanf("%d", &x);
        if(flag) {
            maxim = x;
            flag = 0;
        } else if (x > maxim) {
            maxim = x;
        }
        mat[i][j] = x;
        ++j;
        c = getchar();
    }

    return 0;
}
