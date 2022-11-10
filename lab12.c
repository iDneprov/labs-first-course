// 18 вариант
#include <stdio.h>

int Check (char a){
    int i;
    char q;

    for(i=0; i<=9; ++i){
        q = i+'0';
        if(a == q)
        return i;
    }
    return -1;
}
long long Pow(int k){
    long long s = 1;
    int i;
    for(i = 0; i < k; ++i){
        s*=10;
    }
    return s;
}
int main() {
    int buf;
    int a1, a2, an1, an2;
    char a;
    int k = 0;
    long long s = 0;
    while(1){

    a = getchar();

    if(a == EOF)
    break;

    if(Check(a) == -1){
        if(k >= 4){
        s-= (an1 * Pow(k-4) + an2 * Pow(k-3));
        printf ("%d", a1);
        printf ("%d", an1);
        if(s!=0) printf ("%lld", s);
        printf ("%d", a2);
        printf ("%d\n", an2);
        }
        if(k == 3){
             printf ("%d", a1);
             printf ("%d", a2);
             printf ("%d\n", an2);
        }
        if(k == 2){
             printf ("%d", a2);
             printf ("%d\n", a1);
        }
        s = 0;
        k = 0;
        continue;
        
    } else{
        ++k;
    }

    if(k == 1){
    a1 = Check(a);
    an1 = Check(a);
    }

    if(k == 2){
    a2 = Check(a);
    an2 = Check(a);
    }

    if(k >= 3){
        buf = an2;
        an2 = Check(a);
        an1 = buf;
        s+= Check(a) * Pow (k-3);
    }

    }
    return 0;
}
