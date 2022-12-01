#include <stdio.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>

unsigned long long MakeSet(wint_t symb) {
    symb = towlower(symb);
    if (symb < L'а' || symb > L'ё'){
        return 0;
    } else {
        return 1llu << (symb - L'а');
    }
}

int main(void) {
    setlocale(LC_ALL, "");
    unsigned long long other_vowels = (1llu << (L'а' - L'а') | 1llu << (L'о' - L'а') | 1llu << (L'у' - L'а') | 1llu << (L'э' - L'а') | 1llu << (L'ы' - L'а') | 1llu << (L'и' - L'а'));
    unsigned long long vowels_type_2 = (1llu << (L'е' - L'а') | 1llu << (L'ё' - L'а') | 1llu << (L'ю' - L'а') | 1llu << (L'я' - L'а'));
    unsigned long long set_of_letters = 0;
    wint_t symb = 0;
    char flag = 0;
    while (1) {
        symb = getwchar();
        set_of_letters = set_of_letters | MakeSet(symb);
        if ((symb == ' ' || symb == '\n' || symb == ',' || symb == WEOF) && (set_of_letters > 0)) {
            if (((set_of_letters & vowels_type_2) != 0) && ((set_of_letters & other_vowels) == 0)) {
                flag = 1;
            }
            set_of_letters = 0;
        } 
        if (symb == WEOF) {
            break;
        }
    }
    if (flag == 1) {
        wprintf(L"\nYes\n");
    } else {
        wprintf(L"\nNo\n");
    }
}
