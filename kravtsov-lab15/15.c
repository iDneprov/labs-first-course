#include <stdio.h>
#define MX 8

int findSumOfRow (int *m, int row, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum = sum + m[row * size + (MX - size) * row + i];
    }
    return sum;
}

int main() {
    int m[MX][MX];
    int d = 0;
    int s;
    int row = 0;
    int col = 0;
    int size = 0;
    int minFl = 0;
    int numRowMax = -1;
    int mx = -32767;
    
    while ((s = getchar()) != EOF) {
        if (s >= '0' && s <= '9') {
            d = d * 10 + (s - '0');
        } else if (s == ' ') {
            d = minFl ? -d : d;
            if (d > mx) {
                numRowMax = row;
                mx = d;
            }
            m[row][col] = d;
            d = 0;
            ++col;
            minFl = 0;
        } else if (s == '\n') {
            size = col + 1;
            d = minFl ? -d : d;
            if (d > mx) {
                numRowMax = row;
                mx = d;
            }
            m[row][col] = d;
            d = 0;
            ++row;
            col = 0;
            minFl = 0;
        } else if (s == '-') {
            minFl = 1;
        }
    }
    
    if (d) {
        d = minFl ? -d : d;
        if (d > mx) {
            numRowMax = row;
            mx = d;
        }
        m[row][col] = d;
    }

    printf("\nSum: %d", findSumOfRow(&m[0][0], numRowMax, size));
    return 0;
}
