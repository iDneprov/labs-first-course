#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
 
 
 
int max(int a, int b) {
    if(a > b) return a; 
    
    return b;
}
int maxe(int a, int b, int c) {
    if (a > b && a>c) return a;
    if (b > a && b>c) return b;
    if (c > b && c>a) return c;
}
 
int min(int a, int b) {
    if(a < b) return a;
    return b;
}
 
int mod(int a, int b){
    return a - (a / b) * b;
}
 
 
bool isPointInArea (int i, int j)
{
 
    if (i > -20-j && i < -10-j) return true;
    return false;
}
 
 
 
int main() {
    const int i0 = 12, j0 = 4, l0 = 3;
    int i=i0, j=j0, l=l0, k=0;
    while(!isPointInArea(i, j)){
        if(k==50)break;
        printf("(i,j) = (%d,%d)\n", i, j);
        printf("l = %d\n", l);
        printf("k = %d\n", k);
        int i_prev = i, j_prev = j, l_prev = l;
        i = mod(i_prev *j_prev/(abs(l_prev)+1) + j_prev*l_prev/(abs(i_prev)+1) +i_prev*l_prev/(abs(j_prev)+1),30);
        j = mod(i_prev*max(j_prev, l_prev),20)+mod(j_prev*min(i_prev, l_prev),30)-k;
        l = mod(maxe( i_prev*j_prev, i_prev*l_prev, j_prev*l_prev),30)+20;
        k++;
    }
    if(k==50&&!isPointInArea(i, j))
        printf("The point didn't reach the area in 50 steps\n");
    else
        printf("Point reached the area less or equal then 50 steps(%d)\n", k);
    printf("The coordinates are (%d, %d)\n", i, j);
    printf("The dynamic parameter of running is %d\n", l);
}