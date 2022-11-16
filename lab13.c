#include <stdio.h>
#include <ctype.h>

#define GLASNIYE (1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') |   1u << ('o' - 'a') | 1u << ('u' - 'a') | 1u << ('y' - 'a'));

unsigned int CharToSet(char c) {
    c = tolower(c);
    if (c < 'a' || c > 'z') {
        return 0;
    }
    return 1u << (c - 'a'); 
}

int main(void) {
    int i, k = 0, flag = 0;
    char c;
    unsigned int ans_set = 0;
    c = getchar();
    while (c != EOF) {
        if (c == '\n' || c == ' ') {
            if (k == 1) {
                flag = 1;
            } else {
                k = 0;
        }
        } else {
            ans_set = ans_set | CharToSet(c);
            ans_set = ans_set & GLASNIYE;
            if (ans_set != 0){
                ++k;
            }
        }
        c = getchar();
    }
    if (flag == 1) {
        printf("yes\n");
    } else {
        if (k == 1) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}