#include <stdio.h>

/*
10 - символ переноса строки
32 - пробел


*/



void main(){
    char a = 0;
    while (1){
        a = getchar();

        if (a == EOF) {
            break;
        } else if (a == 10) {
            putchar(32);
            putchar(a);
            putchar(32);
        } else {
            putchar(a);
        }
    }
}   