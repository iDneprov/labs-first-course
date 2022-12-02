#include <stdio.h>
//#include <stdbool.h>
//#include <assert.h>

void FilingMatrix(int* matrix, int r, int c) {
    printf("Вводи элементы матрицы, мраз\n");
    printf("Введёшь криво - Я тебе пальчики секатором подровняю\n");

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            scanf("%d", ((matrix + i * r) + j));
    }
    printf("\n");
}

/*
bool TestFilingMatrix() {
    printf("Начало тестирования\nТестовые данные:\n10 10\n20 20\n");
    printf("Вводи тестовые данные 10 10 20 20\n");
    printf("Введёшь криво - Я тебе пальчики секатором подровняю\n");
    
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
*/

void Lab14() {
    //assert(TestFilingMatrix() != false);

    printf("Начало выполнения программы\n");
    printf("Введи колличество строк и столбцов, одним числом\n");

    int n = 0;
    scanf("%d", &n);

    int matrix[n][n];
    FilingMatrix(&matrix[0][0], n, n);

    printf("%d ", matrix[0][n - 1]);
    
    int iExternal = 0;
    int iInternal;
    int jExternal, jInternal;
    for (jExternal = n - 2; jExternal >= 0; --jExternal) {
        printf("%d ", matrix[iExternal][jExternal]);
        
        iInternal = iExternal + 1;
        for (jInternal = jExternal + 1; (jInternal < n) && (iInternal < n); ++jInternal) {
            printf("%d ", matrix[iInternal][jInternal]);
            ++iInternal;
        }
    }

    jExternal = 0;
    for (iExternal = 1; iExternal < n; ++iExternal) {
        printf("%d ", matrix[iExternal][jExternal]);
        
        if (iExternal != n - 1) {
            iInternal= iExternal + 1;
            for (jInternal = jExternal + 1; (jInternal < n) && (iInternal < n); ++jInternal) {
                printf("%d ", matrix[iInternal][jInternal]);
                
                ++iInternal;
            }
        }
    }
}

int main() {
    Lab14();

    return 0;
}
