#include <stdio.h>

const int ORDTAB = 9;
const int ORDEOS = 10;

void PrintAnswer(int kolvo) {
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

int AllowedSymbol(int symbol) {
    if (((symbol >= '0') && (symbol <= '9')) || ((symbol >= 'A') && (symbol <= 'Z')) || 
            ((symbol >= 'a') && (symbol <= 'z')) || (symbol == '_')) {
                return 1;
    }
    return 0;
}

int AllowedFirstSymbol(int symbol) {
    if (((symbol >= 'A') && (symbol <= 'Z')) || 
            ((symbol >= 'a') && (symbol <= 'z')) || (symbol == '_')) {
                return 1;
    }
    return 0;
}

int Rasdelitel(int symbol) {
    if ((symbol == ' ') || (symbol == ',') || (symbol == ORDTAB) || (symbol == ORDEOS)) {
        return 1;
    }
    return 0;
}

int main() {
    int current, kolvo;
    int  flag = -1;
    while (1) {
        current = getchar();
        if (current == EOF) {
            if (flag == 1) {
                ++kolvo;
            }
            break;
        }
        if (flag == -1) {
           if (!AllowedFirstSymbol(current)) {
                if (Rasdelitel(current)) {
                    flag = 0;
                } else {
                    flag = 2;
                }
            } else {
                flag = 1;
            }
        }
        if (flag == 0) {
            if (!AllowedFirstSymbol(current)) {
                if (Rasdelitel(current)) {
                    flag = 0;
                } else {
                    flag = 2;
                }
            } else {
                flag = 1;
            }
        }
        if (flag == 1) {
            if (!AllowedSymbol(current)) {
                if (Rasdelitel(current)) {
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
            if (!Rasdelitel(current)) {
                flag = 2;
            } else {
                flag = 0;
            }
        }
    }
    PrintAnswer(kolvo);
}
