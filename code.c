#include <stdio.h>

int Abs(int a){
    if (a >= 0){
        return a;
    }
    return(-a);
}

int Max(int a, int b){
    if (a>=b){
        return(a);
    }
    return(b);
}

int Min(int a, int b){
    if (a<=b){
        return(a);
    }
    return(b);
}

int Step2(int a){
    return (a*a);
}

int Step3(int a){
    return (a*a*a);
}

int X (int x, int y, int l, int i){
    return(Abs(Max(Min(x+y, x+l)%30, Max(x+l, y+i)%25)));
}

int Y (int x, int y, int l, int i){
    return(Abs(x+i)%10 + Abs(x+i)%10 + Abs(l+i)%10);
}

int L (int x, int y, int l, int i){
    return((Step3(x) + Step3(y) + Step3(l)-i)%35);
}
int UE(int x, int y){ // UE = uravnenie elipsa
    return( ( Step2(x-20) / 100 ) + Step2(y) / 25 );
}
int main(){
    int x, y, l, x1, y1, l1, f, i;
    x = -10;
    y = -10;
    l = 6;
    f = 1;
    i = 0;
    while(f == 1) {
        x1 = X(x, y, l, i);
        y1 = Y(x, y, l, i);
        l1 = L(x, y, l, i);
        x = x1;
        y = y1;
        l = l1;
        if (UE(x, y)<=1){
            f = 0;
            printf("popal, step %d, coord: x=%d, y=%d", i, x, y);
        }
        ++i;
        if (i == 51){
            f = 0;
            printf("mimo");
        }
    }
    return 0;
}