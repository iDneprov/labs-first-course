#include <stdio.h>

int Min(int x,int y){
    return x > y ? y : x;
}

int Max(int x,int y){
    return x > y ? x : y;
}

int Mod(int x,int y){
    return x*y < 0 ? x - ((x/y) - 1)*y : x - (x/y) * y;
}   

int Abs(int x){
    return x >= 0 ? x : -x;
}

int iNext(int i , int k, int l, int j){
    return  Abs(k) - Min(i/3,Mod((j+l),10)) - 20;
}

int jNext(int i, int k, int l, int j){
    return ((-(j+k))/5) + Abs(Mod((i*l),8));
}

int lNext(int i, int k, int j,int l){
    return Max(Mod((i+j),15),Mod((l+k),14));
}

int Checker(int i, int j){
    if(((i >= 5) && (i <=15)) && ((j <= -5)&&(j >= -15))){
        return 1;
    }
    return 0;
}

int PrevMain(){
    int i = 11;
    int j = 13;
    int l = 10;
    for(int k = 1; k < 500; ++k){
        int x = i;
        int y = j;
        int z = l;
        if(Checker(i,j)){
            return k;
        }
        else{
            i = iNext(x,y,z,k);
            j = jNext(x,y,z,k);
            l = lNext(x,y,z,k); 
        }
    }
    return 0;
}

int main(void){
    int ans = PrevMain();
    if(ans == 0){
        printf("We are not in the square :( \n");
    }
    else{
        printf("We hit in the square for k = %d \n", ans);
    }
    return 0;   // Если увеличить кол-во итерация, то точка попадает за  = 126
}