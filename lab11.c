//* Филиппов Владимир М80-110Б-22 *//
//* Кодирование по Цезарю с переменным ключом +3 *//
//* Тесты: don li Volga li te4et kotomku na ple40 *//
//* qwertyuiopasdfghjklzxcvbnm *// 
//* Viva Victoria *//

#include <stdio.h>

#define IN_DIGIT 1
#define CONTINUE 2
#define SPACE 3

int AsciiCode(char c, int counter) {
    int ascii = 0;
    if (c >= 'A' && c <= 'Z') {
        ascii = (counter + 3 + (int)(c) - 65) % 26 + 65;
    } else {
        ascii = (counter + 3 + (int)(c) - 97) % 26 + 97;
    }   
    return ascii;
}

int StateUpdate(char c, int *counter, int state) {
    if (c == ' ') {
        *counter = -1;
        return SPACE;
    } else if (((int)c >= 1 && (int)c <= 64) || ((int)c >= 91 && (int)c <= 96) || ((int)c >= 123)) {
        return CONTINUE;
    } else {
        (*counter)++;
        return IN_DIGIT;
    }
}

int main() {
    char c;
    int counter = -1;
    int state = 0;
    while ((c = getchar()) != EOF) {

        state = StateUpdate(c, &counter, state);

        if (state == IN_DIGIT) {
            putchar(AsciiCode(c, counter));
        } else {
            putchar(c);
        }

    }
    return 0;
}
