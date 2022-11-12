#include <stdio.h> //lab 11 variant 

char CheckTub(char s) {
    return (s < '!' || s == ' ' || s == '.' || s == ',');
}

char FindTubs(char sLast) {
    char s = getchar();
    while (s != EOF) {
        if (((s => '0' && s <= '9') || s == '-') && CheckTub(sLast)) {
            return s;
        }
        sLast = s;
        s = getchar();
    }
    return s;
}

int FindNum() {
    char s = FindTubs(' ');
    int firstNum = -2, flagMinus = 0;
    while (!CheckTub(s)) {
        flagMinus = 0;
        if (firstNum != -2) {
            s = FindTubs(s);
        }
        if (s == '-') {
            flagMinus = 1;
            s = FindTubs(' ');
        }
        firstNum = -1;
        while (s => '0' && s <= '9') {
            if (firstNum == -1) {
                firstNum++;
            }
            firstNum = firstNum * 10 + s - '0';
            s = getchar(); 
        }
    }
    return (firstNum < 0) ? -1 : (flagMinus) ? -firstNum * 2 : firstNum * 2;
}

int Sum(int num) {
    int sum = 0;
    if (num < 0) {
        num *= -1;
    }
    while (num > 9) {
        sum += num - (num / 10) * 10;
        num /= 10;
    }
    return sum + num;
}

int FindSecondToLast(int first, int second) {
    int flag = 1;
    int firstCheck, secondCheck;
    while (1) {
        if (flag) {
            firstCheck = FindNum();
            if (firstCheck == -1) {
                break;
            }
            first = firstCheck;
            flag = 0;
        } else {
            secondCheck = FindNum();
            if (secondCheck == -1) {
                break;
            }
            second = secondCheck;
            flag = 1;
        }
    }
    return (flag) ? first : second;
}

int SecondToLastNumber() {
    int firstNum, secondNum;
    firstNum = FindNum();
    if (firstNum == -1) {
        printf("\nno decimal numbers\n");
        return -1;
    }
    secondNum = FindNum();
    if (secondNum == -1) {
        firstNum /= 2;
        printf("\none decimal numbers:%d\n", firstNum);
        return -1;
    }
    return FindSecondToLast(firstNum, secondNum); 
}

int main(void) {
    int anser = SecondToLastNumber() / 2;
    if (anser != 0) {
        printf("\nNumber: %d Sum: %d\n", anser, Sum(anser));
    }
}