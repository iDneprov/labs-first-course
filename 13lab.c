#include <stdio.h>
#include <ctype.h>
#include <locale.h>

#define DEAF (1ull << ('q' - 'a') | 1ull << ('t' - 'a') | 1ull << ('p' - 'a') | 1ull << ('s' - 'a') | 1ull << ('f' - 'a') | 1ull << ('h' - 'a') | 1ull << ('k' - 'a') | 1ull << ('x' - 'a') | 1ull << ('c' - 'a'))
// #define DEAF 76383396ULL работает одинаково ,если по букве, или если перевести двоичный код в 10, где 1-цы это глухие согласные
#define VOWELS 17842449ULL

unsigned long long int CharInSet(int a) {
    if (a >= 'a' && a <= 'z') {
        return 1ull << (a - 'a');
    } else {
        return 0;
    }
}

int main() {
    char a;
    unsigned long long int Set = 0 , NewSet = 0;
    a = getchar();
    while (a != EOF) {
        if (a != ' ' && a != '\n') {
            Set = Set | CharInSet(a);
        } else {
            NewSet = Set & (DEAF | VOWELS);
            if (NewSet == Set) break;
            Set = 0;
        }
        a = getchar();
    }
    NewSet = Set & (DEAF | VOWELS);
    if ((NewSet == Set) && Set != 0) {
        printf("Есть слово,все согласные которого глухие !\n");
    } else {
        printf("Нет такого слова.\n");
    }
}

