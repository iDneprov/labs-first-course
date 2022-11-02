#include <stdio.h>

#define maxN 100

int DisplayMatrixDM(int matrix[maxN][maxN], int n) {
  putchar('\n');

  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != n; j++) {
      printf("%d ", matrix[i][j]);
    }
    putchar('\n');
  }
  return 0;
}

int DisplayMatrixSM(int matrix[maxN], int n) {
  putchar('\n');

  for (int i = 0; i != n * n; ++i) {
    printf("%d ", matrix[i]);
    if (!((i + 1) % n)) {
      putchar('\n');
    }
  }
  return 0;
}

int CustomGrade(int a, int b) {
  int result = 1;

  for (int i = 0; i < b; i++)
  {
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



int DoStaff(int matrix[maxN][maxN], int n, int cyclic) {
  int lambda;
  int indexMatrix[maxN * maxN], Queue[maxN * maxN], NewQueue[maxN * maxN];;
  int counter = 0, step = 0, current_x = DefineCurrent(n), current_y = current_x;

  if (n - 1){
    // ------> Разложение мтричцы на массив индексов и массив очереди
    // Первый элемент
    Queue[n * n - 1 - counter] = matrix[current_y][current_x];
    indexMatrix[current_y * n + current_x] = n*n - 1 - counter;

    // Общий проход
    for (int x = 0; x < n - 1; x++) {
      lambda = CustomGrade(-1, x + 1);
      step += 1;
      for (int y = 0; y < 2; y++) {
        for (int z = 0; z < step; z++) {
          if (y) {
            current_y -= lambda;
          } else {
            current_x -= lambda;
          }
          counter += 1;
          Queue[n * n - 1 - counter] = matrix[current_y][current_x];
          indexMatrix[current_y * n + current_x] = n * n - 1 - counter;
        }
      }
    }
    // Конечный добор
    lambda *= -1;
    for (int z = 0; z < step; z++) {
      current_x -= lambda;
      counter += 1;
      Queue[n * n - 1 - counter] = matrix[current_y][current_x];
      indexMatrix[current_y * n + current_x] = n * n - 1 - counter;
    }
    // ------> Циклический сдвиг
    // Циклический сдвиг массива queue вправо
    for (int x = 0; x < cyclic; x++) {
      for (int i = 0; i < n * n - 1; i++) {
        NewQueue[i + 1] = Queue[i];
      }
      NewQueue[0] = Queue[n * n - 1];
    
      for (int i = 0; i < n * n; i++) {
        Queue[i] = NewQueue[i];
      }
    }
    // Вывод итоговой матрицы
    putchar('\n');
    for (int i = 0; i < n * n; i++) {
      printf("%d ", Queue[indexMatrix[i]]);
      if (!((i + 1) % n)) {
        putchar('\n');
      }
    }
  } else {
    printf("\n%d\n", matrix[0][0]);
  }
  return 0;
}




int main() {
  int n, cyclic;
  int matrix[maxN][maxN];

  //Ввод данных
  scanf("%i", &n);
  if (n) {
    for (int i = 0; i != n; ++i) {
      for (int j = 0; j != n; j++) {
        scanf("%i", &matrix[i][j]);
      }
    }
    scanf("%i", &cyclic);
    DoStaff(matrix, n, cyclic);
  }
  putchar('\n');

}
