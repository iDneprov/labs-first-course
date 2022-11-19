#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

int Max(int a, int b) {
    return a > b ? a : b;
}

int Maxe(int a, int b, int c) {
    return Max(Max(a, b), c);
}

int Min(int a, int b) {
    return a > b ? b : a;
}

int Mod(int a, int b) {
    return a - (a / b) * b;
}

int isPointInArea(int i, int j) {
    return (i > -20 - j && i < -10 - j);
}

int main() {
    const int i0 = 12, j0 = 4, l0 = 3;
    int i = i0, j = j0, l = l0, k = 0;
    while (!isPointInArea(i, j)) {
        if (k == 50)
            break;
        printf("(i,j) = (%d,%d)\n", i, j);
        printf("l = %d\n", l);
        printf("k = %d\n", k);
        int i_prev = i, j_prev = j, l_prev = l;
        i = Mod(i_prev * j_prev / (abs(l_prev) + 1) + j_prev * l_prev / (abs(i_prev) + 1) + i_prev * l_prev / (abs(j_prev) + 1), 30);
        j = Mod(i_prev * Max(j_prev, l_prev), 20) + Mod(j_prev * Min(i_prev, l_prev), 30) - k;
        l = Mod(Maxe(i_prev * j_prev, i_prev * l_prev, j_prev * l_prev), 30) + 20;
        k++;
    }
    if (k == 50 && !isPointInArea(i, j))
        printf("The point didn't reach the area in 50 steps\n");
    else
        printf("Point reached the area less or equal then 50 steps(%d)\n", k);
    printf("The coordinates are (%d, %d)\n", i, j);
    printf("The dynamic parameter of running is %d\n", l);
}
