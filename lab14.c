#include <stdio.h>

#define UP 1
#define DOWN -1
#define MXN 7

int main() {
    int n, currentPosition, flag;
    int m[MXN * MXN];
    scanf("%i", &n);
    for (int i = 0; i < (n * n); ++i) {
        scanf("%d", &m[i]);
    }
    flag = UP;
    currentPosition = n * n - 1;
    printf("\n%d ", m[currentPosition]);
    for (int i = 0; i < (n * n - 1); ++i) {
        if (flag == UP) {
            if (currentPosition / n == 0) {
                currentPosition -= 1;
                flag = DOWN; 
            } else if (currentPosition % n == (n - 1)) {
                currentPosition -= n;
                flag = DOWN; 
            } else {
                currentPosition += 1;
                currentPosition -= n;

            }
        } else {
            if (currentPosition % n == 0) {
                currentPosition -= n;
                flag = UP;
            } else if (currentPosition / n == (n - 1)) {
                currentPosition -= 1;
                flag = UP;
            } else {
                currentPosition += n;
                currentPosition -= 1;
            }
        }   
        printf("%d ", m[currentPosition]);
    }
}


