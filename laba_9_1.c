#include <stdio.h>

int abs(int a){
    if (a >= 0) return a;
    if (a < 0) return a * -1;
}
int max(int a, int b){
    if (a>b) return a;
    if (b>a) return b;
    if (a==b) return a;
}

int min(int a, int b){
    if (a>b) return b;
    if (b>a) return a;
    if (a==b) return a;
}

int sign(int a){
    if (a<0) return -1;
    if (a==0) return 0;
    if (a>0) return 1;
}

int CheckInArea( int x, int y){
    if (((x >= -10) & (x <= 0)) & ((y >= 10 - abs(x)) & (y <= 10 + abs(x)))) return 1;
    else return 0; 
}

void main(){
    int j0, k, l0, i0, i, j , l;
    i = -12;
    j = -22;
    l = 11;
    k = 0;
    for (k = 1; k < 50; ++k){
        i0 = i;
        j0 = j;
        l0 = l;
        i = max(min(i0 - j0, j0 - l0) % 20, min(i0 - l0, j0 - k) % 20) + 10;
        j = sign(i0 - j0) * min(i0 % 20, j0 % 20) - max(abs(i0 - l0), abs(k - 20)) % 20 + 20;
        l = (i0 % 10) * (j0 % 10) + (l0 % 10);
        if  (CheckInArea(i, j)){
            printf("Success. k = %d\nFinal coordinates: i = %d   j = %d", k, i, j);
            break;
        }
    }
    if (!CheckInArea(i, j)){
        printf("Failure\nFinal coordinates: i = %d   j = %d", i, j);
    }
    
}