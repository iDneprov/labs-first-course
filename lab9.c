#include <stdio.h>

int Max(int v1, int v2, int v3){  
    int max = v1;
    if (v2 > max)
    max = v2; 
    if (v3 > max)
    max = v3;
    return max;
}

int Min(int v1, int v2, int v3){
    int min = v1;
    if (v2 < min)
    min = v2;
    if (v3 < min)
    min = v3;
    return min;
}

void Move(int k, int *iUk, int *jUk, int *lUk){
    int iNew, jNew, lNew;
    int v1, v2, v3;
    int i  = *iUk, j = *jUk, l = *lUk;
    iNew = (i * i * i - j * j * j + l * l * l - k) % 20;
    v1= i * j * l - k;
    v2= i * i * l - k;
    v3= j * l * l - k;
    jNew = Min (v1, v2, v3) % 30;
    lNew = Max (v1, v2, v3) % 30;  
    *iUk = iNew;
    *jUk = jNew;
    *lUk = lNew;
}

int Check(int *iUk, int *jUk, int *lUk ){
    const int x = -10, y = -10, x2 = -20, y2 = -20, r = 10;
    int i = *iUk, j = *jUk, l = *lUk;
    if(( (i - x) * (i - x) + (j - y) * (j - y) <= r * r) && ( (i - x2) * (i - x2) + (j - y2) * (j - y2) <= r * r))
        return 1; 
    return 0;
}

int main () {
const int i0 = 6, j0 = 27, l0 = -15;
int i, j, l;
    i = i0;
    j = j0;
    l = l0;
    int *iUk = &i, *jUk = &j, *lUk = &l;
    int k = 0;
    while(k <= 50){
        if(Check(iUk, jUk, lUk)){
             printf ("попадание\n");
             printf ("координа абсцисс %d\n", i);
             printf ("координа ординат %d\n", j);
             printf ("параметр движениея %d\n", l);
             printf ("число интераций %d\n", k);
             return 0;
        }
        Move(k, iUk, jUk, lUk);
        ++k;
    }  
    printf ("число интераций %d\n", k - 1);
    printf ("промах\n");
    printf ("координа абсцисс %d\n", i);
    printf ("координа ординат %d\n", j);
    printf ("параметр движениея %d\n", l);
  return 0;
}
