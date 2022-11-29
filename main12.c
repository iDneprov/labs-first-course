#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"rus");
    long n;
    printf("Введите числа :\n");
    while(scanf("%ld",&n) != EOF) {
        int flag = 0;
        if (n == 0) {
            flag = 1;
            printf("1\n");
        }
        long n1 = 0;
        while (n != 0) {
            n1 = n1 * 10 + (( n % 10 ) % 2 == 0 ?  n % 10 + 1 : n % 10);
            n /= 10;
        }
        while (n1 > 0) {
            printf("%ld", n1%10);
            n1/=10;
        }
        if (flag != 1) printf("\n");  
    }
}