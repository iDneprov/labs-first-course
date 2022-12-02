#include <stdio.h>

int main(){ 
	int c = getchar();
	int shift = 1;
	
	while(c != EOF) {
		if(c == ' ') {
			shift = (shift + 1) % 26;
			putchar(' ');
		}
		else if(c == '\n') {
			shift = 1;
			putchar('\n');
		}
		else {
			c = c - shift;
			if((c + shift <= 'Z' && c + shift >= 'A' && c < 'A') || (c + shift <= 'z' && c + shift >= 'a' && c < 'a')) c += 26; 
			putchar(c);
		}
		c = getchar();
	}
}    
