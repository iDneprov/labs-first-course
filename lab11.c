#include <stdio.h>

const int ORD0 = '0';
const int ORD9 = '9';
const int ORDA = 'A';
const int ORDZ = 'Z';
const int ORDa = 'a';
const int ORDz = 'z';
const int ORD_ = '_';
const int ORDSPACE = ' ';
const int ORDCOMMA = ',';
const int ORDTAB = 9;
const int ORDEOS = 10;

void print_aswer(int kolvo) {
    int kolvocopy = kolvo;  
    int razryady = 0;
    int first = 1;
    if (kolvo == 0) {
        putchar(ORD0);
    }
    while (kolvocopy > 0) {
        ++razryady;
        kolvocopy = kolvocopy / 10; 
    }
    for (int i = 1; i < razryady; ++i) {
        first = first * 10;
    }
    while ((kolvo > 0) && (first>0)) {
        putchar((ORD0 + kolvo / first));
        if (first > 1) {
            if (kolvo % first < first / 10) {
                    putchar(ORD0);
                    first = first / 10;
            }
        }
        kolvo = kolvo % first;
        first = first / 10;
    }
}

int allowed_symbol (int symbol) {
    if (((symbol >= ORD0) && (symbol <= ORD9)) || ((symbol >= ORDA) && (symbol <= ORDZ)) || 
            ((symbol >= ORDa) && (symbol <= ORDz)) || (symbol == ORD_)) {
                return 1;
    }
    return 0;
}

int allowed_first_symbol (int symbol) {
    if (((symbol >= ORDA) && (symbol <= ORDZ)) || 
            ((symbol >= ORDa) && (symbol <= ORDz)) || (symbol == ORD_)) {
                return 1;
    }
    return 0;
}

int rasdelitel(int symbol) {
    if ((symbol == ORDSPACE) || (symbol == ORDCOMMA) || (symbol == ORDTAB) || (symbol == ORDEOS)) {
        return 1;
    }
    return 0;
}

void main() {
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
        if (flag == 0){
            if (! allowed_first_symbol(current)) {
                if ( rasdelitel(current) ) {
                    flag = 0;
                } else{
                    flag = 2;
                }
            } else {
                flag = 1;
            }
        }
        if (flag == 1){
            if ( ! allowed_symbol(current) ) {
                if ( rasdelitel(current) ) {
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
            if ( ! rasdelitel(current) ) {
                flag = 2;
            } else {
                flag = 0;
            }
        }
    }
    print_answer(kolvo);
}