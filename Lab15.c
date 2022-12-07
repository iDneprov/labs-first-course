#include <stdio.h>

void FilingMatrix(int* matrix, int r, int c) {
    printf("Вводи элементы матрицы, мраз\n");
    printf("Введёшь криво - Я тебе пальчики секатором подровняю\n");

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            scanf("%d", ((matrix + i * c) + j));
    }
    printf("\n");
}

int MinElemMatrix(int* matrix, int r, int c) {
    int min = *matrix;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (min > *((matrix + i * c) + j))
                min = *((matrix + i * c) + j);
        }
    }

    return min;
}

int MaxElemMatrix(int* matrix, int r, int c) {
    int max = *matrix;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (max < *((matrix + i * c) + j))
                max = *((matrix + i * c) + j);
        }
    }

    return max;
}

int CountColumnMinElemMatrix(int* matrix, int r, int c) {
    int count = 0;
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (*((matrix + i * c) + j) == MinElemMatrix(matrix, r, c))
                ++count;
        }
    }

    return count;
}

int* NumbersColumnsMinElemMatrix(int* matrix, int r, int c, int n) {
    int numbersColumns[n];
    
    int counterAnswerMas = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (*((matrix + i * c) + j) == MinElemMatrix(matrix, r, c)) {
                numbersColumns[counterAnswerMas] = j;
                ++counterAnswerMas;
            }
        }
    }

    int* result = numbersColumns;
    
    return result;
}

int NumberColumnMaxElemMatrix(int* matrix, int r, int c) {
    int numberColumn;
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (*((matrix + i * c) + j) == MaxElemMatrix(matrix, r, c))
                numberColumn = j;
        }
    }
    
    return numberColumn;
}

void Lab15() {
    printf("Начало выполнения программы\n");
    
    printf("Введи колличество строк и столбцов, одним числом\n");
    int n = 0;
    scanf("%d", &n);

    int matrix[n][n];
    FilingMatrix(&matrix[0][0], n, n);

    int countChanges = CountColumnMinElemMatrix(&matrix[0][0], n, n);
    int* changeableColumns = NumbersColumnsMinElemMatrix(&matrix[0][0], n, n, countChanges); 
    
    int columnMaxElem = NumberColumnMaxElemMatrix(&matrix[0][0], n, n); 

    for (int counterExternal = 0; counterExternal < countChanges; ++counterExternal) {
        for (int counterInternal = 0; counterInternal < n; ++counterInternal)
            matrix[counterInternal][*changeableColumns + counterExternal] = matrix[counterInternal][columnMaxElem];
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%d", matrix[i][j]);
        printf("\n");
    }
}

int main(void) {
    Lab15();

    return 0;
}
