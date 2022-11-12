#include <stdio.h>

#define ZERO '0'
#define DEFOLD 0

int PowInt(int number, int degree) {
    int result = 1;
    while (degree > 0) {
        result *= number;
        --degree;
    }
    return result;
}

int SeparatorSymbols(char symbol) {
    return symbol == '\n' || symbol == '\t' || symbol == ' ';
}

int main(void) {
    int number = DEFOLD;
    int write = 1;
    int countZero = DEFOLD;
    int symbol = getchar();
    int isMinus = 0;
    while (symbol != -1 && write) {
        if (write) {
            if ((char) symbol == ZERO && number == DEFOLD) {
                ++countZero;
                symbol = getchar();
            } else if (SeparatorSymbols(symbol)) {
                symbol = getchar();
                while (SeparatorSymbols(symbol)) {
                    symbol = getchar();
                }
                write = 0;
            } else if (symbol == '-') {
                isMinus = 1;
                symbol = getchar();
            } else {
                number = number * 10 + (symbol - ZERO);
                symbol = getchar();
            }
        } 
        if (symbol == -1) {
            write = 0;
        }
        // printf(" %d %c", symbol, symbol);
        if (!write) {
            if (isMinus) {
                putchar('-');
            }
            int numberInTwoSystem = DEFOLD, countRang = DEFOLD;
            while (number > DEFOLD) {
                numberInTwoSystem += ((number % 2) * PowInt(10, countRang));
                ++countRang;
                number /= 2;
            }
            int nowRangNumber, middle = countRang / 2, isZero = 1;
            while (numberInTwoSystem > DEFOLD || countRang > DEFOLD) {
                isZero = 0;
                nowRangNumber = PowInt(10, countRang - 1);
                char res = ZERO + numberInTwoSystem / nowRangNumber;
                putchar(res);
                numberInTwoSystem %= nowRangNumber;
                --countRang;
                if (countRang == middle) {
                    while (countZero > DEFOLD) {
                        putchar(ZERO);
                        --countZero;
                    }
                }
            }
            if (isZero) {
                while (countZero > DEFOLD) {
                    putchar(ZERO);
                    --countZero;
                }
            }
            putchar('\n');
            write = 1;
        }
    }
}
