#include <stdio.h>

void print_answer(int kolvo) {
    int kolvocopy = kolvo;  
    int razryady = 0;
    int first = 1;
    if (kolvo == 0) {
        putchar('0');
    }
    while (kolvocopy > 0) {
        ++razryady;
        kolvocopy = kolvocopy / 10; 
    }
    for (int i = 1; i < razryady; ++i) {
        first = first * 10;
    }
    while ((kolvo > 0) && (first>0)) {
        putchar(('0' + kolvo / first));
        if (first > 1) {
            if (kolvo % first < first / 10) {
                    putchar('0');
                    first = first / 10;
            }
        }
        kolvo = kolvo % first;
        first = first / 10;
    }
}

int allowed_symbol (int symbol) {
    return ((symbol >= '0') && (symbol <= '9')) || ((symbol >= 'A') && (symbol <= 'Z')) || 
            ((symbol >= 'a') && (symbol <= 'z')) || (symbol == '_');
}

int allowed_first_symbol (int symbol) {
    return ((symbol >= 'A') && (symbol <= 'Z')) || 
            ((symbol >= 'a') && (symbol <= 'z')) || (symbol == '_');

}

int rasdelitel(int symbol) {
    return (symbol == ' ') || (symbol == ',') || (symbol == '\t') || (symbol == '\n');
}

int main() {
    int current, kolvo;
    int  flag = -1;
    kolvo = 0;
    while (1) {
        current = getchar();
        if (current == EOF) {
            if (flag == 1) {
                ++kolvo;
            }
            break;
        }
        if (flag == -1) {
           if ( ! allowed_first_symbol(current)) {
                if ( rasdelitel(current) ) {
                    flag = 0;
                } else {
                    flag = 2;
                }
            } else {
                flag = 1;
            }
        }
        if (flag == 0) {
            if (! allowed_first_symbol(current)) {
                if ( rasdelitel(current) ) {
                    flag = 0;
                } else {
                    flag = 2;
                }
            } else {
                flag = 1;
            }
        }
        if (flag == 1) {
            if (! allowed_symbol(current)) {
                if (rasdelitel(current)) {
                    flag = 0;
                    ++kolvo;
                } else {
                    flag = 2;
                }
            } else {
                flag = 1;
            }
        }
        if (flag == 2) {
            if (! rasdelitel(current)) {
                flag = 2;
            } else {
                flag = 0;
            }
        }
    }
    print_answer(kolvo);
}
