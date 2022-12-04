#include <stdio.h>

#define MaxN 7

int main(){
    int Arr[MaxN][MaxN];
    int dir[4] = { 1, 0, -1, 0 };
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j) {
            scanf("%d", &Arr[i][j]);
        }
    }
    int l = n;
    int p = 0;
    int i = n-1, j = n;
    while (l != 0) {
        for (int k = 0; k != l; ++k) {
            j -= dir[p % 4];
            i -= dir[(p + 3) % 4];
            printf("%d ", Arr[i][j]);
        }
        ++p;
        l -= p % 2;
    }
    printf("\n");
}

