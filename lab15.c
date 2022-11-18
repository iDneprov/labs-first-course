//20 вариант
#include <stdio.h>

#define MAX_N 8

int main() {
    int mass[MAX_N][MAX_N];
    short int columnCheck;
    int i, j, l, n, min, sum;

    scanf("%i", &n);
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", &mass[i][j]); 

    min = mass[0][0];
    for (i = 0; i < n; ++i)    
        for (j = 0; j < n; ++j) 
            if (min > mass[i][j])
                min = mass[i][j];

    for (i = 0; i < n; ++i) { 
        columnCheck = 0;
        sum = 0;
        for (j = 0; j < n; ++j) 
            if (min == mass[j][i]) {
                if (!columnCheck) {
                    for (l = 0; l < n; ++l)
                        sum += mass[l][i];
                    mass[j][i] = sum;    
                    columnCheck = 1;
                } else 
                    mass[j][i] = sum;     
            }   
    } 
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j)
            printf("%d ", mass[i][j]);  
        putchar('\n');
    }        
    return 0;
}
