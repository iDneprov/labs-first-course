#include <stdio.h>
#include <ctype.h>

#define VOWELS 35797066ULL

unsigned long long int CharToSet(int c) {
    if (c < 'a' || c > 'z') {
        return 0;
    } else {
        return 1ULL << (c - 'a');
    }
}

int main() {
    int c;
    unsigned long long lettersSet = 0, newLettersSet = 0;
    c = getchar();
    while (c != EOF) {
        if (c != ' ' || c != '\n') {
            lettersSet = lettersSet | CharToSet(c);
            c = getchar();
        } else {
            newLettersSet = lettersSet & VOWELS;
            if (lettersSet == newLettersSet) {
                printf("Yes!");
                break;
            }
        }

        c = getchar();
    }

    newLettersSet = lettersSet & VOWELS;
    if (lettersSet == newLettersSet) {
        printf("Yes!");
    } else {
        printf("No!");
    }
    return 0;
}
