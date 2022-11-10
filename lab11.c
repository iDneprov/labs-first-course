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
        ascii = (counter + 3 + c - 'A') % 26 + 'A';
    } else {
        ascii = (counter + 3 + c - 'a') % 26 + 'a';
    }   
    return ascii;
}

int StateUpdate(char c, int *counter, int state) {
    if ((c >= 'a' && c <= 'z') || (c <= 'A' && c >= 'Z')) {
        (*counter)++;
        return IN_DIGIT;
    } else {
        if (c == ' ') {
            *counter = -1;
        }
        return CONTINUE;
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
