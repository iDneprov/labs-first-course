#include <stdio.h>
#include <ctype.h>

#define CONSONANTS 35797578ULL
#define VOWELS 17842449ULL

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
        if (c != ' ' && c != '\n') {
            lettersSet = lettersSet | CharToSet(c);
        } else {
            newLettersSet = lettersSet & (CONSONANTS | VOWELS);
            if (lettersSet == newLettersSet) {
                break;
              }
            lettersSet = 0;
        }

        c = getchar();
    }

    newLettersSet = lettersSet & (CONSONANTS | VOWELS);
    if (lettersSet == newLettersSet) {
        printf("Yes!");
    } else {
        printf("No!");
    }
    return 0;
}
