#include <iostream>
#include <vector>
 
#define MAX_SIZE_ELEMENT_IN_VECTOR 4
#define EOF '\n'
#define MAX_NUMBER 10000
using namespace std;

vector<int> num0;
vector<int> num1;
vector<int> num2;
char GLOBAL_SIGN = ' ';

// обработка чисел и поиск знака 
int CheckTub(char simbol) {
    return (simbol == EOF || simbol < '!' || simbol == '-' || simbol == '+' || simbol == '*' || simbol == '/' || simbol == '^');
}

int CheckSign(char simbol) {
    return (simbol == '-' || simbol == '+' || simbol == '*' || simbol == '/' || simbol == '^');
}

char SkipTabs(char simbolLast) {
    char simbol = getchar();
    while (simbol != EOF) {
        if (((simbol >= '0' && simbol <= '9') || simbol == '-') && CheckTub(simbolLast)) {
            break;
        }
        simbolLast = simbol;
        simbol = getchar();
    }
    return simbol;
}

char FindSign() {
    char simbol = getchar();
    while (simbol != EOF) {
        if (CheckSign(simbol)) {
            break;
        }
        simbol = getchar();
    }
    return simbol;
}

int CheckTheCorrectnessOfTheNumber(char simbol) {
    if (CheckSign(simbol) && GLOBAL_SIGN == ' ') {
        GLOBAL_SIGN = simbol;
    }
    else if (!CheckTub(simbol)) {
        return 0;
    }
    return 1;
}

int PowForNumbers(int x, int y) {
    int z = 1;
    while (y > 0) {
        if (y & 1) {
            z *= x;
        }
        x *= x;
        y = y >> 1;
    }
    return z;
}

void Replace(int size_number, vector<int>& num2) {
    int gamma = PowForNumbers(10, (size_number));
    int delta = PowForNumbers(10, MAX_SIZE_ELEMENT_IN_VECTOR - size_number);
    for (size_t i = num2.size() - 1; i > 0; i--) {
        num2[i] += (num2[i - 1] % delta) * gamma;
        num2[i - 1] /= delta;
    }
}

char Skip0() {
    char simbol = getchar();
    while (simbol == '0') {
        simbol = getchar();
    }
    return simbol;
}

void DeliteFirstsNulls(vector<int>& number) {
    int quantityNulls = 0;
    while (quantityNulls < number.size() - 1 && number[quantityNulls] == 0) {
        quantityNulls++;
    }
    number.erase(number.begin(), number.begin() + quantityNulls);
}

void FindNumber() {
    char simbol = SkipTabs(' ');
    int size_number = 0;
    bool sign = false;
    if (simbol == '-') {
        sign = true;
        simbol = getchar();
    }
    while (simbol >= '0' && simbol <= '9') {
        if (size_number / MAX_SIZE_ELEMENT_IN_VECTOR + 1 > num2.size()) {
            num2.emplace_back(0);
        }
        num2[size_number / MAX_SIZE_ELEMENT_IN_VECTOR] = num2[size_number / MAX_SIZE_ELEMENT_IN_VECTOR] * 10 + simbol - 48;
        size_number++;
        simbol = getchar();
    }
    if (num2.empty() && simbol != EOF) {
        FindNumber();
    }
    else if (CheckTheCorrectnessOfTheNumber(simbol)) {
        if (!num2[0]) {
            DeliteFirstsNulls(num2);
        }
        if (num2.size() > 1 && size_number % MAX_SIZE_ELEMENT_IN_VECTOR) {
            Replace(size_number % MAX_SIZE_ELEMENT_IN_VECTOR, num2);
        }
        if (sign) {
           for (int i = 0; i < num2.size(); i++) {
                num2[i] *= -1;
           }
        }
    }
    else {
        num2.clear();
        FindNumber();
    }
} 
// операции 
int ABS(int number) {
    return number > 0 ? number : -number;
}
int ceil(int i, int j) {
    return (i - (i / j) * j) > 0 ? i / j + 1 : i / j;
}

void ResizenumberHigher(size_t newSize, vector<int>& numberHigher) {
    size_t delta = newSize - numberHigher.size();
    numberHigher.resize(newSize, 0);
    for (int j = newSize - delta - 1; j > -1; j--) {
        swap(numberHigher[j], numberHigher[j + delta]);
    }
}

void DoPlus(vector<int>& numberLower, vector<int>& numberHigher, bool Minus) {
    if (numberHigher.size() < numberLower.size()) {
        ResizenumberHigher(numberLower.size(), numberHigher);
    }
    if (Minus) {
        for (int i = numberLower.size() - 1; i > -1; i--) {
            numberHigher[numberHigher.size() - numberLower.size() + i] -= numberLower[i];
        }
    }
    else {
        for (int i = numberLower.size() - 1; i > -1; i--) {
            numberHigher[numberHigher.size() - numberLower.size() + i] += numberLower[i];
        }
    }

    for (int i = numberHigher.size() - 1; i > 0; i--) {
        if (ABS(numberHigher[i]) >= MAX_NUMBER) {
            numberHigher[i - 1] += numberHigher[i] / MAX_NUMBER;
            numberHigher[i] -= (numberHigher[i] / MAX_NUMBER) * MAX_NUMBER;
        }
        if (numberHigher[i - 1] >= 0 && numberHigher[i] < 0 && numberHigher[0] > 0) {
                numberHigher[i - 1]--;
                numberHigher[i] += MAX_NUMBER;
        }
        else if (numberHigher[i - 1] <= 0 && numberHigher[i] > 0 && numberHigher[0] < 0) {
            numberHigher[i] = -1 * (MAX_NUMBER - numberHigher[i]);
            numberHigher[i - 1]++;
        }
    }
    if (ABS(numberHigher[0]) >= MAX_NUMBER) {
        ResizenumberHigher(numberHigher.size() + 1, numberHigher);
        numberHigher[0] = numberHigher[1] / MAX_NUMBER;
        numberHigher[1] = numberHigher[1] % MAX_NUMBER;
    }
    if (numberHigher[0] == 0) {
        DeliteFirstsNulls(numberHigher);
    }
}

vector<int> DoMultiply(vector<int>& num1, vector<int>& num2) {
    int sizeNum2 = num2.size(), sizeNum1 = num1.size();
    vector<int> result(sizeNum1 + sizeNum2);
    for (int i = sizeNum1 - 1; i > -1; i--) {
        for (int j = sizeNum2 - 1; j > -1; j--) {
            result[i + j + 1] += (num1[i] * num2[j]);
            result[i + j] += (result[i + j + 1]) / MAX_NUMBER;
            result[i + j + 1] %= MAX_NUMBER;
        }
    }
    if (result[0] == 0) {
        DeliteFirstsNulls(result);
    }
    return result;
}

vector<int> PowForVector(vector<int>& x, vector<int>& base) {
    vector<int> result(1,1);
    while (base[base.size() - 1] || base.size() > 1) {
        if (base[base.size() - 1] & 1) {
            result = DoMultiply(result, x);
        }
        x = DoMultiply(x, x);
        for (int i = 0; i < base.size() - 1; i++) {
            base[i + 1] += (base[i] & 1) * MAX_NUMBER;
            base[i] /= 2;
        }
        base[base.size() - 1] /= 2;
        DeliteFirstsNulls(base);
    }
    return result;
}

void ReplaceForDiv(int sizeDiv, vector<int>& div) {
    int gamma = PowForNumbers(10, (sizeDiv));
    int delta = PowForNumbers(10, MAX_SIZE_ELEMENT_IN_VECTOR - sizeDiv);
    for (int i = 0; i < div.size() - 1; i++) {
        div[i] = div[i] * delta + (div[i + 1] / gamma);
        div[i + 1] %= gamma;
    }
}

vector<int> DoDivision(vector<int>& divisible, vector<int>& diviser) {
    if (diviser.size() > divisible.size()) {
        return vector<int>(1, 0);
    }
    else if (!divisible[0]) {
        return vector<int>(1, 0);
    }
    else if (diviser.size() == 1 && divisible.size() == 1) {
        return vector<int>(1, divisible[0] / diviser[0]);
    }
    vector<int> result(1,0);
    vector<int> newDiv;
    vector<int> one(1, 1);
    vector<int> ten(1, 10);
    bool minus = false;
    int sizeDiviser = diviser.size() * MAX_SIZE_ELEMENT_IN_VECTOR, delta = MAX_NUMBER / 10, sizeDivisible = divisible.size() * MAX_SIZE_ELEMENT_IN_VECTOR, sizeDivNow = 0;
    while (!(diviser[0] / delta)) {
        sizeDiviser--;
        delta /= 10;
    }
    delta = MAX_NUMBER / 10;
    while (!(divisible[0] / delta)) {
        sizeDivisible--;
        delta /= 10;
    }
    if (diviser[0] < 0) {
        minus = !minus;
        for (int j = 0; j < diviser.size(); j++) {
            diviser[j] *= -1;
        }
    }
    if (divisible[0] < 0) {
        minus = !minus;
        for (int j = 0; j < divisible.size(); j++) {
            divisible[j] *= -1;
        }
    }
    if (sizeDivisible % MAX_SIZE_ELEMENT_IN_VECTOR) {
        ReplaceForDiv(sizeDivisible % MAX_SIZE_ELEMENT_IN_VECTOR, divisible);
        divisible[divisible.size() - 1] *= PowForNumbers(10, MAX_SIZE_ELEMENT_IN_VECTOR - sizeDivisible % MAX_SIZE_ELEMENT_IN_VECTOR);
    }
    for (int i = 0; i < sizeDivisible; i++) {
        if (newDiv.size() * MAX_SIZE_ELEMENT_IN_VECTOR <= sizeDivNow) {
            newDiv.resize(newDiv.size() + 1, 0);
        }
        newDiv[sizeDivNow / MAX_SIZE_ELEMENT_IN_VECTOR] = newDiv[sizeDivNow / MAX_SIZE_ELEMENT_IN_VECTOR] * 10 + ((divisible[i / MAX_SIZE_ELEMENT_IN_VECTOR] / (PowForNumbers(10, MAX_SIZE_ELEMENT_IN_VECTOR - i % MAX_SIZE_ELEMENT_IN_VECTOR - 1))) - (divisible[i / MAX_SIZE_ELEMENT_IN_VECTOR] / (PowForNumbers(10, MAX_SIZE_ELEMENT_IN_VECTOR - i % MAX_SIZE_ELEMENT_IN_VECTOR))) * 10);
        sizeDivNow++;
        if (sizeDivNow % MAX_SIZE_ELEMENT_IN_VECTOR) {
            Replace(sizeDivNow % MAX_SIZE_ELEMENT_IN_VECTOR, newDiv);
        }
        DoPlus(diviser, newDiv, true);
        while (newDiv[0] >= 0) {
            DoPlus(one, result, false);
            DoPlus(diviser, newDiv, true);
        }
        result = DoMultiply(result, ten);
        DoPlus(diviser, newDiv, false);
        delta = MAX_NUMBER / 10;
        if (newDiv[0] > 0) {
            sizeDivNow = newDiv.size() * MAX_SIZE_ELEMENT_IN_VECTOR;
            while (!(newDiv[0] / delta)) {
                sizeDivNow--;
                delta /= 10;
            }
        }
        else {
            sizeDivNow = 0;
        }
        ReplaceForDiv(sizeDivNow % MAX_SIZE_ELEMENT_IN_VECTOR, newDiv);
    }
    result[result.size() - 1] /= 10;
    Replace(MAX_SIZE_ELEMENT_IN_VECTOR - 1, result);
    if (minus) {
        for (int i = 0; i < result.size(); i++) {
            result[i] *= -1;
        }
    }
    return result;
}

void DoArithmetic(bool minus) {
    char sign;
    if (GLOBAL_SIGN != ' ') {
        sign = GLOBAL_SIGN;
        GLOBAL_SIGN = ' ';
    }
    else {
        sign = FindSign();
    }
    if (sign != EOF) {
        FindNumber();
    }
    if (num2.empty()) {
        sign = 'E';
    }
    switch (sign)
    {
    case '+':
        DoPlus(num1, num0, minus);
        num1.swap(num2);
        num2.clear();
        DoArithmetic(false);
        break;
    case '-':
        DoPlus(num1,num0, minus);
        num1.swap(num2);
        num2.clear();
        DoArithmetic(true);
        break;
    case '*':
        if (!num2.empty()) {
            num1 = DoMultiply(num1, num2);
        }
        num2.clear();
        DoArithmetic(minus);
        break;
    case '^':
        if (!num2.empty()) {
            num1 = PowForVector(num1, num2);
        }
        num2.clear();
        DoArithmetic(minus);
        break;
    case '/':
        if (!num2.empty()) {
            if (!num2[0]) {
                cout << "Error: /0 \n";
                break;
            }
            else {
                num1 = DoDivision(num1, num2);
            }
        }
        num2.clear();
        DoArithmetic(minus);
        break;
    default:
        if (sign == 'E') {
            DoPlus(num1, num0, minus);
        }
        break;
    }
}
void PrintNum0() {
    cout << num0[0];
    for (int i = 1; i < num0.size(); i++) {
        for (int j = MAX_NUMBER / 10; j > ABS(num0[i]) && j > 1; j /= 10) {
            cout << "0";
        }
        cout << ABS(num0[i]);
    }
}

void FindFirstNumber() {
    FindNumber();
    if (num2.empty()) {
        cout << "\n" << "Error: No numbers";
    }
    else {
        num1.swap(num2);
        num2.clear();
        DoArithmetic(false);
        PrintNum0();
    }
}

int main(){
    FindFirstNumber();
}
