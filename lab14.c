#include <stdio.h>

#define N_MAX 7

int main(void) {
    int matrix[N_MAX][N_MAX];
    int dir[4] = { 1, 0, -1, 0 };
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int l = n;
    int p = 0;
    int i = n-1, j = -1;
    while (l != 0) {
        for (int k = 0; k != l; ++k) {
            j += dir[p % 4];
            i += dir[(p + 1) % 4];
            printf("%d ", matrix[i][j]);
        }
        ++p;
        l -= p % 2;
    }
    putchar('\n');
}
