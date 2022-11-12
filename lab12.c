#include <stdio.h>

#define SIGN 0
#define NUM 1
#define CONTINUE 2
#define END 3

char Abs(char n) {
    return n = (n > 0) ? n : -n;
}

void RecursionOutput(char num) {
    if (Abs(num) > 0) {
        RecursionOutput(Abs(num) / 2);
        putchar('0' + Abs(num) % 2);
    }
}

char Pow(char num, char power) {
    char res = 1;
    for (int i = 1; i <= power; i++) {
        res *= num;
    }
    return res;
}

char ClosetPowerOfTwo(char num){
    char n = Abs(num);
    unsigned char base = 1;
    char power = 0;
    while (base < n) {
        base = base * 2;
        power += 1;
    }
    return power;
}


int AdditionalCode (char num) {
    return Pow(2, ClosetPowerOfTwo(num)) - num; 
}

int StatusUpdate(char ch, char *sign){
    if (ch >= '0' && ch <= '9') {
        return NUM;
    } else if (ch == '-') {
        *sign = '-';
        return SIGN;
    }
    return CONTINUE;
}

char ClayNum(char ch, int k, char num, char sign){
    if (sign == '+') {
        if (k == 0) {
            num += ch - '0';
        } else if (k == 1) {
            num *= 10;
            num += ch - '0';
        } else if (k == 2) {
            num *= 10;
            num += ch - '0';
        }      
    } else {
        if (k == 0) {
            num -= ch - '0';
        } else if (k == 1) {
            num *= 10;
            num -= ch - '0';
        } else if (k == 2) {
            num *= 10;
            num -= ch - '0';
        }
    }
    return num;
}

void DobeyEgo(char num, char sign) {
    for (int i = 0; i < 6 - ClosetPowerOfTwo(num); ++i){
        if (sign == '+') {
            putchar('1');
        } else {
            putchar('0');
        }
    }
}

int Exeptions(char num){
    if (num == -128) {
        putchar('1');
        for (int i = 0; i < 7; i++){
            putchar('0');
        }
    } else if (num == 0) {
        for (int i = 0; i < 8; i++){
            putchar('0');
        }
    } else {
        return 1;
    }
    return 0; 
}

int main() {
    char ch, sign = '+', num = 0;
    int state = CONTINUE;
    int k = 0;
    while (1) {
        ch = getchar();
        state = StatusUpdate(ch, &sign);
        if (state == NUM) {
            num = ClayNum(ch, k, num, sign);
            ++k;
        } else if (state == CONTINUE && k > 0) {
            if (num == -128) {
                Exeptions(num);
            } else if (num == 0) {
                Exeptions(num);
            } else {
                if (sign == '-') {
                    putchar('1');
                    num = AdditionalCode(Abs(num));
                } else {
                    putchar('0');
                }
                DobeyEgo(Abs(num), sign);
                RecursionOutput(num);
            }
        putchar('\n');
        k = 0;
        sign = '+';
        num = 0;
        }
        if (ch == EOF){
            break;
        }
    }
}    

