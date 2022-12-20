#include <stdio.h>
#include <ctype.h>
#define VOWELS (1u << ('a'-'a') | 1u<<('e'- 'a') | 1u<<('i'- 'a') | 1u<<('o'- 'a') | 1u<<('u'- 'a') | 1u<<('y'- 'a'))

unsigned int char_to_set(char c){
  c  = tolower(c);
  if ((c < 'a') || (c > 'z')){
    return 0;
  }
  else {
    return 1u << (c - 'a');
  }
}
int main(void){
    printf("Входная строка:\n");
  char glas, c;
  unsigned int letters_set = 0; 
  unsigned int end_set = 1u<<('a'-'a') | 1u<<('e'- 'a') | 1u<<('i'- 'a') | 1u<<('o'- 'a') | 1u<<('u'- 'a') | 1u<<('y'- 'a');
  while((c = getchar()) != EOF){
    letters_set = (char_to_set(c) | letters_set) & VOWELS;
    if (((c == ' ') || (c == '\t')  || (c == '\n') || (c == ',')) && (letters_set != 0)){
      end_set = end_set & letters_set;
      letters_set = 0;
    }
  }
  for (glas = 'a'; glas <= 'z'; glas++){
    if (((char_to_set(glas) & VOWELS) != 0) && ((char_to_set(glas) & end_set) != 0)){
      printf("\nГласная, входящая в состав всех слов: %c \n", glas);
    }
  }
  return 0;
}
