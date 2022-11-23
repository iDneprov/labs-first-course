#include <stdio.h>

#define MAX_N 7

int main() {
    int mas[MAX_N][MAX_N];
    int n, i, j;
    int countoper = 0;
    int iter = 1;
    int condoper = 1;
    scanf("%i", &n);
    for (int k = 0; k < n; ++k) {
        for (int m = 0; m < n; ++m) {
            scanf("%d", &mas[k][m]);
        }
    }
    i = n - (n / 2 + 1);
    j = n - (n / 2 + 1);
    if (n == 1) {
        printf("%d", mas[0][0]);
    } else {
        countoper = 2 * n - 1;
    }
    while (countoper != 0) {
        if ((condoper == 1) && (countoper != 1)) {
            if (countoper == 2 * n - 1) {
                for (int k = i; k <= i + iter; ++k) {
                    printf("%d ", mas[k][j]);
                }
            } else {
                for (int k = i + 1; k <= i + iter; ++k) {
                    printf("%d ", mas[k][j]);
                }
            }
            i += iter;
            for (int m = j + 1; m <= j + iter; ++m) {
                printf("%d ", mas[i][m]);
            }
            j += iter;
            condoper = 0;
            iter += 1;
            countoper -= 2;
        }
        if ((condoper == 0) && (countoper != 1)) {
            for (int k = i - 1; k >= i - iter; --k) {
                printf("%d ", mas[k][j]);
            }
            i -= iter;
            for (int m = j - 1; m >= j - iter; --m) {
                printf("%d ", mas[i][m]);
            }
            j -= iter;
            condoper = 1;
            iter += 1;
            countoper -= 2;
        }
        if ((condoper == 1) && (countoper == 1)) {
            for (int k = i + 1; k <= i + iter - 1; ++k) {
                printf("%d ", mas[k][j]);
            }
            countoper -= 1;
        }
        if ((condoper == 0) && (countoper == 1)) {
            for (int k = i - 1; k >= i - iter + 1; --k) {
                printf("%d ", mas[k][j]);
            }
            countoper -= 1;
        }
    }
    putchar('\n');
    return 0;
}

