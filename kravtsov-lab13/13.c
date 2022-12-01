#include <stdio.h>
#include <ctype.h>
#define VOWELS (1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a'))

unsigned int CharToSet(char c) {
    c = tolower(c);
    if (c < 'a' || c > 'z') {
        return 0;
    } else {
        return 1u << (c - 'a');
    }
}

int CheckWord(unsigned int letters) {
    char alpha;
    int consonantsCount = 0;
    for (alpha = 'a'; alpha <= 'z'; ++alpha) {
        if ((letters & CharToSet(alpha) & ~VOWELS) != 0) {
            ++consonantsCount;
            if (consonantsCount > 1) {
                return 0;
            }
        }
    }
    if (consonantsCount == 1) {
        return 1;
    }
    return 0;
}

int main() {
    int s;
    unsigned int letters = 0;
    
    while ((s = getchar()) != EOF) {
        if (s >= 'a' && s <= 'z') {
            letters = letters | CharToSet(s);
        } else {
            if (CheckWord(letters)) {
                printf("Est slovo, soderzashee odny soglacnyu\n");
                return 0;
            }
            letters = 0;
        }
    }

    if (CheckWord(letters)) {
        printf("Est slovo, soderzashee odny soglacnyu\n");
        return 0;
    }
    
    printf("Nichego net");
    return 0;
}
