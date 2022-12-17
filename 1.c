#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int check_in_area(int i, int j){ 
    int i_center = 10;
    int j_center = 10; 
    double distance;
    distance = sqrt((i_center - i)*(i_center - i) + (j_center - j)*(j_center - j));
    if(distance > 5 && distance < 10)
        return 1;
    return 0;
} 

int my_max(int num1, int num2){
    if(num1 >= num2)
        return num1;
    return num2;
}

int my_min(int num1, int num2){
    if (num1 >= num2)
        return num2;
    return num1;
}


int my_sign(int num){
    if(num > 0)
        return 1; 

    if(num == 0)
        return 0; 

    return -1;  
}
int my_abs(int num){
    if(num>=0)
        return num;
    return -1*num;
}

int i_next(int i, int j, int k, int l){
    return my_max(my_min(i+j-l-k,i-j+l-k),my_min(k+i-j-l,k-i-j+l));
}

int j_next(int i, int j, int k, int l){
    return j + l*my_sign(j)%20 + k*my_sign(i)%10;
}

int l_next(int i, int j, int k, int l){
    return my_abs(i-j + l-k)*my_sign(i)*my_sign(j);
}

int laba9(int i, int j, int l){
    for(int k=0; k<=50; ++k){
        if(check_in_area(i, j)){
            printf("i = %d; j = %d; l = %d\nk = %d;\n", i, j, l, k);
            printf("Есть попадание!\n");
            return 1;                
        }
        i = i_next(i, j, k, l);
        j = j_next(j, i, k, l);
        l = l_next(l, i, j, l);
    }
    printf("i = %d; j = %d; l = %d", i, j, l);
    printf("Промазал...\n");
    return 0;
}

int main (void) {
    int i=1, j=-30, l=1;
    laba9(i, j, l);
    return 0;
}

