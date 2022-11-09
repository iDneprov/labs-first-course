#include <stdio.h>

int main() {
    int k,num;
    int line;
    while(1) {
        scanf("%d", &num);
        line = getchar();
        if(line == EOF) {
            break;
        }
        if(num > 0) {
            k = k + 1;
        }
    }
    printf("%d\n", k);
    return 0;
}
