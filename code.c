#include <stdio.h>

#define i_0 -11
#define j_0 -6
#define l_0 -5

int FindNewI(int i,int j, int l,int k) {
    new_i = (i + j + l) * (k + 1) % 25 - (i * j * l * (k + 2) % 10) + 10;
    return new_i;
}

int FindNewJ(int i,int j, int l,int k) {
    new_j = (((i + j + l) * (k + 3) % 25) * (((i + j + l) * (k + 3) % 25) >= (i * j * l * (k + 4) % 25))) +
        (i * j * l * (k + 4) % 25) * ((i * j * l * (k + 4) % 25) > ((i + j + l) * (k + 3) % 25)) + 10;
    return new_j;
}

int FindNewL(int i,int j, int l,int k) {
    new_l = 2*((l > 0) - (l < 0)) * ((((i + j + l) * (k + 5) % 10) > (i * j * l * (k + 6) % 25))-
        (((i + j + l) * (k + 5) % 10) < (i * j * l * (k + 6) % 25)))*((i + j + l) * (k + 5) % 10 - i * j * l * (k + 6) % 25);
    return new_l;
}


int main(void) {
    int i,j,l,k = 1,flag = 0;
    i = i_0;
    j = j_0;
    l = l_0;
    for (; k < 50; ++k) {
        new_i = FindNewI(i,j,l,k);
        new_j = FindNewJ(i,j,l,k);
        new_l = FindNewL(i,j,l,k);
        if ((new_i >= 5) && (new_i <= 15) && (new_j <= -5) && (new_j >= -15)) {
            flag = 1;
            printf("Number of iterations%d\n",k);
            printf("Coordinates of the end of the movement %d %d , motion parameter %d\n",i,j,l );
            break;
        }
        i = new_i;
        j = new_j;
        l = new_l;
    }
    if (flag == 0) {
        printf("Lost in Saratov\n");
        printf("Coordinates of the end of the movement %d %d , motion parameter %d\n",i,j,l );
    }
    return 0;
}
