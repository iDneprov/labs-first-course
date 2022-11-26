#include <stdio.h>

int main() {    
    int n = 0;
    char c = 0;
    int vowel = 0b11111;
    int word = 0;
    printf("Input: ");
    do {
        c = getchar();
        if (c == 'a' || c == 'A') {
            word |= 0b00001;
        } else if (c == 'e' || c == 'E') {
            word |= 0b00010;
        } else if (c == 'i' || c == 'I') {
            word |= 0b00100;
        } else if (c == 'o' || c == 'O') {
            word |= 0b01000;
        } else if (c == 'u' || c == 'U') {
            word |= 0b10000;
        } else {
            if (word != 0)
                vowel &= word;
            word = 0;
        }
    } while (c != '\n');
    printf("Output: ");
    if (vowel & 0b00001) {
        printf("a ");
    }
    if (vowel & 0b00010) {
        printf("e ");
    }
    if (vowel & 0b00100) {
        printf("i ");
    }
    if (vowel & 0b01000) {
        printf("o ");
    }
    if (vowel & 0b10000) {
        printf("u ");
    }
    return 0;
}
