#include <stdio.h>

int main(void) {
    int number = getchar();
    int count_zero = 0;
    int first_zero = 1;

    while (number != EOF) {
        if ((char) number == '0' && first_zero) {
            ++count_zero;
            number = getchar();

        } else if ((char) number == '\n') {
            number = getchar();

        } else if ((number <= '9' && number >= '0')
                || (number <= 'z' && number >= 'a')
                || (number <= 'Z' && number >= 'A')) {
            putchar(number);
            number = getchar();
            first_zero = 0;

        } else {
            count_zero = 0;
            putchar('e');
            putchar('r');
            putchar('r');
            putchar('o');
            putchar('r');
            break;
        }
    }

    while (count_zero > 0) {
        putchar('0');
        --count_zero;
    }
}
