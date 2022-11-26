#include <stdio.h>
#define MX 7

int main() {
    int m[MX][MX];
    int d = 0;
    int s;
    int row = 0;
    int col = 0;
    int size = 0;
    
    while ((s = getchar()) != EOF) {
        if (s >= '0' && s <= '9') {
            d = d*10 + (s - '0');
        } else if (s == ' ') {
            m[row][col] = d;
            d = 0;
            ++col;
        } else if (s == '\n') {
            size = col + 1;
            m[row][col] = d;
            d = 0;
            ++row;
            col = 0;
        }
    }
    
    if (d) {
        m[row][col] = d;
    }

    int l = size;
    int p = 0;
    int i = -1, j = 0;
    int dir[4] = {0, 1, 0, -1};
    while (l != 0) {
        for (int k = 0; k != l; ++k) {
            j += dir[p % 4];
            i += dir[(p+1) % 4];
            printf("%d ", m[i][j]);
        }
        ++p;
        l -= p % 2;
    }
    putchar('\n');
    return 0;
}
