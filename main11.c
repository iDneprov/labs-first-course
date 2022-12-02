#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"rus");
    char a;
    int sost = 0, n1 = 0, n0 = 0,flag = 0 ,x;
    printf("(☞ ͡ ͡° ͜ ʖ ͡ ͡°)☞\n");
    printf("Введите числа: \n");
    while (sost != 5){
        a = getchar();
        if (a != ' ' && a != ',' && a != '\n' && a != '\t') putchar(a);
        switch (sost) {
            case 0 :
                if (a == '0') sost = 1;
                if (a != ' ' && a != '\n' && a != '\t' && a != ',' && a != '0') sost = 3;
                if (a == EOF){
                    printf("Предпоследнее шестнадцатиричное число : %x\n",x);
                    printf("✺◟( ͡° ͜ʖ ͡°)◞✺\n");
                    sost = 5;
                }
                break;
            case 1 :
                if (a == 'x') sost = 2;
                if (a != ' ' && a != '\n' && a != '\t' && a != ',' && a != '0' && a != 'x') sost = 3;
                if (a == EOF) sost = 5;
                break;
            case 2 :
                if (a == 'A') n1 = n1 * 16 + 10;
                if (a == 'B') n1 = n1 * 16 + 11;
                if (a == 'C') n1 = n1 * 16 + 12;
                if (a == 'D') n1 = n1 * 16 + 13;
                if (a == 'E') n1 = n1 * 16 + 14;
                if (a == 'F') n1 = n1 * 16 + 15;
                if (a <= '9' && a >= '0') n1 = n1 * 16 +(int)(a - '0');
                if ((a < '0' || a > '9') && (a < 'A' || a > 'F') && (a != ' ' && a != ',' && a != '\t' && a != '\n')) flag = 1;
                if (a == ' ' || a == ',' || a == '\t' || a == '\n') {
                    if (flag == 1) {
                        printf(": не является 16-ти ричным числом.");
                        flag = 0;
                        n1 = 0;
                        sost = 0;
                    } else {
                        flag = 0;
                        sost = 0;
                    }
                    printf("\n");
                    x = n0;
                    n0 = n1;
                    n1 = 0;
                }
                if (a == EOF) sost = 5;
                break;
            case 3 :
                if (a == ' ' || a == ',' || a == '\t' || a == '\n') {
                    printf(": не является шестнадцатиричным числом\n");
                    sost = 0;
                }
                if (a == EOF) sost = 5;
                break;
                }
        
    }
    return 0;
}
