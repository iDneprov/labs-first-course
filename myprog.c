#include <stdio.h> 
#include "stdnepbool.h"

bool СheckInArea(int iPoint, int jPoint) {
    return ((iPoint + jPoint + 10 <= 0) && (iPoint + jPoint + 20 >= 0)); 
   
}


int Max1(int num1, int num2) {
    return num1 >= num2 ? num1 : num2;
}

int Min(int num1, int num2) {
    return num1 >= num2 ? num2 : num1;
}


int Abs(int a) {
    return a > 0 ? a : -a;
}

int iIncrease(int i, int j, int k, int l) {
    return (i * j / (Abs(l) + 1) + j * l / (Abs(i) + 1) + i * l / (Abs(j) + 1)) % 30;
}


int jIncrease(int j, int i, int k, int l) {
    return (i * Max1(j, l) % 20 + j * Min(i, l) % 30 - k);
}

int lIncrease(int l, int i, int j) {
    return Max1(Max1(i * j, i * l), j * l) % 30 + 20;
}



int Lab9(int i, int j, int l) {    
        int p = 0;
        for (int k = 0; k <= 50; k++) {
            p = k;
            if(СheckInArea(i, j)) {
                printf("i = %d; j = %d; l = %d\nk = %d;\n", i, j, l, k);
                printf("Complete\n");
                return 1;                
            }
            
            printf("i = %d j = %d l = %d\n", i, j, l);

            i = iIncrease(i, j, k, l);
            j = jIncrease(j, i, k, l);
            l = lIncrease(l, i, j);
             
        }

        printf("i = %d; j = %d; l = %d\nk = %d;\n", i, j, l, p);
        printf("NO\n");
        return 0;
}


int main() {   
    int i = 12;
    int j = 4;
    int l = 3;
    
    Lab9(i, j, l);
    return 0;
}
