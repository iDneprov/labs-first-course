#include <stdio.h>
#include <ctype.h>
#define VOWELS (1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a'))
#define TEST_FILE_NAME "test.txt"

unsigned int CharToSet(char c) {
    c = tolower(c);
    if (c < 'a' || c > 'z') {
        return 0;
    } else {
        return 1u << (c - 'a');
    }
}

void CheckWord(unsigned int letters, int *vowelFlag, int *consonantFlag) {
    char alpha;
    int vowelsCount = 0;
    int consonantsCount = 0;
    for (alpha = 'a'; alpha <= 'z'; ++alpha) {
        if ((letters & CharToSet(alpha)) != 0) {
            if ((letters & CharToSet(alpha) & VOWELS) != 0) {
                ++vowelsCount;
            } else {
                ++consonantsCount;
            }
        }
    }
    if (vowelsCount == 1) {
        *vowelFlag = 1;
    }
    if (consonantsCount == 1) {
        *consonantFlag = 1;
    }
}

int main() {
    int s;
    unsigned int letters = 0;
    int vowelFlag = 0;
    int consonantFlag = 0;
    char name[] = TEST_FILE_NAME;
    FILE *f;
    
    if ((f = fopen(name, "r")) == NULL) {
        printf("Не удалось открыть файл");
        return 0;
    }

    while ((s = fgetc(f)) != EOF) {
        if (s >= 'a' && s <= 'z') {
            letters = letters | CharToSet(s);
        } else {
            CheckWord(letters, &vowelFlag, &consonantFlag);
            letters = 0;
        }
    }

    CheckWord(letters, &vowelFlag, &consonantFlag);

    if (vowelFlag) {
        printf("Est slovo, soderzashyu odny glacnyu\n");
    }
    if (consonantFlag) {
        printf("Est slovo, soderzashyu odny soglacnyu\n");
    }
    if (!vowelFlag && !consonantFlag) {
        printf("Nichego net\n");
    }
    
    fclose(f);
    return 0;
}
