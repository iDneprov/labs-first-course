#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a>b) ? a : b;
}

int min(int a, int b) {
    return (a<b) ? a : b;
}

int sign(int a) {
    if(a > 0) {
        return 1;
    }
    if(a == 0) {
        return 0;
    }
    if( a < 0) { 
        return -1;
    }
}

int Inext(int i, int j, int k, int l) {
    return (abs(max(i*(k+5),j*(k+6)))-abs(min(j*(k+7),l*(k+8)))) % 20;
}

int Jnext(int i, int j, int k, int l) {
    return ((3-sign(i-j))*abs(min(min(i*j+5,i*j-3),i*j+6))) % 25 - 7;
}

int Lnext(int i, int j, int l) {
    return i % 10 + j % 10 + l % 10;
}

int Check(int i, int j) {
    return i>=5 && i<=10 && j<=-5 && j>=-10;
}

int main(){
int i0 = 10, j0 = 20, l0 = -1, k;
int in = 0;
for( k = 0; k<=50; k++) {
    int i=Inext(i0, j0, k, l0);
    int j=Jnext(i0, j0, k, l0);
    int l=Lnext(i0, j0, l0);
    i0 = i, j0 = j, l0 = l;
    if(Check(i, j)) {
        in=1;
        break;
    }
}
if(in) {
    printf("Попадание на шаге k=%d\n", k);
} else {
    printf("Промах k=%d, i=%d, j=%d, l=%d\n", k, i0, j0, l0);
}
return 0;
}