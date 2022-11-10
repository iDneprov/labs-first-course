// 18 вариант
#include <stdio.h>

int Check (char a){
    int i;
    char q;

    for(i=0;i<=9;i++){
        q=i+'0';
        if(a==q){
            return i;
        }
    }

    if(a=='.'){
        return 10;
    }

    return -1;
}

void Nepoluchilos(short int *a, short int *b, double *c, int *d){
    *a=0; 
    *b=0;
    *c=0;
    *d=0;
}

double Pow(int k){
    int i;

    double s=1;

    for(i=0;i<k;i++){
        s=s/10;
    }

    return s;
}

void Fahrenheit (double s){

    s= s * 9 / 5 + 32;

    printf("%g",s);
    printf("F");

}

int main() {
    short int Bool_1=0, Bool_2=0;
    char a;
    int figure;
    int k=0;
    double s=0;

    while(1){

    a = getchar();

    if(a==EOF){
    break;
    }

    figure=Check(a);

    if(figure==-1){

        if(Bool_1==0){

            putchar(a);

        } 

        if(Bool_1==1){
            if(a=='C')

              Fahrenheit (s);

             Nepoluchilos( &Bool_1, &Bool_2, &s, &k);

        }
        

    } else{

        Bool_1=1;

        if(figure!=10){


            if(Bool_2==0){
            s*=10;
            s+=figure;
            } 
            
            else{

                 ++k;
            s+=figure*Pow(k);

            }

        } 
        
        else{
            if(Bool_2==1){

                Nepoluchilos( &Bool_1, &Bool_2, &s, &k);

                continue;
            }

            Bool_2=1;

            ++k;
            s+=figure*Pow(k);

        }

    }

    }
    return 0;
}
