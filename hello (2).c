#include <stdio.h>
#define I_CENTER 10
#define J_CENTER 10
#define I -1
#define J -1
#define L -9

int CheckInArea(int i, int j) {
    int place = (I_CENTER - i) * (I_CENTER - i) + (J_CENTER - j) * (J_CENTER - j);
    return place > 25 && place <= 100;        
} 

int Max(int num1, int num2) {
    if (num1 >= num2)
        return num1;
    return num2;
}

int Sign(int num) {
    if (num > 0)
        return 1; 
    if (num == 0)
        return 0; 
    return -1;  
}

int Abs(int num) {
    if (num >= 0)
        return num;
    return -1*num;
}

int Inext(int i, int j, int k, int l) {
    return Max(j-k, l-k) % 30 + Max(i+l, j+k) % 20;
}

int Jnext(int i, int j, int k, int l) {
    return (Abs(i-l) * Sign(j+k) + Abs(i-k) * (j+k)) % 20;
}

int Lnext(int i, int j, int k, int l) {
    return (i+k) * (j-k) * (l+k) % 25;
}

int Laba9(int i, int j, int l) {
    for (int k = 0; k <= 50; ++k) {
        if (CheckInArea(i, j)) {
            printf("i = %d; j = %d; l = %d\nk = %d;\n", i, j, l, k);
            printf("You are in the area!\n");
            return 1;                
        }
        i = Inext(i, j, k, l);
        j = Jnext(j, i, k, l);
        l = Lnext(l, i, j, l);
    }
    printf("i = %d; j = %d; l = %d", i, j, l);
    printf("You are not in the area\n");
    return 0;
}

int main(void) {
    Laba9(I, J, L);
    return 0;
}

