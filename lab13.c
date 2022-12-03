#include <stdio.h>
#define CONS (1ULL << ('p' - 'a') | 1ULL << ('t' - 'a') | 1ULL << ('k' - 'a') | 1ULL << ('f' - 'a') | 1ULL << ('s' - 'a'))

int Check(char s) {
    return ((s != EOF) && (s != '\n') && (s != '.') && (s != ',') && (s != ' '));
}

unsigned long long int CharToSet(char c) {
    return  (c < 'a' || c > 'z') ? 0 : 1ULL << (c - 'a');
}

int main(void) {
    int flag = 0;
    char s;
    unsigned long long int letters = 0;
    s = getchar();
    while (1) {
        if (Check(s)) {
            letters = letters | CharToSet(s);
            letters = letters & CONS;
        }
        if (Check(s) == 0) {
            if (!letters) {
                flag = 1;
            }  
            if (letters != 0) {
                flag = 0;
            }
            letters = 0;
        }
        if (s == EOF || s == '\n') {
            if (flag) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }
        s = getchar();
    }
}
