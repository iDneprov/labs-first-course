#include <stdio.h>

#define MINUS -1
#define NUMBER 0
#define END 1
#define ERR 3
#define EOS 10

void PrintERR() {
    putchar('E');
    putchar('R');
    putchar('R');
    putchar('O');
    putchar('R');
    putchar('\n');
}

int Pow(int base, int indicator) {
    int res = 1;
    for ( int i = 0; i < indicator; ++i) {
        res *= base;
    }
    return res;
}

void PrintAnswer(int num, char sign) {
    //printf ("%d \n", num);
    if (num == 0) {
        for (int i = 0; i < 8; ++i) {
            putchar('0');
        }
        putchar(EOS);
    } else {
        int deg = 6;
        if (sign == '+') {
            putchar('0');
            while (deg > -1) {
                //printf ("%d, %d, %d \n", num, deg, Pow(2, deg));
                if (num - Pow(2, deg) >= 0) {
                    putchar('1');
                    num -= Pow(2, deg);
                    deg -= 1;                    
                } else {
                    putchar('0');
                    deg -= 1;
                }
            }
            putchar('\n');
        } else {
            putchar('1');
            while (deg > -1) {
                if (num - Pow(2, deg) >= 0) {
                    putchar('0');
                    num -= Pow(2, deg);
                    deg -=1;
                } else {
                    putchar('1');
                    deg -= 1;
                }
            }
            putchar('\n');
        }
    }
}

int AddNumber(int num, char symb, int len) {
    if (len == 0) {
        num = symb - '0';
        return num;
    } else {
        num *= 10;
        num += (symb - '0');
        return num;
    }
}

int Mode(int mode, char symb) {
    if (mode == END)  {
        if (symb == '-') {
            return MINUS;
        } else if ((symb >= '0') && (symb <= '9')) {
            return NUMBER;
        } else {
            return ERR;
        }
    } else if ((mode == NUMBER) || (mode == MINUS)) {
        if ((symb >= '0') && (symb <= '9')) {
            return NUMBER;
        } else if ((symb == EOS) && (mode != MINUS)) {
            return END;
        } else {
            return ERR;
        }
    }
    return 0;   
}

int main() {
    char symb, sign = '+';
    int num, mode = END, number_length = 0;
    while (1) {
        symb = getchar();
        if (symb == EOF) {
            break;
        }
        mode = Mode(mode, symb);
        if (mode == MINUS) {
            sign = '-';
        } else if (mode == NUMBER) {
            num = AddNumber(num, symb, number_length);
            number_length += 1;
        } else if (mode == END){
            if (num < 128) {
                PrintAnswer(num, sign);
                num = 0;
                sign = '+';
            } else {
                mode = ERR;
            }
        } 
        if (mode == ERR) {
            while (symb != EOS) {
                symb = getchar();
            }
            PrintERR();
            num = 0;
            sign = '+';
            mode = END;
        }
    }
}  
  
