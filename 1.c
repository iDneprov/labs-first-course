#include <stdio.h>
#include <stdlib.h>

#define I_START 10
#define J_START 20
#define L_START -1

int Max(int a, int b) {
    return (a>b) ? a : b;
}

int Min(int a, int b) {
    return (a<b) ? a : b;
}

int Sign(int a) {
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

int INext(int i, int j, int k, int l) {
    return (abs (Max (i*(k+5),j*(k+6)))-abs (Min (j*(k+7),l*(k+8)))) % 20;
}

int JNext(int i, int j, int k, int l) {
    return ((3-Sign (i-j))*abs (Min (Min (i*j+5,i*j-3),i*j+6))) % 25 - 7;
}

int LNext(int i, int j, int l) {
    return i % 10 + j % 10 + l % 10;
}

int Check(int i, int j) {
    return i>=5 && i<=10 && j<=-5 && j>=-10;
}

int Lab9(int I, int J, int L){
int in = 0;
int k;
for( k = 0; k<=50; k++) {
    int I_NEW=INext(I, J, k, L);
    int J_NEW=JNext(I, J, k, L);
    int L_NEW=LNext(I, J, L);
    I = I_NEW, J = J_NEW, L = L_NEW;
    if(Check(I_NEW, J_NEW)) {
        in=1;
        break;
    }
}
if(in) {
    printf("Попадание на шаге k=%d\n", k);
} else {
    printf("Промах k=%d, I=%d, J=%d, L=%d\n", k, I, J, L);
}
return 1;
}

int main(){
    Lab9(I_START, J_START, L_START);
    return 0;
}

