#include <stdio.h>
#include <ctype.h>

#define VOWELS (1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a') | 1u << ('y' - 'a'))

unsigned int CharToSet(char c) {
    c = tolower(c);
    if (c < 'a' || c > 'z') {
        return 0;
    }
    return 1u << (c - 'a');
}

int SeparatorsCheck(char c) {
    return c == ' ' || c == ',' || c == '\v' || c == '\n' || c == '\t' || c == EOF;
}

int main() {
    char prevsym = '#';
    int iter = 0;
    int flag = 0;
    char c;
    unsigned int letter1 = 0;
    unsigned int letter2 = 0;
    unsigned int supportletter = 0;
    while (c = getchar()) {
        if (c != EOF) {
            prevsym = c;
        }
        if (!SeparatorsCheck(c)) {
            if ((iter == 0) || (iter == 1)) {
                if (iter == 0) {
                    iter += 1;
                }
                letter1 = letter1 | CharToSet(c);
            } else {
                letter2 = letter2 | CharToSet(c);
            }
        }
        if (SeparatorsCheck(c) && (iter == 0)) {
            continue;
        }
        if (SeparatorsCheck(c) && (iter != 0)) {
            iter += 1;
            if (iter >= 3) {
                supportletter = letter2;
                letter1 = letter1 & VOWELS;
                letter2 = letter2 & VOWELS;
                if ((letter1 == letter2) && (letter1 != 0)) {
                    flag = 1;
                }
                letter1 = supportletter;
                letter2 = 0;
            }
            if (c == EOF) {
                if (prevsym != '\n') {
                    printf("\n");
                }
                if (flag == 0) {
                    printf("NO\n");
                } else {
                    printf("YES\n");
                }
                break;
            }
        }
    }
    return 0;
}
