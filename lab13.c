//17 вариант
#include <stdio.h>
#include <ctype.h>

const unsigned int ALPHABET_VOWELS = (1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a') | 1u << ('y' - 'a'));

int main() {
    short int start = 1, final = 0, bool1 = 0;
    unsigned int s, first = 0, second = 0;
    char a;
    while (1) {
        a = getchar();
        a = tolower(a);
        if (final) {
            if (a == EOF) 
                break;
            continue;       
        }

        if (a == ' ' || a == ',' || a == '\t' || a == '\v' || a == '\n' || a == EOF) {   
            if (bool1) {
                bool1 = 0;
                if (a == ' ' || a == ',' || a == '\n') {
                    if (start) 
                        start = 0;
                    else 
                        if ((first & second) != 0)  
                            final = 1;       
                    second = first;
                    first = 0;   
                } else {     
                    if (!start) 
                        if ((first & second) != 0)
                            final = 1;                
                    if (a == EOF) 
                        break;    
                    second = first = 0;
                    start = 1; 
                }
            } else
                if (a == EOF)
                    break;  
        } else {
            bool1 = 1;
            if (a >= 'a' && a <= 'z') {
                s = 1u << (a - 'a');
                    if((s & ALPHABET_VOWELS) && ((s & first) == 0))
                    first = first | s; 
            }
        }
    }
    if (final) 
        printf("YES\n");
    else 
        printf("NO\n");
    return 0;
}
