#include <stdio.h>

#define I -12
#define J -22
#define L 11

int Abs(int a) {
    return a >= 0 ? a : (a * -1);
}

int Max(int a, int b) {
    return a >= b ? a : b;
}

int Min(int a, int b) {
    return a <= b ? a : b;
}

int Sign(int a) {
    if (a<0) 
        return -1;
    if (a==0) 
        return 0;
    if (a>0) 
        return 1;
}

int CheckInArea( int x, int y) {
    if (((x >= -10) && (x <= 0)) && ((y >= 10 - Abs(x)) && (y <= 10 + Abs(x)))) 
        return 1;
    else 
        return 0; 
}

int main(void) {
    int j0, k, l0, i0, i, j , l;
    i = I;
    j = J;
    l = L;
    k = 0;
    
    for (k = 1; k < 51; ++k){
        i0 = i;
        j0 = j;
        l0 = l;
        
        i = Max(Min(i0 - j0, j0 - l0) % 20, Min(i0 - l0, j0 - k) % 20) + 10;
        j = Sign(i0 - j0) * Min(i0 % 20, j0 % 20) - Max(Abs(i0 - l0), Abs(k - 20)) % 20 + 20;
        l = (i0 % 10) * (j0 % 10) + (l0 % 10);
        
        if  (CheckInArea(i, j)){
            printf("Success. k = %d\nFinal coordinates: i = %d   j = %d", k, i, j);
            break;
        }
    }
    
    if (!CheckInArea(i, j)) {
        printf("Failure\nFinal coordinates: i = %d   j = %d", i, j);
    }
    
    return 0;
    
}
