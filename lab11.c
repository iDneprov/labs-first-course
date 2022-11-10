#include <stdio.h>

int main(void) {
    char c; 
    int len = 0, sum = 0;
    c = getchar();
    while (c != EOF) {
        if ((c != ' ') && (c != ',') && (c != '.') && (c != '\n')) {
            len++;
        } else {
            if (len >= 3) {
                sum++;  
            }
            len = 0;
            }  
        c = getchar();
        }
        printf("%d\n", sum);
    if (len >= 3) {
        printf("%d\n", 1);
    }
return 0;   
}
