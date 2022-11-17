#include <stdio.h>
#include <ctype.h>

#define VOWELS (1u << ('a' - 'a') | 1u << ('o' - 'a') | 1u << ('i' - 'a') | 1u << ('e' - 'a') | 1u << ('u' - 'a') | 1u << ('y' - 'a'))

unsigned int CharToSet(char s) {
    s = tolower(s);
    if (s < 'a' || s > 'z') {
        return 0;
    } else {
        return 1u << (s - 'a');
    }
}

unsigned int CheckWord(unsigned int word) {
    char letter;
    int k = 0;
    for (letter = 'a'; letter <= 'z'; letter++) {
        if ((word & CharToSet(letter)) != 0) {
            k = k + 1;
        }
    }
    if (k == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int s = 0, result = 0, flag = 1;
    unsigned int lettersFromWord = 0;
    while (1) {
        s = getchar();
        if (s == ' ' || s == '\n' || s == EOF) {
            lettersFromWord = lettersFromWord & ~VOWELS;
            result = result + CheckWord(lettersFromWord);
            if (result != 0 && flag != 0) {
                break;
            }
             else {
                result = 0;
             }
            lettersFromWord = 0;
            flag = 1;
        } else {
            if ((CharToSet(s) & ~VOWELS & lettersFromWord) == 0) {
            lettersFromWord = (lettersFromWord | CharToSet(s)) & ~VOWELS;
            } else {
                flag = 0;
            }
        }
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
