#include <stdio.h>

void MinMax (int *min, int *max, int *v1, int *v2, int *v3){

    *max = *v1;
    *min = *v1;
 
    if (*v2 > *max)
        *max = *v2;
    if (*v3 > *max)
        *max = *v3;
    if (*v2 < *min)
        *min = *v2;
    if (*v3 < *min)
        *min = *v3;
        
}

void Move (int k, int *i_Uk, int *j_Uk, int *l_Uk){
    int iNew, jNew, lNew;
    int v1, v2, v3;

    int i  =*i_Uk, j = *j_Uk, l = *l_Uk;

    iNew=(i * i * i - j * j * j + l * l * l - k) % 20;
    v1= i * j * l -k;
    v2= i * i * l -k;
    v3= j * l * l -k;

    int min, max;

    MinMax(& min, & max, & v1, & v2, & v3);

    jNew = min%30;
    lNew = max%30;
    
    *i_Uk = iNew;
    *j_Uk = jNew;
    *l_Uk = lNew;
}

int Check(int *i_Uk, int *j_Uk, int *l_Uk ){

    const int x=-10, y=-10, x2=-20, y2=-20, r=10;

    int i=*i_Uk, j=*j_Uk, l=*l_Uk;

    if(( (i - x) * (i - x) + (j - y) * (j - y) <= r * r) && ( (i - x2) * (i - x2) + (j - y2) * (j - y2) <= r * r))
        return 1;
    
    return 0;
}

int main (){
const int i0 = 6, j0 = 27, l0 = -15;
int i, j, l;
    i= i0;
    j= j0;
    l= l0;
    int *i_Uk=&i, *j_Uk=&j, *l_Uk=&l;
    int k = 0;

    while(k <= 50){
        if(Check(i_Uk, j_Uk, l_Uk)){
             printf ("попадание\n");
             printf ("координа абсцисс %d\n", i);
             printf ("координа ординат %d\n", j);
             printf ("параметр движениея %d\n", l);
             printf ("число интераций %d\n", k);
             return 0;
        }
        Move(k, i_Uk, j_Uk, l_Uk);
        ++k;
    }
    
    printf ("число интераций %d\n", k-1);
    printf ("промах\n");
    printf ("координа абсцисс %d\n", i);
    printf ("координа ординат %d\n", j);
    printf ("параметр движениея %d\n", l);
  return 0;
}
