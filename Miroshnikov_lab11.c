#include <stdio.h>
#define SIZE 5

int main() {
    int k = 0;
    int ans = 0;
    char a = 0;
    char fl = a;
    while (1) {
        a = getchar();
        if (a == EOF) {
            if ((k <= SIZE) && (k != 0)) {
                ans += 1;
                printf("\n");
                break;
            } else {
                if (fl == '\n') {
                    break;
                } else {
                    printf("\n");
                    break;
                }
            }
        } else {
            if ((a != ' ') && (a != ',') && (a != '\v') && (a != '\n') && (a != '\t')) {
                k += 1;
            } else {
                fl = a;
                if ((k <= SIZE) && (k != 0)) {
                    ans += 1;
                }
                k = 0; 
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
