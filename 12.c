#include <stdio.h>


void PrintNewNum(char num) {
    if (num == '0')
        printf("00");

    if (num == '1')
        printf("01");

    if (num == '2')
        printf("02");

    if (num == '3')
        printf("03");

    if (num == '4')
        printf("04");

    if (num == '5')
        printf("05");

    if (num == '6')
        printf("06");

    if (num == '7')
        printf("07");

    if (num == '8')
        printf("10");

    if (num == '9')
        printf("11");
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
