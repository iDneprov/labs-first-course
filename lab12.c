#include <stdio.h>

int main(void) {
    int number, res = 0, rp, p = 0, i = 0;
    int tarr[100] = {0};
    scanf("%d", &number);
    p = getchar();
    while (p != '\n') {
      if (p > '9' || p < '0') {
        return 0;
      }
      rp = p-48;
      number = number*10+rp+(rp%2 == 0);
      p = getchar();
    }
    while(number != 0)
    {
        if (number%2 == 0) number++;
        tarr[i] = (number)%10;
        ++i;
        number /= 10;
    }
    char a[10] = {'0','1','2','3','4','5','6','7','8','9'};
    i--;
    for(; i>-1; --i){
        putchar(a[tarr[i]]);
    }
    putchar('\n');
    return 0;
}
