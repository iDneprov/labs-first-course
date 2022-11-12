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

void Filling_strok(char massiv[], int n) {
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
    int slice_bigin = 0;
    int slice_end = 0;
    int tmp_first_index = 0;
    int tmp_last_index = 0;
    
    int number_num = 0;

    int i = 0;
    while (i < strlen(str)) {
        if (isdigit(str[i])) {
            ++number_num;
            slice_bigin = i;
            
            while (i < strlen(str)) {
                if (isdigit(str[i]))
                    ++i;
                else
                    break;
            }   

            if (number_num == 1) {
                tmp_first_index = slice_bigin;
                tmp_last_index = i;
            }   
            slice_end = i;
        }        
        ++i;
    }

    int j = tmp_first_index;
    for (; j < tmp_last_index; ++j) {
        putchar(str[j]);
    }
    printf("\n");

    j = slice_bigin;
    for (; j < slice_end; ++j) {
        putchar(str[j]);
    }
    printf("\n");
}


int main(void) {
    int n = 5;
    char str[n];
    Filling_strok(str, n);
    
    Lab11(str);

    return 0;
}
