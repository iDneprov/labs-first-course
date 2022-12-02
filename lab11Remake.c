#include <stdio.h>
#include <locale.h>

int main(){ 
    setlocale(LC_ALL,"Rus");
    char a1 = '0';
    char a0 = 'g';
    int flag = 0;
    int n1 = 0, n0, x, flag1 = 0, flag2 = 1, flag3 = 0;
    printf("Введите любые числа\n");
    while (a1 != EOF) {
        a1 = getchar();
        if ((a0 <= '9' && a0 >= '0') || (a0 >= 'A' && a0 <= 'F')) flag3 = 1;
        if ( (a1 < '0' || a1 > '9') && (a1 < 'A' || a1 > 'F') && (a1 != ' ' && a1 != ',' && a1 != '\n' && a1 != '\t' && a1 != '-' && a1 != EOF) ) flag = 1;
        if (a1 == '-') {
            if ((a0 <= '9' && a0 >= '0') || (a0 >= 'A' && a0 <= 'F') ){
                flag = 1;
            } else {
                flag2 = -1;
            }
        }
        if (a1 == EOF || a0 == EOF || a1 == ' ' || a1 == ',' || a1 == '\n' || a1 == '\t') {
            if (flag == 0) {
                x = n0;
                if (flag3 == 1) {
                    n0 = n1 * flag2;
                    flag3 = 0;
                }
                n1 = 0;
                flag1 += 1;
                flag2 = 1;
            } else {
                flag = 0;
            }
        }
        if (a1 == 'A') n1 = n1 * 16 + 10;
        if (a1 == 'B') n1 = n1 * 16 + 11;
        if (a1 == 'C') n1 = n1 * 16 + 12;
        if (a1 == 'D') n1 = n1 * 16 + 13;
        if (a1 == 'E') n1 = n1 * 16 + 14;
        if (a1 == 'F') n1 = n1 * 16 + 15;
        if (a1 <= '9' && a1 >= '0') n1 = n1 * 16 + (int)(a1 - '0');
        if (a1 == EOF && flag1 > 1) {
            if(x >= 0) {
                printf("Предпоследнее 16 - ичное число: %x\n",x);
            } else {
                printf("Предпоследнее 16 - ичное число: -%x\n",(0-x));
            }
        }
        if (a1 == EOF && flag1 < 2) {
        printf("Одно число(Отсутствие чисел).\n");
            } 
        a0 = a1;
    }
}

