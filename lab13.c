#include <stdio.h>
#include <ctype.h>

const unsigned int GLASNIYE = (1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') |   1u << ('o' - 'a') | 1u << ('u' - 'a') | 1u << ('y' - 'a'));


unsigned int CharToSet(char c) {
    c = tolower(c);
    if (c < 'a' || c > 'z') {
        return 0;
    }
    return 1u << (c - 'a'); 
}

int main(void) {
    int k = 0, flag = 0, eofFlag = 0;
    char c;
    unsigned int ansSet = 0;
    while (1) {
        c = getchar();
        if (((c == '\n') || (c == ' ')) && (c != EOF)) {
            if (k == 1) {
                flag = 1;
            } else {
                k = 0;
        }
        } else {
            ansSet = ansSet | CharToSet(c);
            ansSet = ansSet & GLASNIYE;
            if (ansSet != 0) {
                ansSet = 0;
                ++k;
            }
        }
        if (c == EOF) {
            eofFlag = 1;
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
if (eofFlag == 0) {
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
