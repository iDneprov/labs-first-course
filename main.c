#include <stdio.h>

#define MAX_SIZE 7

int main() {
    int mas[MAX_SIZE][MAX_SIZE];
    int n;
    int dir[4] = {-1, 0, 1, 0};
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &mas[i][j]);
        }
    }
    int l = n;
    int p = 0;
    int i = n, j = 0;
    while (l != 0) {
        for (int k = 0; k < l; ++k) {
            i += dir[p % 4];
            j += dir[(p + 1) % 4];
            printf("%d ", mas[i][j]);
        }
        ++p;
        l -= p % 2;
    }
    putchar('\n');
}
