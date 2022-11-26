#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void PrintNewNum(char num) {
    if (num == '0')
        printf("0000");

    if (num == '1')
        printf("0001");

    if (num == '2')
        printf("0010");

    if (num == '3')
        printf("0011");

    if (num == '4')
        printf("0100");

    if (num == '5')
        printf("0101");

    if (num == '6')
        printf("0110");

    if (num == '7')
        printf("0111");

    if (num == '8')
        printf("1000");

    if (num == '9')
        printf("1001");
}

void Lab12(char num) {
    while (num != EOF) {     
        if (num == '\n' || num == ' ') {
            printf("\n");
            num = getchar();
        }

        if (num == '-') {
            printf("-");
            num = getchar();
        }
        PrintNewNum(num);


        num = getchar();
    }   
}

int main(void) {    
    char num = 'a';
    
    Lab12(num);
    
    return 0;
}
