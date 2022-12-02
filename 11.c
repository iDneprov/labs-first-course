#include <stdio.h>
int main()
{
    long INT_MAX = 2147483647;
    int sost=0,c;
    long n;

    while(sost != 3){
        c = getchar();
        switch(sost){
            case 0:
                if ((c != ' ' && c != '\t' && c != ',' && c != '.') && c >= '0' && c <= '9'){n = (int)(c-'0'); sost = 1;}
                else if(c == '-'){sost = 2;}
                if(c == EOF){sost = 3;}
                break;
            case 1:
                if((c != ' ' && c != '\t' && c != ','&& c != '.') && c >= '0' && c <= '9'){n = n * 10 + (int)(c-'0');}
                else{if(n > INT_MAX){printf("%ld\n", n);}n = 0;sost = 0;}
                break;
            case 2:
                if((c != ' ' && c != '\t' && c != ','&& c != '.') && c >= '0' && c <= '9'){n = n * 10 + (int)(c-'0');}
                else{if(n > INT_MAX + 1){printf("%ld\n", -n);}n = 0;sost = 0;}
                break;
        }
    }
    return 0;
}

