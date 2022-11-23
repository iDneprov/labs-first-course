#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_N 4

void FilingMassiv(int** mass, int r, int c) {
    //int valu = 0;

    printf("Вводи элементы матрицы, мраз\n");
    printf("Введёшь криво - тобi пiзда\n");

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            scanf("%d", &mass[i][j]);
    }
    printf("\n");
}

bool TestFilingMassiv() {
    printf("Начало тестирования\nТестовые данные 10 10 20 20\n");
    
    int checkMas[2][2] = {10, 10, 20, 20};

    int tmpMatrixArray[2][2];
    int *testMatrix[2];
    for (int i = 0; i < 2; i++) {
        testMatrix[i] = &tmpMatrixArray[i][0];
    }
    FilingMassiv(testMatrix, 2, 2);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (testMatrix[i][j] != checkMas[i][j])
                return false;
        }
    }
    printf("Всё ок, не ссы, продолжаем\n\n");

    return true;
}

void Lab14() {
    assert(TestFilingMassiv() != false);

    printf("Начало выполнения программы\n");
    
    int massivArray[MAX_N][MAX_N];
    int *massiv[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        massiv[i] = &massivArray[i][0];
    }
    FilingMassiv(massiv, MAX_N, MAX_N);   
        
    for (int j = 0; j < MAX_N; ++j) 
        printf("%d ", massiv[0][j]);
    printf("\n");

    for (int i = 1; i < MAX_N; ++i) 
        printf("%d ", massiv[i][MAX_N - 1]);
    printf("\n");

    for (int j = MAX_N - 2; j >= 0; --j)
        printf("%d ", massiv[MAX_N - 1][j]);    
    printf("\n");

    for (int i = MAX_N - 2; i >= 1; --i)
        printf("%d ", massiv[i][0]);    
    printf("\n");

    for (int j = 1; j < MAX_N - 2; ++j) 
        printf("%d ", massiv[1][j]);
    printf("\n");

    for (int i = 1; i < (MAX_N - 1); ++i)
        printf("%d ", massiv[i][MAX_N - 2]);
    printf("\n");
    
    if (MAX_N > 3) {
        printf("%d ", massiv[MAX_N - 2][1]);    
        printf("\n");
    }
}




int main() {
    Lab14();

    return 0;
}
