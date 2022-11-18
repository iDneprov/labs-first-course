#include <stdio.h>
#include <ctype.h>

#define SIBILANTS (1ULL << ('s' - 'a') | 1ULL << ('z' - 'a'))
#define EXCEPTIONS (1ULL << ('a' - 'a') | 1ULL << ('e' - 'a') | 1ULL << ('i' - 'a') | 1ULL << ('h' - 'a') | 1ULL << ('o' - 'a') | 1ULL << ('u' - 'a'))

int CheckTub(char s) {
    return (s == '\v' || s == ' ' || s == '.' || s == ',' || s == '\n');
}

unsigned long long int CharToSet(char s) {
    s = tolower(s);
    return  (s < 'a' || s > 'z') ? 0 : 1ULL << (s - 'a');
}

int Checker(unsigned long long int set) {
    return (set == (set & (SIBILANTS | EXCEPTIONS)) && set != (set & EXCEPTIONS));
}
int FindOnlyHissing() {
    char s = getchar();
    unsigned long long int lettersSet = 0;
    while (s != EOF) {
        if (!CheckTub(s)) {
            lettersSet = lettersSet | CharToSet(s);
        } else {
            if (Checker(lettersSet)) {
                printf("Yes\n");
                return 0;
            }
            lettersSet = 0;
        }
        s = getchar(); 
    }
    if (Checker(lettersSet)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

int main(void) {
    FindOnlyHissing();
}

