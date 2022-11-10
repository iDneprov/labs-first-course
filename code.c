#include <stdio.h>

#define START_I -11
#define START_J -6
#define START_L -5

int FindNewI(int i,int j, int l,int k) {
    newI = (i + j + l) * (k + 1) % 25 - (i * j * l * (k + 2) % 10) + 10;
    return newI;
}

int FindNewJ(int i,int j, int l,int k) {
    newJ = (((i + j + l) * (k + 3) % 25) * (((i + j + l) * (k + 3) % 25) >= (i * j * l * (k + 4) % 25))) +
        (i * j * l * (k + 4) % 25) * ((i * j * l * (k + 4) % 25) > ((i + j + l) * (k + 3) % 25)) + 10;
    return newJ;
}

int FindNewL(int i,int j, int l,int k) {
    newL = 2*((l > 0) - (l < 0)) * ((((i + j + l) * (k + 5) % 10) > (i * j * l * (k + 6) % 25))-
        (((i + j + l) * (k + 5) % 10) < (i * j * l * (k + 6) % 25)))*((i + j + l) * (k + 5) % 10 - i * j * l * (k + 6) % 25);
    return newL;
}


int main(void) {
    int i,j,l,k = 1,flag = 0;
    i = START_I;
    j = START_J;
    l = START_L;
    for (; k < 50; ++k) {
        newI = FindNewI(i,j,l,k);
        newJ = FindNewJ(i,j,l,k);
        newL = FindNewL(i,j,l,k);
        if ((new_i >= 5) && (new_i <= 15) && (new_j <= -5) && (new_j >= -15)) {
            flag = 1;
            printf("Number of iterations%d\n",k);
            printf("Coordinates of the end of the movement %d %d , motion parameter %d\n",i,j,l );
            break;



        }
        i = newI;
        j = newJ;
        l = newL;
    }
    if (flag == 0) {
        printf("Lost in Saratov\n");
        printf("Coordinates of the end of the movement %d %d , motion parameter %d\n",i,j,l );
    }
    return 0;
}
