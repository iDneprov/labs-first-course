#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

/*
int input_len(int len) {
    char len_before[] = {};

    printf("Введи длинну строки, мраз: ");
    
    gets(len_before);
    len = atoi(len_before); 

    printf("\n");

    return len;
}
*/

void FillingStrok(char massiv[], int n) {
    bool res = true;

    assert(massiv != 0);

    printf("Введи строку, мраз: ");
        
    res = fgets(massiv, n + 1, stdin);
        
    if (res != true) {
        printf("Криво ввел\n");
        
        assert(res == true);
    }
    printf("\n");
}


void Lab11(char str[]) {     
    int sliceBigin = 0;
    int sliceEnd = 0;
    int tmpFirstIndex = 0;
    int tmpLastIndex = 0;
    
    int numberNum = 0;

    int i = 0;
    while (i < strlen(str)) {
        if (isdigit(str[i])) {
            ++numberNum;
            sliceBigin = i;
            
            while (i < strlen(str)) {
                if (isdigit(str[i]))
                    ++i;
                else
                    break;
            }   

            if (numberNum == 1) {
                tmpFirstIndex = sliceBigin;
                tmpLastIndex = i;
            }   
            sliceEnd = i;
        }        
        ++i;
    }

    int j = tmpFirstIndex;
    for (; j < tmpLastIndex; ++j) {
        putchar(str[j]);
    }
    printf("\n");

    j = sliceBigin;
    for (; j < sliceEnd; ++j) {
        putchar(str[j]);
    }
    printf("\n");
}


int main(void) {
    int n = 5;
    char str[n];
    FillingStrok(str, n);
    
    Lab11(str);

    return 0;
}
