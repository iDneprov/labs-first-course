#include <stdio.h>

enum {MaxSize = 100};

int main() {
    int mas[MaxSize][MaxSize];
    int n = 0, f = getchar(), j = 0;
    int dir[4] = {-1, 0, 1, 0};
    while (f != '\n') {
        n += 1;
        scanf("%d", &mas[0][j]);
        j += 1;
        f = getchar();
    }
    printf("%d\n", n);
    for(int i = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &mas[i][j]);
        }
    }
    int l = n;
    int p = 0;
    int i = n; j = 0;
    while(l != 0) {
        for(int k = 0; k < l; ++k) {
            i += dir[p % 4];
            j += dir[(p+1) % 4];
            printf("%d ", mas[i][j]);
        }
        ++p;
        l -=p % 2;
    }
    putchar('\n');
}
