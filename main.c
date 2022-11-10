#include <stdio.h>

int main() {
    int k = 0, elem;

    while(1) {
        elem = getchar();
        if(elem == EOF) {
            break;
        }
        if( elem != ' ') {
            if(elem != '-' && elem != '0') {
                int l = 0, number = 0;
                while(l < 6) {
                    if(elem == ' ') {
                        break;
                    }
                    number = number * 10 + elem - 48;
                    l += 1;
                    elem = getchar();
                    if(elem == EOF) {
                        break;
                    }
                }
                if(number <= 32767) {
                        k += 1;
                }
            }
            while(elem != ' ') {
                elem = getchar();
                if(elem == EOF) {
                        break;
                    }
            }
        }
    }
    printf("%d\n", k);
    return 0;
}
