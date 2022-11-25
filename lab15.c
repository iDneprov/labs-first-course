#include <stdio.h>

int main() {
    int n = 0, min = 0, c = 0;
    printf("Input: ");
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                if (c == 0) {
                    min = a[i][j];
                    c++;
                } else if (a[i][j] < min) {
                    min = a[i][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                a[i][j] *= min;
            }
        }
    }
    printf("Output: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}