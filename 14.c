#include <stdio.h>

int main() {
    const int max_size = 100;
    int n;
    int m[max_size][max_size];

    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (int q = n - 1; q >= 0; q--) {
        int i = q;
        for (int j = 0; (j < n) && (i < n); j++) {
            printf("%d ", m[i][j]);
            i++;
        }
    }
    for (int q = 1; q < n; q++) {
        int j = q;
        for (int i = 0; (i < n) && (j < n); i++) {
            printf("%d ", m[i][j]);
            j++;
        }
    }
    return 0;
}