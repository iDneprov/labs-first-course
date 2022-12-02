#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define VOWELS (1u<<('a'-'a') | 1u<<('e'-'a') | 1u<<('i'-'a')| 1u<<('o'-'a') | 1u<<('u'-'a'))

unsigned int CharToSet(char c) {
    c = tolower(c);

    if (c < 'a' || c > 'z')
        return 0;
    else
        return 1u<<(c-'a');
}

unsigned int CreateSet() {
    unsigned int set = 1u<<('b'-'a');
    
    char symb = 'a';
    while (true) {
        symb = getchar();
        if (symb == EOF)
            break;
        
        if (symb == ' ' && symb == '\t' && symb == ',' && symb == '\n')
            break;   
    
        set = set | CharToSet(symb);
    }   
    
    return set;
}

bool CheckWord(unsigned int letters) {
    if ((letters & VOWELS) == VOWELS)
        return true; 
    
    return false;
}

bool SearchWord() {
    printf("Введи слова\n");
    
    if (CheckWord(CreateSet())) 
        return true;
    
    return false;
}

void OutPut() {
    if (SearchWord())
        printf("\nСлово со всеми гласными найдено");
    else
        printf("\nСлово со всеми гласными НЕ найдено");
}

int main(void) {
    OutPut();
    
    return 0;
}
