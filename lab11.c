#include <stdio.h>
 
int main() {
    int act = 0, c;
 
    int k = 0;
    int a[100] = {0};
    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') {
            break;
        }
        if (!(c > 47 && c < 58)) {
            if (act != 0) a[k++] = act;
            act = 0;
            continue;
        }
 
        act = act * 10 + (c - '0');
    }
 
    for (int i = 0; i < 100; i++) {
        int elem = a[i];
        if (elem != 0) {
            printf("0%d\n", elem);
        } else { break; }
    }
 
}