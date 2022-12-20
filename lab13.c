#include <stdio.h>
 
struct countVowels {
    int a;
    int e;
    int i;
    int o;
    int u;
    int y;
 
};
 
int main() {
    //find the vowel that is contained in each word that is readed from the console and print this vowel
    char c;
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    struct countVowels count;
 
    while ((c = getchar()) != '!') {
        if (c == 'a') count.a = 1;
        else if (c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') count.a = 0;
        if (c == 'e') count.e = 1;
        else if (c == 'a' || c == 'i' || c == 'o' || c == 'u' || c == 'y')count.e = 0;
        if (c == 'i') count.i = 1;
        else if (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'y')count.i = 0;
        if (c == 'o') count.o = 1;
        else if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'y')count.o = 0;
        if (c == 'u') count.u = 1;
        else if (c == 'a' || c == 'e' || c == 'i' || c == 'y' || c == 'o') count.u = 0;
        if (c == 'y') count.y = 1;
        else if (c == 'a' || c == 'i' || c == 'o' || c == 'e' || c == 'u') count.y = 0;
    }
    int a = count.a, e = count.e, i = count.i, o = count.o, u = count.u, y = count.y;
    if (a == 1) printf("%c", 'a');
    if (e == 1) printf("%c", 'e');
    if (i == 1) printf("%c", 'i');
    if (o == 1) printf("%c", 'o');
    if (u == 1) printf("%c", 'u');
    if (y == 1) printf("%c", 'y');
 
}