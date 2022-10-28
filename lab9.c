#include <stdio.h>

int i0 = 24, Jj = -14, l0 = 9;

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

int Move(int *i, int *j, int *l, int *k) {
    int i1 = *i, j1 = *j, l1 = *l, k1 = *k;
    *i = (i1 + k1) * (j1 - k1) * (l1 + k1) % 25;
    *j = Min(i1 + k1, Max(j1 - k1, l1 - k1)) % 30;
    *l = Sign(i1) * Abs(j1 - l1) - Sign(j1) * Abs(i1 - k1);
    return 0;
}

int Checking(int *i, int *j) {
    int i1 = *i, j1 = *j;
    if (((0 <= i1) && (i1 <= 20)) && ((-20 <= j1) && (j1 <= 0))) {
        return 1;
    } else {
        return 0;
    }
}
int main(void) {
    int i = i0, j = Jj, l = l0, k = 0;
    while (k <= 50) {
        Move(&i, &j, &l, &k);
        printf("%d %d %d %d\n", i, j, l, k);
        if (Checking(&i, &j)) {
            printf("I'm horny!!!\n");
            printf("%d steps for get me!\n", k);
            printf("%d %d %d %d\n", i, j, l, k);
            return 0;
        } else {
            k++;
        }
    }
return 0;    
}