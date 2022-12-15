#include <stdio.h>

#define I0 -22
#define J0 29
#define L0 4

int Sign(int x) {
    if (x > 0) {
        return 1;
    }
    if (x == 0) {
        return 0;
    }
    return -1;
}

int Min(int x, int y) {
    return (x < y) ? x : y;
}

int Max(int x, int y) {
    return (x > y) ? x : y;
}

int Module(int x) {
    return (x > 0) ? x : -x;
}

int Ik(int i, int j, int k, int l) {
    return(Sign(Min(i, k)) * Max((i + k) % 20, (j + l) % 20));
}

int Jk(int i, int j, int k, int l) {
    return(Module(Max(i, k)) - k * Min(j, l));
}

int Lk(int i, int j, int k, int l) {
    float a;
    int b;
    a = k - l;
    b = ((i + j + l) * (i + j + l)) % 5 + 1;
    return(a / b);
}

int Check(int x, int y) {
    return(((x + 10) * (x + 10) + (y + 10) * (y + 10) == 100) && ((x + 20) * (x + 20) + (y + 20) * (y + 20) == 100));
}

int main() {
    int k, hit, i, j, l;
    k = 0;   
    hit = 0;   
    i = I0;
    j = J0;
    l = L0;
    if (Check(i, j)) {
        hit = 1;
        k = 1;
    }
    else{
        for(k = 1; k <= 50; k++) {
            int iNext = Ik(i, j, k, l);
            int jNext = Jk(i, j, k, l);
            int lNext = Lk(i, j, k, l);
            i = iNext;
            j = jNext; 
            l = lNext;
            if (Check(iNext, jNext)) {
                hit = 1;
                break;
            }
        }
    }
    if (hit) {
            printf("Попадание на k = %d шаге\n", k);
    }
    else {
            printf("Промах k = %d, i = %d, j = %d, l = %d\n", k, i, j, l);
    }      
    return 0;
}

