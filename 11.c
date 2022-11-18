#include <stdio.h> //lab 11 variant 

char CheckTub(char s) {
    return (s < '!' || s == ' ' || s == '.' || s == ',');
}

char FindTubs(char sLast) {
    char s = getchar();
    while (s != EOF) {
        if (((s >= '0' && s <= '9') || s == '-') && CheckTub(sLast)) {
            return s;
        }
        sLast = s;
        s = getchar();
    }
    return s;
}

int FindNum(int* sum) {
    char s = FindTubs(' ');
    int firstNum = -2, flagMinus = 0, sumSave = *sum;
    while (!CheckTub(s)) {
        flagMinus = 0;
        if (firstNum != -2) {
            s = FindTubs(s);
        }
        if (s == '-') {
            s = getchar();
            if (s >= '0' && s <= '9'){
                flagMinus = 1;
            } else {
                s = FindTubs(s);
            }
        }
        firstNum = -1;
        while (s >= '0' && s <= '9') {
            if (firstNum == -1) {
                firstNum++;
                *sum = 0;
            }
            *sum += s - '0';
            firstNum = firstNum * 10 + s - '0';
            s = getchar(); 
        }
    }
    if (firstNum < 0) {
        *sum = sumSave;
        return -1;
    }
    return (flagMinus) ? -firstNum * 2 : firstNum * 2;
}

int FindSecondToLast(int first, int second, int sumFirst, int sumSecond) {
    int flag = 1;
    int firstCheck, secondCheck;
    while (1) {
        if (flag) {
            firstCheck = FindNum(&sumFirst);
            if (firstCheck == -1) {
                break;
            }
            first = firstCheck;
            flag = 0;
        } else {
            secondCheck = FindNum(&sumSecond);
            if (secondCheck == -1) {
                break;
            }
            second = secondCheck;
            flag = 1;
        }
    }
    if (flag) {
        printf("\nSum:%d", sumFirst);
    } else {
        printf("\nSum:%d", sumSecond);
    }
    return (flag) ? first : second;
}

int SecondToLastNumber() {
    int firstNum, secondNum, sumFirst = 0, sumSecond = 0;
    firstNum = FindNum(&sumFirst);
    if (firstNum == -1) {
        printf("\nno decimal numbers\n");
        return -1;
    }
    secondNum = FindNum(&sumSecond);
    if (secondNum == -1) {
        firstNum /= 2;
        printf("\none decimal numbers:%d\n", firstNum);
        return -1;
    }
    return FindSecondToLast(firstNum, secondNum, sumFirst, sumSecond); 
}

int main(void) {
    int anser = SecondToLastNumber() / 2;
    if (anser != 0) {
        printf("\nNumber:%d\n", anser);
    }
}

