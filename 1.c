#include <stdio.h>

#define q 5
#define w 10

int Abs(int a) {
    return (a > 0) ? a : -a;
}

int Max(int a, int b) {
    return (a > b) ? a : b;
}

int Min(int a, int b) {
    return (a < b) ? a : b;
}

int Sign(int a) {
    if(a > 0) {
        return 1;
    }
    if(a == 0) {
        return 0;
    }
        return -1;
}

int INext(int i, int j, int k, int l) {
    return (Abs(Max(i * (k + 5),j * (k + 6)))-Abs(Min(j * (k + 7),l * (k + 8)))) % 20;
}

int JNext(int i, int j) {
    return (Abs(Min(Min(i * j + 5,i * j - 3),i * j + 6)) * (3 - Sign(i - j))) % 25 - 7;
}

int LNext(int i, int j, int l) {
    return i % 10 + j % 10 + l % 10;
}

int Check(int i, int j) {
    return i >= q && i <= w && j <= -q && j >= -w;
}

int main(){
int in = 0,i0 = 10, j0 = 20, l0 = -1, u;
int k;
for(k = 0; k<50; k++) {
    int i = INext(i0, j0, k, l0);
    int j = JNext(i0, j0);
    int l = LNext(i0, j0, l0);
    i0 = i, j0 = j, l0 = l;
    if(Check(i, j)) {
        in = 1;
        if(in == 1) {
    printf("Попадание на шаге k = %d\n", k);
    return 0;
        }
    }
}
if(k == 50) {
    printf("Промах k = %d i = %d j = %d l = %d\n", k, i0, j0, l0);
    return 0;
}
}
