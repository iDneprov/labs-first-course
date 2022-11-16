#include <stdio.h>
#include <ctype.h>

#define VOWELS (1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a'))

unsigned int CharToSet(char c) {
    c = tolower(c);
    if (c < 'a' || c > 'z') {
        return 0;
    }
    return 1u << (c - 'a');
}

int SeparatorSymbols(char symbol) {
    return symbol == '\n' || symbol == '\t' || symbol == ' ';
}

int main (void) {
    int c;
    unsigned int lettersFromOneWordSet = 0;
    unsigned int lettersFromAllWordSet = 0;
    int isFirstWord = 1;
    int isSpace = 1;
    while ((c = getchar()) != EOF) {
        if (SeparatorSymbols(c)) {
            if (isSpace) {
                continue;
            }
            if (!isFirstWord) {
                lettersFromAllWordSet = lettersFromAllWordSet & lettersFromOneWordSet;
            } else {
                lettersFromAllWordSet = lettersFromOneWordSet;
                isFirstWord = 0;
            }
            lettersFromOneWordSet = 0;
            isSpace = 1;
            continue;
        } else {
            lettersFromOneWordSet = lettersFromOneWordSet | CharToSet(c);
            isSpace = 0;
        }
    }
    if (!isSpace) {
        lettersFromAllWordSet = lettersFromAllWordSet & lettersFromOneWordSet;
    }
    lettersFromAllWordSet = lettersFromAllWordSet & (~VOWELS);
    if (lettersFromAllWordSet != 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
