#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"rus");
    int numb = 0, flag = 0,flag1 = 0, dg;
    char a = '0';
    printf("Введите число: \n");
    while (a != EOF) {
        a = getchar();
        if (a == '-') flag1 = 1;
        if (a == ' ' || a == ',' || a == '\n' || a == '\t' || a == EOF) {
            if(flag == 0) {
        if(flag1 == 1){
            printf("Полученное число: -%d\n",numb);
            flag1 =0;
        } else {
            printf("Полученное число: %d\n",numb);
        }
        numb = 0;
    }
        }
        if (a >= '0' && a <= '9') {
            dg = (int)(a - '0');
            numb = numb * 10 + ((dg % 10) % 2 == 0 ? ((dg % 10 - 1) + 10) % 10 : dg % 10);   
        }
        
    }
}
