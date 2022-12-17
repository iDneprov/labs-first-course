#include <stdio.h>
#include <ctype.h>

#define Start ((1u << ('b' - 'a')) | (1u << ('c' - 'a')) | (1u << ('d' - 'a')) | (1u << ('f' - 'a')) | (1u << ('g' - 'a')) | (1u << ('h' - 'a')) | (1u << ('j' - 'a')) | (1u << ('k' - 'a')) | (1u << ('l' - 'a')) | (1u << ('m' - 'a')) | (1u << ('n' - 'a')) | (1u << ('p' - 'a')) | (1u << ('q' - 'a')) | (1u << ('r' - 'a')) | (1u << ('s' - 'a')) | (1u << ('t' - 'a')) | (1u << ('v' - 'a')) | (1u << ('w' - 'a')) | (1u << ('x' - 'a')) | (1u << ('y' - 'a')) | (1u << ('z' - 'a')))

int main(void){
    unsigned int set_sym;
    unsigned int set_in;
    char sym;
    int count;

    set_in = 0;
    count = 0;
    set_sym = 0;

    while (scanf("%c", &sym) != EOF) {
        if (sym == ' ' || sym == '\n') {
            set_in = 0;
            set_sym = 0;
        }
        sym = tolower(sym);
        if (sym >= 'a' && sym <= 'z') {
            set_sym = 1u << (sym - 'a');
        } else {
            set_sym = 0;
        }
        if ((set_sym & set_in) != 0) {
            count = 1;
        }
        set_in = set_in | set_sym;
        set_in = set_in & Start;
    }
    if (count == 1) {
        printf("Yes\n");
    }
    if (count == 0) {
        printf("No\n");
    }
    return 0;
}