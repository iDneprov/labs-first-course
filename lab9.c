#include <stdio.h>

int max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}

int min(int a, int b){
    if (a > b){
        return b;
    }
    return a;
}

int NextI(int i, int j, int l, int k){
    return (i * min(j, l) + j * min(i, l) + k * k) % 20;
}

int NextJ(int i, int j, int l, int k){
    return ((i % 10 + k) * (j % 10 + k) * (l % 10 - k) % 25);
}

int NextL(int i, int j, int l, int k){
    return (max(min(i + j, i + l) % 25, max(i + l, j + k) % 20) + 10);
}

int CheckInTheArea(int i, int j){
    if (i + j + 10 <= 0 && i + j + 20 >= 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void){
    int i0 = -22, j0 = 14, l0 = -14, k;
    int inArea = 0;
    for (k = 0; k <= 50; ++k){
        int i = NextI(i0, j0, l0, k);
        int j = NextJ(i0, j0, l0, k);
        int l = NextL(i0, j0, l0, k);
        i0 = i, j0 = j, l0 = l;
        if (CheckInTheArea (i, j)){
            inArea = 1;
            break;
        }
    }
    if (inArea){
        printf("Попадание на шаге %d\n", k);
    }
    else {
        printf("Промах: k = %d, i = %d, j = %d, l = %d\n", k, i0, j0, l0);
    }
    return 0;
}
