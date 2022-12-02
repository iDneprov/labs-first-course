#include <stdio.h>

int main(){
	char c = getchar();
	int m[8][8];
	int row = 0, col = 0, num = 0, sign = 1;
	while (c != EOF) {
		if (c == ' ') {
			m[row][col] = num * sign;
			++col;
			num = 0;
			sign = 1;
		} else if (c == '\n') {
			m[row][col] = num * sign;
			if (col == row) {
				++row;
				for (int i = 0; i < row; ++i) { 		
					for (int j = 0; j < row; ++j) {
						printf("%d ", m[i][(j + 110) % row]);
					}
					printf("\n");
				}
				row = -1;	
			}
			++row;
			col = 0;
			num = 0;
			sign = 1;
		} else if (c == '-') {
			sign = -1;
		} else {
			num = num * 10 + ((int)c - 48);
		}
		c = getchar();
	}
}
