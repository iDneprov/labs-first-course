#include <stdio.h>

#define UP 1
#define DOWN -1
#define MXN 7

int main() {
    int n, current_rosition, flag;
    int m[MXN * MXN];
    scanf("%i", &n);
    for (int i = 0; i < (n * n); ++i) {
        scanf("%d", &m[i]);
    }
    flag = UP;
    current_rosition = n * n - 1;
    printf("\n%d ", m[current_rosition]);
    for (int i = 0; i < (n * n - 1); ++i) {
        if (flag == UP) {
            if (current_rosition / n == 0) {
                current_rosition -= 1;
                flag = DOWN; 
            } else if (current_rosition % n == (n - 1)) {
                current_rosition -= n;
                flag = DOWN; 
            } else {
                current_rosition += 1;
                current_rosition -= n;

            }
        } else {
            if (current_rosition % n == 0) {
                current_rosition -= n;
                flag = UP;
            } else if (current_rosition / n == (n - 1)) {
                current_rosition -= 1;
                flag = UP;
            } else {
                current_rosition += n;
                current_rosition -= 1;
            }
        }   
        printf("%d ", m[current_rosition]);
    }
}


