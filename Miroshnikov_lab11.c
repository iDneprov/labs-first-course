#include<stdio.h>
#define SIZE 5

int main() {
    int k,ans = 0;
    char a = 0;
    while (1) {
        a = getchar();
        if (a == EOF) {
            break;
        } else {
            if ((a != ' ') && (a != ',') && (a != '\v') && (a != '\n') && (a != '\t')) {
                k += 1;
            } else {
                if ((k <= SIZE) && (k != 0)) {
                    ans += 1;
                }
                k = 0; 
            }
        }
    }
    printf("%d %s", ans, "\n");
    return 0;
}