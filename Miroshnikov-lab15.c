#include <stdio.h>

#define MAX_N 8

int main() {
    int mas[MAX_N][MAX_N];
    int n, max, min;
    int imax = 0;
    int jmin = 0;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &mas[i][j]);
        }
    }
    max = mas[0][0];
    min = mas[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mas[i][j] > max) {
                max = mas[i][j];
                imax = i;
            }
            if (mas[i][j] < min) {
                min = mas[i][j];
                jmin = j;
            }
        }
    }
    int masi[n];
    int masj[n];
    for (int k = 0; k < n; ++k) {
        masi[k] = mas[imax][k];
        masj[k] = mas[k][jmin];
    }
    int ans[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[i][j] = masj[i] * masi[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", ans[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
