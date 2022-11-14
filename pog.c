#include <stdio.h>
#include <stdbool.h>

int Max(int a, int b) {
    return a > b ? a : b;
}

int Min(int a, int b) {
    return a < b ? a : b;
}

int Abs(int a) {
    if(a >= 0) return a;
    else return -1 * a;
}

int Sign(int a) {
    if(a > 0) return 1;
    if(a == 0) return 0;
    if(a < 0) return -1;
}

int Modulo(int a, int b) {
    if (a % b == 0) return a / b;
    else if (a * b > 0) return a % b;
    else return a - (a/b-1) * b;
}

int main() {
    int i = 20, j = 0, l = 11;
    bool check = false;

    for (int k = 0; k < 50; k++) {
        if (i >= -10 && j >= 0 && j <= -i+10){
            printf("Hit\n steps:%d i=%d j=%d l=%d\n", k, i, j, l);
            check = true;
            break;
        }

        i = Modulo((i - k)*Max(j, l) + (j - k)*Min(i, l) + (l - k)*Max(i, j), 23);
        j = Modulo(-((i - k)*Min(j, l) + (j-k)+Max(i, l) + (l - k)*Min(i, j)), 27);  
        l = Abs(i + j - l - k)*Sign(i - j + l - k);
    }
    if (!check) {
        if (i >= -10 && j >= 0 && j <= -i+10) {
                printf("Hit\n steps:%d i=%d j=%d l=%d\n", 50, i, j, l);
                check = true;
            }
    }

    if (!check) printf("Miss\n steps:%d i=%d j=%d l=%d\n", 51, i, j, l);
}
