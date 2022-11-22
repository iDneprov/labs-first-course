#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define SLASH 2
#define STAR 3
#define ENTER 4
#define SEPARATOR 5
#define CHAR 6
#define END 7

int StateUpdate(char c) {
	if (c == '/') {
		return SLASH;
	} else if (c == '*') {
		return STAR;
	} else if (c == '\n') {
		return ENTER;
	} else if (c == ',' || c == ' ') {
		return SEPARATOR;
	} else if (c == EOF) {
		return END;
	} else {
		return CHAR;
	}
}

int main()
{
	FILE *f;
	f = fopen("lr11.txt", "r");
	if (f == NULL)
	{
		printf("failed to open file");
	}
	int flagEnter = 0, flagComm = 0, flagWord = 0;
	int counter = 0, counterFull;
	int state1 = 0, state2 = 0;
	char c1, c2;
	while (!feof(f)) {
		while (1) {
			c1 = fgetc(f);
			c2 = fgetc(f);
			state1 = StateUpdate(c1);
			state2 = StateUpdate(c2);
			if (state1 == SLASH && state2 == STAR) {
				flagComm = 1;
			} else if (state1 == CHAR && state2 != CHAR) {
				counter++;
			} else if (state1 == ENTER || state2 == ENTER) {
				flagEnter = 1;
			} else if (state1 == STAR && state2 == SLASH && flagComm != 0) {
				if (flagEnter) {
					counterFull += counter;
				}
				counter = 0;
				flagComm = 0;
				flagEnter = 0;

			}
			
		}
	}
	printf("%d\n", k);
	fclose(f);
	return 0;
}
/* /**/