//Принимаю пакет тестов с помощью команды ./a.out < test.txt(в этом файле лежит пакет тестов)
#include <stdio.h>

int Check(int *mas) {
    for (int i = 0; i < 10; ++i) {
        if (mas[i] == 0) {
            return -1;
        }
    }
    return 0;
}

int main() {
    int mas[10];
    char a = 0;
    while (1) {
        a = getchar();
        if (a == EOF) {
            break;
        } else {
            if (a != '\n') {
                mas[a - '0'] += 1;
            }
            if (a == '\n') {
                if (Check(mas) == -1) {
                    printf("%s %s", "YES", "\n");
                } else {
                    printf("%s %s", "NO", "\n");
                }
                for (int j = 0; j < 10; ++j) {
                    mas[j] = 0;
                }
            }
            if (a == '-') {
                continue;
            }
        }
    }
    return 0;
    printf("%s", "\n");
}
