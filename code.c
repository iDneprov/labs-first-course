#include <stdio.h>

#define i_0 -11
#define j_0 -6
#define l_0 -5

int Find_New_Coor(int *i,int *j, int *l,int *k){
    int a,b,c,d;
    a = *i;
    b = *j;
    c = *l;
    d = *k;
    *i = (a+b+c)*(d+1)%25 - a*b*c*(d+2)%10 + 10;
    *j = (((a+b+c)*(d+3)%25)*(((a+b+c)*(d+3)%25)>=(a*b*c*(d+4)%25)))+(a*b*c*(d+4)%25)*((a*b*c*(d+4)%25)>((a+b+c)*(d+3)%25))+10;
    *l = 2*((c>0)-(c<0))*((((a+b+c)*(d+5)%10) > (a*b*c*(d+6)%25))-(((a+b+c)*(d+5)%10) < (a*b*c*(d+6)%25)))*((a+b+c)*(d+5)%10 - a*b*c*(d+6)%25);
    /*if (((a+b+c)*(d+5)%10 - a*b*c*(d+6)%25) == 0){
        printf("On my way to Saratov\n");
    }*/
    return 0;
}

int main(void){
    int i,j,l,k = 0,flag = 0;
    i = i_0;
    j = j_0;
    l = l_0;
    while (k < 50){
        k++;
        Find_New_Coor(&i,&j,&l,&k);
        printf("%d %d %d %d\n",i,j,k,l);
        if ((i>=5) && (i<=15) && (j<=-5) && (j>=-15)){
            flag = 1;
            printf("Number of iterations%d\n",k);
            printf("Coordinates of the end of the movement %d %d , motion parameter %d\n",i,j,l );
            break;
        }
    }
    if (flag == 0) {
        printf("Lost in Saratov\n");
        printf("Coordinates of the end of the movement %d %d , motion parameter %d\n",i,j,l );
    }
    return 0;
}
