#include <stdio.h>

int main() {
    int currentWord = 0, c;
    int k = 0;
    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') {
            break;
        }
        if (!(c > 47 && c < 58)) {
            if (currentWord != 0) printf("0%d\n", currentWord);
            currentWord = 0;
            continue;
        } 
        currentWord = currentWord * 10 + (c - '0');
    }
}
