#include<stdio.h>

int CheckDotInArea(int i, int j) {
    if ((j <= -i - 10) && (j >= -i - 20)) {
        return 1;
    }
    return 0;
}

int Min(int a, int b) {
    if (b < a) {
        return b;
    }
    if (a < b) {
        return a;
    }
    if (a == b) {
        return b;
    }
}

int Max(int a, int b) {
    if (a > b) {
        return a;
    }
    if (b > a) {
        return b;
    }
    if (a == b) {
        return b;
    }
}

int Abs(int a) {
    if (a >= 0) {
        return a;
    }
    if (a < 0) {
        return -a;
    }
}

int NextJ(int i, int j, int l, int k) {
        return Max(k - 1 - i, Min(j, Max(i - l, j - l))) % 30;
}

int NextL(int i, int j, int l, int k) {
        return l*l % 20 - Max(i, j) % k;
}

int NextI(int i, int j, int l, int k) {
        return Abs(i - l) + Min(j % 10, l * (k - 1) % 10) - 20;
}

int Lab9 () {
    int i = -30;
    int j = -4;
    int l = 12;

    for(int k = 0; k <= 50; ++k) {
        int x = i;
        int y = j;
        int z = l;
        if (CheckDotInArea(i, j) == 1) {
            return k;
        } else {
            if (k != 0) {
            i = NextI(x, y, z, k);
            j = NextJ(x, y, z, k);
            l = NextL(x, y, z, k);
            } else {
                continue;
            }
        }
    }

    return -1;
}

int main(void) {
    int k = Lab9();
    if (k == -1) {
        printf("We are not in the area\n");
    } else {
        printf("We are in the area with k = %d\n", k);
    }
}



