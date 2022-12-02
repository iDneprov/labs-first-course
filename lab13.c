#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define VOWELS (1u << ('a' - 'a') | 1u << ('e' - 'a') | 1u << ('i' - 'a') | 1u << ('o' - 'a') | 1u << ('u' - 'a'))

bool IsVowel(char c) {
	return (1u << (tolower(c) - 'a') & VOWELS) != 0;
}

int main() {
	char c, prev;
	bool check = false, s = false;
	
	c = getchar();
	prev = c;
	s = IsVowel(c);
  
	while (c != EOF) {
		if (c == ' ' || c == ',') {
			s = s & IsVowel(prev);
			check = s | check;	    
			c = getchar();
			s = IsVowel(c); 
		}	
		if (c == '\n' || c == EOF) {
			s = s & IsVowel(prev);
			check = s | check;	
			if (check) {                
				printf("Yes\n");        
			} else {
				printf("No\n");            
			}
			check = false;
			c = getchar();
			prev = c;
			s = IsVowel(c);
		}
		prev = c;
		c = getchar();
	}
}
