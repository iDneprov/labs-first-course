#include <stdio.h>
#include <math.h>

int main(void) {
    int n, mxj, ans = 1;
    double mn = INFINITY;
    scanf("%d", &n);
    int mas[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &mas[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mas[i][j] <= mn) {
                mn = mas[i][j];
                mxj = j;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        ans *= mas[i][mxj];
    }
printf("%d\n", ans);
return 0;
}
