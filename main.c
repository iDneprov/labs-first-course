#include <stdio.h>
#include <ctype.h>

unsigned int LetterCheck(char s) {
    s = tolower(s);
    if(s <= 'z' && s >= 'a' && s != 'a' && s != 'e' && s != 'i' && s != 'u' && s != 'y' && s != 'o') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int s = 0, k = 0, result = 0;
    while (1) {
        s = getchar();
        if (s == ' ' || s == '\n' || s == EOF) {
            if (k == 1) {
                result = 1;
                break;
            }
            k = 0;
        }
            k += LetterCheck(s);
        if (s == EOF) {
            break;
        }
    }
    if (result == 1) {
        printf("Yes. There are word with one consonant letter");
    } else {
        printf("No words with one consonant letter");
    }
    putchar('\n');
}
