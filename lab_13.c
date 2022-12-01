#include <stdio.h>
#include <ctype.h>

unsigned int CharToSet (int c) {
    c = tolower(c);
    return (c < 'a' || c > 'z') ? 0 : 1u << (c - 'a');
}

int main(void) {
    unsigned int Fset = 0;
    unsigned int Sset = 0;
    int first = 0, f = 0, c = 0;

    while (c != EOF) {
        c = getchar();
        if (c != '\n' && c != '\t' && c !=',' && c != ';' && c != ' ' && c != EOF) {
            if (first == 0) {
                Fset |= CharToSet(c);
            } else {
                Sset |= CharToSet(c);
            }
        } else {
            if (first == 0) {
                first = 1;
            } else if (Fset != Sset) {
                printf("yes\n");
                f = 1;
                break;
            }
        }
    }

    if (!f) {
        printf("no\n");
    }

    return 0;
}