#include <stdio.h>

int check_in_area(int i, int j){ 
    int i_center = 10;
    int j_center = 10; 
    
    int place = (i_center - i)*(i_center - i) + (j_center - j)*(j_center - j);

    return place > 25 && place <= 100;        
} 

int my_max(int num1, int num2){
    if(num1 >= num2)
        return num1;
    return num2;
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
    return my_max(j-k, l-k)%30 + my_max(i+l, j+k)%20;
}

int j_next(int i, int j, int k, int l){
    return (my_abs(i-l)*my_sign(j+k) + my_abs(i-k)*(j+k))%20;
}

int l_next(int i, int j, int k, int l){
    return (i+k)*(j-k)*(l+k)%25;
}

int laba9(int i, int j, int l){
    for(int k=0; k<=50; ++k){
        if(check_in_area(i, j)){
            printf("i = %d; j = %d; l = %d\nk = %d;\n", i, j, l, k);
            printf("You are in the area!\n");
            return 1;                
        }
        i = i_next(i, j, k, l);
        j = j_next(j, i, k, l);
        l = l_next(l, i, j, l);
    }
    printf("i = %d; j = %d; l = %d", i, j, l);
    printf("You are not in the area\n");
    return 0;
}

int main (void) {
    int i=-1, j=-1, l=-9;
    laba9(i, j, l);
    return 0;
}

