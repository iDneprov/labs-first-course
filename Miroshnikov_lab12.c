#include<stdio.h>

int Abs(int a) {
    return (a >= 0) ? a : -a;
}

int Check(int *mas, int i) {
    for (i = 0; i < 10; ++i) {
        if (mas[i] == 0) {
            return -1;
        }
        return 0;
    }
}

int main() {
    int mas[10];
    int a, ch, i;
    scanf("%d", &a);
    a = Abs(a);
    while (a != 0) {
        ch = a % 10;
        mas[ch] += 1;
        a = a / 10;
    }
    if (Check(mas, i) == -1) {
        printf("%s %s", "YES", "\n");
    } else {
        printf("%s %s", "NO", "\n");
    }
    return 0;
}