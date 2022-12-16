#include <stdio.h>

#define MAXN 7

int main(void) {
    int m[MAXN][MAXN];
    int i, n, j, l, f = 1;

    scanf("%i", &n);
    for (i = 0; i != n ; ++i) {
        for (j = 0; j != n; ++j) {
            scanf("%i", &m[i][j]);
        }
    };

    for (l = 0; l != n; ++l) {
        if (f == 1) {
            for (i = l, j = 0; i != -1 && j != l + 1; --i, ++j) {
                printf("%i ", m[i][j]);
            }
        } else {
            for (j = l, i = 0; j != -1 && i != l + 1; --j, ++i) {
                printf("%i ", m[i][j]);
            }
        }
        if (l != 0) {
            f *= -1;
        }
    }

    f = (n % 2 == 0) ? -1 : 1;
    for (l = 1; l != n; ++l) {
        if (f == 1) {
            for (j = l, i = n - 1; j != n && i != l - 1; ++j, --i) {
                printf("%i ", m[i][j]);
            }
        } else {
            for (i = l, j = n - 1; i != n && j != l - 1; ++i, --j) {
                printf("%i ", m[i][j]);
            }
        }
        f *= -1;
    }

}
