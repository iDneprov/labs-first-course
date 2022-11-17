//19 вариант
#include <stdio.h>

#define MAX_N 7

int main() {
    int mass[MAX_N][MAX_N];
    int i, l, n;

    scanf("%i", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &mass[i][j]);     
    for (l = 0; l < n; ++l) {
        for (i = 0; i <= l; ++i)
            if (l % 2 == 0)
                printf("%d ", mass[l][i]);  
            else 
                printf("%d ", mass[i][l]);     
        for (i = 0; i < l; ++i)
            if (l % 2 == 0)
                printf("%d ", mass[l - i - 1][l]);
            else 
                printf("%d ", mass[l][l - i - 1]);   
    }
    putchar('\n');
    return 0;
}
