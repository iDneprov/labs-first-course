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
    unsigned long long otherVowels = (1llu << (L'а' - L'а') | 1llu << (L'о' - L'а') | 1llu << (L'у' - L'а') | 1llu << (L'э' - L'а') | 1llu << (L'ы' - L'а') | 1llu << (L'и' - L'а'));
    unsigned long long vowelsType2 = (1llu << (L'е' - L'а') | 1llu << (L'ё' - L'а') | 1llu << (L'ю' - L'а') | 1llu << (L'я' - L'а'));
    unsigned long long setOfLetters = 0;
    wint_t symb = 0;
    char flag = 0;
    while (1) {
        symb = getwchar();
        setOfLetters = setOfLetters | MakeSet(symb);
        if ((symb == ' ' || symb == '\n' || symb == ',' || symb == WEOF) && (setOfLetters > 0)) {
            if ((setOfLetters & OtherVowels) == 0) {
                flag = 1;
            }
            setOfLetters = 0;
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

