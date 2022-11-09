#include <stdio.h>

#define MAX_N 8

int CustomPow(int a, int b) {
	int result = 1;

	for (int i = 0; i < b; i++) {
		result *= a;
	}
	return result;
}

int DefineCurrent(int n) {
	if (n % 2) {
		return n / 2;
	}
	return n / 2 - 1;
}

int DoStaff(int matrix[MAX_N][MAX_N], int n) {
	int lambda;
	int counter = 0, step = 0, currentX, currentY;
	int ultraRenda1, prevX, prevY;

	if (n - 1) {
		// Первый элемент
		currentX = DefineCurrent(n);
		currentY = currentX;
		ultraRenda1 = matrix[currentY][currentX];
		prevX = currentX;
		prevY = currentY;

		// Общий проход
		for (int x = 0; x < n - 1; x++) {
			lambda = CustomPow(-1, x + 1);
			step += 1;
			for (int y = 0; y < 2; y++) {
				for (int z = 0; z < step; z++) {
					if (y) {
						currentY -= lambda;
					}
					else {
						currentX -= lambda;
					}
					counter += 1;
					matrix[prevY][prevX] = matrix[currentY][currentX];
					prevX = currentX;
					prevY = currentY;
				}
			}
		}
		// Конечный добор
		lambda *= -1;
		for (int z = 0; z < step; z++) {
			currentX -= lambda;
			counter += 1;
			matrix[prevY][prevX] = matrix[currentY][currentX];
			prevX = currentX;
			prevY = currentY;
		}
		// Последний элемент
		matrix[prevY][prevX] = ultraRenda1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
	}
	else {
		printf("\n%d\n", matrix[0][0]);
	}
	return 0;
}

int main() {
	int n;
	int matrix[MAX_N][MAX_N];

	//Ввод данных
	scanf("%d", &n);
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j != n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	DoStaff(matrix, n);
	putchar('\n');
}
