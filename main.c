#include <stdio.h>

#define MaxSize 7

int main() {
    int mas[MaxSize][MaxSize];
    int n = 1, j = 1, flag = 1, i = 1, l, p, k = 0, e = 0;
    int dir[4] = {-1, 0, 1, 0};
    scanf("%d", &mas[0][0]);
    int f = getchar();
    while (1) {
        if(f == '\n' && flag == 1 && n == 1) {
            printf("%d\n", mas[0][0]);
            scanf("%d", &mas[0][0]);
            e = 1;
        }
        if(f == '\n' && flag == 1 && n != 1) {
            flag = 2;
            j = 0;
        }
        if (f != '\n' && flag == 1 && f != EOF) {
            n += 1;
            scanf("%d", &mas[0][j]);
            j += 1;
        }
        if (f == EOF && n == 1 && k == 0 && e == 1) {
            printf("%d\n", mas[0][0]);
            break;
        }
        if (f == EOF && n != 1 && flag != 4) {
            break;
        }
        if (flag == 2) {
            if (j == n && i != n - 1) {
                j = 0;
                i += 1;
            }
            scanf("%d", &mas[i][j]);
            if(j == n - 1 && i == n - 1) {
                flag = 3;
            }
            j += 1;
        }
        if (flag == 3) {
        l = n;
        p = 0;
        i = n; j = 0;
        flag = 4;
        }
        if (flag == 4) {
            if(l != 0) {
                if (k < l) {
                    i += dir[p % 4];
                    j += dir[(p+1) % 4];
                    printf("%d ", mas[i][j]);
                    ++k;
                } else {
                    k = 0;
                    ++p;
                    l -= p % 2;
                }
            } else {
                flag = 1;
                putchar('\n');
                n = 1; j = 1; i = 1; k = 0;
                scanf("%d", &mas[0][0]);
            }
        }
        if (flag != 4) {
            f = getchar();
        }
    }
    return 0;
}
