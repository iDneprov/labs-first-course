#include <stdio.h>
#include <locale.h>

#define MAXN 8

int main() {
    int n;
    int Arr[MAXN][MAXN];
    int Help[MAXN][MAXN];
    
    printf("Введите размерность матрицы: ");
    scanf("%d", &n);
    printf("Введите элементы массива.\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &Arr[i][j]);
            Help[i][j] = 1;
        }
    }

    for (int i = 1; i <= n;++i) {
        for (int j = i - 1; j > -1; --j ){
            for (int p = 0; p < n; ++p) {
                if (Arr[i][p] == Arr[j][p]) {
                    Help[j][p] = 0;
                } else {
                    for (int k = p - 1; k >= 0; --k) {
                        Help[j][k] = 1;
                    }
                    break;
                }
            }
        }
    }
    printf("Полученный вид матрицы.\n");
    for (int i = 0; i < n;++i) {
        if (Help[i][0] == 0) continue;
        for (int j = 0; j < n;++j) {
            printf("%d ",Arr[i][j]);
        }
        printf("\n");
    }
}

