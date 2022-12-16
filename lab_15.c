#include <stdio.h>

#define MAXN 8

int main(void) {
    int m[MAXN][MAXN];
    int n, i, j, max = 0;

    scanf("%i", &n);
    for (i = 0; i != n ; ++i) {
        for (j = 0; j != n; ++j) {
            scanf("%i", &m[i][j]);
        }
    };
    
    for (i = 0; i != n; ++i) {
        for (j = 0; j != i + 1; ++j) {
            if (max < m[i][j]) {
                max = m[i][j];
            }
        }
    }

    printf("%i\n", max);

    for (j = 0; j != n; ++j) {
        for (i = 0; i != j + 1; ++i) {
            m[i][j] *= max;
        }
    }

    for (i = 0; i != n ; ++i) {
        for (j = 0; j != n; ++j) {
            printf("%i ", m[i][j]);
        }
        printf("\n");
    };
}