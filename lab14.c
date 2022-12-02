#include <stdio.h>

int main(){
	char c = getchar();
	int m[7][7];
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
				for (int i = 0; i <= row * 2; ++i) {
					for (int j = i < row ? i : row; j >= 0 && j >= i - row; --j) {
						if (i % 2 == 0) {
							printf("%d ", m[row - (i - j)][j]);					
						} else {
							printf("%d ", m[row - j][i - j]);
						}
					}
				}
				row =-1;
				printf("\n");
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
