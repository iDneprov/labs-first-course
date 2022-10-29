#include <stdio.h>

void main() {
    char current = 0;
    char buff_1 = 0;
    int flag = 0;
    
    while (1) {
        current = getchar();
        
        if (current == EOF) {
            break;
        } else {
            if (('0' <= current) && (current <= '9')) {
                if (flag == 0) {
                    flag = 1;
                    buff_1 = current;
                    current = getchar();
                    if ((('0' <= current) && (current <= '9')) == 0) {
                        flag = 0;
                        putchar(buff_1);
                        putchar(current);
                    } else {
                        putchar(current);
                    }
                } else {
                    putchar(current);
                }
            } else {
                if (flag == 0) {
                    putchar(current);
                } else {
                    flag = 0;
                    putchar(buff_1);
                    putchar(current);
                }
            }
        }
    }
}
