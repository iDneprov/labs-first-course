#include <stdio.h>

int main(void) {
    char c; 
    int len = 0, sum = 0, flag = 1;
    c = getchar();
    while (1) {
        if ((c != ' ') && (c != ',') && (c != '.') && (c != '\n') && (c != EOF)) {
            len++;
        } else {
            if (c != EOF){
                if (len >= 3) {
                sum++;  
            }
            len = 0;
            } else {
                if (len >= 3) {
                sum++;  
            }
                printf("%d\n", sum);
                flag = 0;
                break;
            }
            }  
        c = getchar();
        }
        if (flag){
            flag = 0;
            printf("%d\n", sum);
        }
    if (len >= 3 && flag) {
        printf("%d\n", 1);
    }
return 0;   
}
