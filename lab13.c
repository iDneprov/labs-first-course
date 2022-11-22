// есть ли слова содержащие гласные только 1ого рода (аоуэыи)

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <wctype.h>

unsigned long long SetDifference(unsigned long long set1, unsigned long long set2) {
    return set1 & ~set2;
}

unsigned long long CharToSet(wint_t c) {
    c = towlower(c);
    if (c < L'а' || c > L'ё'){
        return 0;
    } else {
        return 1llu << (c - L'а');
    }
}

void SetOutput(unsigned long long set) {
    for (wint_t i = L'а'; i <= L'ё'; i++) {
        if ((CharToSet(i) & set) != 0) {
            wprintf(L"%lc ", i);
        }
    }
    wprintf(L"\n");
}

int main(void) {
    setlocale(LC_ALL, "");
    unsigned long long vowelsType1 = (1llu << (L'а' - L'а') | 1llu << (L'о' - L'а') | 1llu << (L'у' - L'а') | 1llu << (L'э' - L'а') | 1llu << (L'ы' - L'а') | 1llu << (L'и' - L'а'));
    unsigned long long vowels = (1llu << (L'а' - L'а') | 1llu << (L'о' - L'а') | 1llu << (L'у' - L'а') | 1llu << (L'э' - L'а') | 1llu << (L'ы' - L'а') | 1llu << (L'и' - L'а') | 1llu << (L'е' - L'а') | 1llu << (L'ё' - L'а') | 1llu << (L'ю' - L'а') | 1llu << (L'я' - L'а'));
    unsigned long long lettersSet = 0;
    wint_t c, ch = 0;
    char flag = 0;

    while (1) {
        c = getwchar();
        if ((ch == ' ' || ch == '\n' || ch == ',') && c != WEOF) {
            lettersSet = 0;
        }
        lettersSet = lettersSet | CharToSet(c);
        if ((c == ' ' || c == '\n' || c == ',') && (ch >= L'а' && ch <= L'ё')) {
            if (SetDifference(vowels & lettersSet, vowelsType1) == 0) {
                flag = 1;
            }
        } else if (c == WEOF) {
            break;
        }
        ch = c;
    }
    if ((SetDifference(lettersSet & vowels, vowelsType1) == 0 || flag == 1) && lettersSet != 0) {
        wprintf(L"Yes\n");
    } else {
        wprintf(L"No\n");
    }
}
