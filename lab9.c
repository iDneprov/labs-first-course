#include <stdio.h>

#define I0 24;
#define J0 -14;
#define L0 9;

int Abs(int a) {
    return (a > 0) ? a : -a;
}

int Sign(int a) {
    if (a < 0) {
        return -1;
    }
    if (a > 0) {
        return 1;
    }
    return 0;
}

int Max(int a, int b) {
    return (a >= b) ? a : b;
}

int Min(int a, int b) {
    return (a >= b) ? b : a;
}

int MoveI(int i, int j, int l, int k) {
    return (i + k) * (j - k) * (l + k) % 25;
}

int MoveJ(int i, int j, int l, int k) {
    return Min(i + k, Max(j - k, l - k)) % 30;
}
    
int MoveL(int i, int j, int l, int k) {
    return Sign(i) * Abs(j - l) - Sign(j) * Abs(i - k);
}

int Checking(int i, int j) {
    return (((0 <= i) && (i <= 20)) && ((-20 <= j) && (j <= 0)));
}

int main(void) {
    int i, j, l, k = 1;
    i = I0;
    j = J0;
    l = L0;
    for (k; k <= 50; ++k) {
        i = MoveI(i, j, l, k);
        j = MoveJ(i, j, l, k);
        l = MoveL(i, j, l, k);
        if (Checking(i, j)) {
            printf("It's inside!!!\n");
            printf("%d steps made for get it inside!\n", k);
            printf("%d %d %d %d\n", i, j, l, k);
            return 0;
        }
    }
return 0;    
}
