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
    int i, k = 0, flag = 0, eof_flag = 0;
    char c;
    unsigned int ans_set = 0;
    while (c = getchar()) {
        if (c == '\n' || c == ' ') {
            if (k == 1) {
                flag = 1;
            } else {
                k = 0;
        }
        } else {
            ans_set = ans_set | CharToSet(c);
            ans_set = ans_set & GLASNIYE;
            if (ans_set != 0) {
                ++k;
            }
        }
        if (c != EOF) {
            continue;
        } else {
            eof_flag = 1;
            if (flag == 1) {
                printf("yes\n");
            } else {
                if (k == 1) {
                    printf("yes\n");
                } else {
                    printf("no\n");
                }   
            }
            break;  
        }
    }
if (eof_flag == 0) {
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
return 0;
}
