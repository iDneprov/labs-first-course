#include <stdio.h>
#include <ctype.h>

unsigned long long int GetSet(int c) {
    return 1ULL << (c);
}

int main() {
    int c = 0, flag = 0, result = 0;
    unsigned long long leftWordSet = 0, rightWordSet = 0;
    while (1) {
        c = getchar();
        if (c == EOF) {
            break; 
        }

        if (!((c == ' ') || (c == '\n'))) {
            c = tolower(c);
            switch (flag) {
            case 0:
                flag += 1;
            case 1:
                if (('a' <= c) && (c <= 'z')) {
                    leftWordSet = leftWordSet | GetSet(c);
                }
                break;
            case 2:
                flag += 1;
            case 3:
                if (('a' <= c) && (c <= 'z')) {
                    rightWordSet = rightWordSet | GetSet(c);
                }
                break;
            default:
                break;
            }
        } else {
            flag += (flag % 2);
            if (flag == 4) {
                result += (leftWordSet == rightWordSet);
                leftWordSet = rightWordSet;
                rightWordSet = 0;
                flag = 2;
            }
        }
    }
    
    if (result) {
        printf("YES!!");
    } else {
        printf("NO T_T");
    }
    putchar('\n');
}
