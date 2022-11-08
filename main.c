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
	int counter = 0, step = 0, current_x, current_y;
	int ultraRenda1, prev_x, prev_y;

	if (n - 1) {
		// Первый элемент
		current_x = DefineCurrent(n);
		current_y = current_x;
		ultraRenda1 = matrix[current_y][current_x];
		prev_x = current_x;
		prev_y = current_y;

		// Общий проход
		for (int x = 0; x < n - 1; x++) {
			lambda = CustomPow(-1, x + 1);
			step += 1;
			for (int y = 0; y < 2; y++) {
				for (int z = 0; z < step; z++) {
					if (y) {
						current_y -= lambda;
					} else {
						current_x -= lambda;
					}
					counter += 1;
					matrix[prev_y][prev_x] = matrix[current_y][current_x];
					prev_x = current_x;
					prev_y = current_y;
				}
			}
		}
		// Конечный добор
		lambda *= -1;
		for (int z = 0; z < step; z++) {
			current_x -= lambda;
			counter += 1;
			matrix[prev_y][prev_x] = matrix[current_y][current_x];
			prev_x = current_x;
			prev_y = current_y;
		}
		// Последний элемент
		matrix[prev_y][prev_x] = ultraRenda1;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}

	} else {
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
