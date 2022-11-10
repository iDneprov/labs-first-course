#include <stdio.h>
#include <ctype.h>

unsigned long long int GetSet(int c) {
    c = tolower(c);
    return 1ULL << (c);
}

int GetResult(unsigned long long leftWordSet, unsigned long long rightWordSet){
    if ((leftWordSet & ~rightWordSet) || (rightWordSet & ~leftWordSet)){
        return 0;
    }
    return 1;
}

int main() {
    int c = 0, flag = 0, result = 0;
    unsigned long long leftWordSet = 0, rightWordSet = 0;
    while (1) {
        c = getchar();
        if (c == EOF) {
            break;
        }

        if (!((c == ' ') || (c == '\n'))){
            switch (flag) {
            case 0:
                flag += 1;
            case 1:
                leftWordSet = leftWordSet | GetSet(c);
                break;
            case 2:
                flag += 1;
            case 3:
                rightWordSet = rightWordSet | GetSet(c);
                break;
            default:
                break;
            }
        } else {
            flag += (flag % 2);
            if (flag == 4) {
                result += GetResult(leftWordSet, rightWordSet);
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
