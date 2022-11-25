#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void FilingMatrix(int* matrix, int r, int c) {
    printf("Вводи элементы матрицы, мраз\n");
    printf("Введёшь криво - Я тебе пальчики секатором подровняю\n");

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            scanf("%d", ((matrix + i * r) + j));
    }
    printf("\n");
}

bool TestFilingMatrix() {
    printf("Начало тестирования\nТестовые данные 10 10 20 20\n");
    
    int checkMatrix[2][2] = {{10, 10}, {20, 20}};
    
    int testMatrix[2][2];
    FilingMatrix(&testMatrix[0][0], 2, 2);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (testMatrix[i][j] != checkMatrix[i][j])
                return false;
        }
    }
    printf("Всё ок, не ссы, продолжаем\n\n");

    return true;
}

void Lab14() {
    assert(TestFilingMatrix() != false);

    printf("Начало выполнения программы\n");
    printf("Введи колличество строк и столбцов, одним числом\n");

    int n = 0;
    scanf("%d", &n);

    int matrix[n][n];
    FilingMatrix(&matrix[0][0], n, n);
   
    for (int j = 0; j < n; ++j) 
        printf("%d ", matrix[0][j]);
    printf("\n");

    for (int i = 1; i < n; ++i) 
        printf("%d ", matrix[i][n - 1]);
    printf("\n");

    for (int j = n - 2; j >= 0; --j)
        printf("%d ", matrix[n - 1][j]);    
    printf("\n");

    for (int i = n - 2; i >= 1; --i)
        printf("%d ", matrix[i][0]);    
    printf("\n");

    for (int j = 1; j < n - 2; ++j) 
        printf("%d ", matrix[1][j]);
    printf("\n");

    for (int i = 1; i < (n - 1); ++i)
        printf("%d ", matrix[i][n - 2]);
    printf("\n");

    if (n == 5) {
        for (int j = 2; j > 1; --j)
            printf("%d ", matrix[n - 2][j]);
    }
    
    if (n == 4 || n == 5) {
        for (int i = n - 2; i > 1; --i)
            printf("%d ", matrix[i][1]);
        printf("\n");
    }
    
    if (n == 5) {
        printf("%d ", matrix[2][2]);
        printf("\n");
    }
    
    if (n > 5) {
        for (int j = n - 3; j > 1; --j)
            printf("%d ", matrix[n - 2][j]); 
        printf("\n");

        for (int i = n - 2; i > 1; --i)
            printf("%d ", matrix[i][1]);
        printf("\n");
        
        for (int j = 2; j < (n - 2); ++j)
            printf("%d ", matrix[2][j]); 
        printf("\n");

        if (n == 6) {
            for (int i = 2; i < (n - 2); ++i)
                printf("%d ", matrix[i][n - 3]);
            printf("\n");
            
            for (int j = 3; j > 1; --j)
                printf("%d ", matrix[3][j]);
            printf("\n");
        }
        
        if (n == 7) {
            for (int i = 3; i < (n - 2); ++i)
                printf("%d ", matrix[i][n - 3]);
            printf("pup\n");
            
            for (int j = n - 3; j > 1; --j)
                printf("%d ", matrix[n - 3][j]);
            printf("\n");
        
            for (int j = 2; j < 4; ++j)
                printf("%d ", matrix[3][j]);
            printf("\n");
        }    
    }

}

int main() {
    Lab14();

    return 0;
}
