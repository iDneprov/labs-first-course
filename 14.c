#include <stdio.h> //lab 12 variant 26

char CheckTub(char s) {
    return (s < '!' || s == ' ' || s == '.' || s == ',' || s == '-');
}

char FindTubs(char sLast) {
    char s = getchar();
    putchar(sLast);
    while (s != EOF) {
        if ((s >= '0' && s <= '9') && CheckTub(sLast)) {
            return s;
        }
        sLast = s;
        putchar(sLast);
        s = getchar();
    }
    return s;
}

int SumNums(long long int num) {
    long long int resultNum = 0, i = 1;
    int sum = 0, toFirst = 0, flag = 0;
    if (num < 10) {
        putchar(num + '0');
        return 0;
    }
    while (num > 9) {
        toFirst = num - (num / 100) * 100;
        num /= 10;
        sum = toFirst / 10 + (toFirst - (toFirst / 10) * 10);
        if (flag) {
            flag = 0;
            resultNum += (sum - toFirst / 10) * i;
            i *= 10;
        } else {
            resultNum = (sum - toFirst / 10) * i + resultNum;
        }
        i *= 10;
        if (sum < 10) {
            flag = 1;
            resultNum = sum * i * 10 + resultNum;
        }
    }
    if (flag) {
        putchar(resultNum / (i * 10) + '0');
        resultNum -= ((resultNum / i) * i);
    }
    putchar(num + '0');
    while (i > 1) {
        i /= 10;
        toFirst = resultNum / i;
        resultNum -= toFirst * i;
        putchar(toFirst + '0');
    }
    return 0;
}

int SumNumsInNumers() {
    char s = ' ';
    long long int num = 0;
    while (s != EOF) {
        s = FindTubs(s);
        num = 0;
        while (!CheckTub(s)) {
            num = num * 10 + (s - '0');
            s = getchar(); 
        }
        SumNums(num);
    }
    putchar('\n');
    return 0;
    
}
int main(void) {
    SumNumsInNumers();
}

