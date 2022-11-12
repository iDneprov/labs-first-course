#include <stdio.h> //lab 12 variant 26

char CheckTub(char s) {
    return (s < 33 || s == ' ' || s == '.' || s == ',' || s == '-');
}

char FindTubs(char sLast) {
    char s = getchar();
    while (s != EOF) {
        if ((s > 47 && s < 58) && CheckTub(sLast)) {
            return s;
        }
        sLast = s;
        putchar(s);
        s = getchar();
    }
    return s;
}

int SumNums(char nums[], int i) {
    int sum = 0, j = 0;
    if (i < 2) {
        while (j < i) {
            putchar(nums[j]);
            j++;
        }
        return 0;
    }
    if (i%2) {
        putchar(nums[0]);
        j++;
    }
    while (j < i) {
        sum = nums[j] + nums[j + 1] - 96;
        if (sum < 10) {
            sum = sum + '0';
            putchar(sum);
        }
        putchar(nums[j]);
        putchar(nums[j + 1]);
        j += 2;
    }
    return 0;
}

int SumNumsInNumers() {
    char s = FindTubs(' ');
    char nums[32];
    int firstNum = 0, i = 0;
    while (s != EOF) {
        i = 0;
        if (firstNum) {
            putchar(s);
            s = FindTubs(s);
        }
        firstNum = 1;
        while (!CheckTub(s)) {
            nums[i] = s;
            i++;
            s = getchar(); 
        }
        SumNums(nums, i);
    }
    putchar('\n');
    return 0;
    
}
int main(void) {
    SumNumsInNumers();
}
