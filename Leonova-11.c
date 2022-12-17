#include <stdio.h>
#include <ctype.h>

#define FROMMITOKM 1.609

int main(void) {
    char character, a;
    int counter, km, mili;
    do {
        mili = 0;
        counter = 0;
        character = getchar();
        if (character == EOF) {
            break;
        }
        if (isdigit(character)) {
            counter = counter + 1;
            mili = mili * 10 + character;
        }
        else {
            counter = 0;
            km = FROMMITOKM * mili;
            printf("%d mi = %d km\n", mili, km);
            mili = 0;
            continue;
        }
        
    }
    while (character != EOF);
    return 0;
}