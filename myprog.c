#include <stdio.h> 
#include "stdnepbool.h"
#include <stdlib.h>
#include <math.h> 
#define eps 1e-10 


bool check_in_area(int i_point, int j_point)
{
    if ((i_point + j_point + 10 <= 0) && (i_point + j_point + 20 >= 0)) 
    {
        return true;
    } 
    else
        return false;
}
int testCheck_in_area() 
{
    if(check_in_area(10, 10))
        return false;    

    return true;
}

int max_1(int num1, int num2) 
{
    if(num1 >= num2)
    {
        return num1; 
    }
    else
        return num2;
}

int min(int num1, int num2) 
{
    if(num1 <= num2)
    {
        return num1; 
    }
    else
        return num2;
}


int max(int num1, int num2, int num3) 
{
    if(num1 >= num2 && num1 >= num3)             
        return num1;
    
    if(num2 >= num1 && num2 >= num3)
        return num2;
             
    return num3;
}

int abs(int a)
{
    if (a >= 0)
        return a;
    else
        return -a;
}



int i_increase(int i, int j, int k, int l)
{
    return (i * j / (abs(l) + 1) + j * l / (abs(i) + 1) + i * l / (abs(j) + 1)) % 30;
}
int test_i_increase()
{
    
    return true;
}

int j_increase(int j, int i, int k, int l)
{
    return (i * max_1(j, l) % 20 + j * min(i, l) % 30 - k);

}

int l_increase(int l, int i, int j)
{
    return max(i*j, i*l, j*l) % 30 + 20;
}




int lab9(int i, int j, int l)
{
      
        int k = 0;
        while(k <= 50)
        {
            if(check_in_area(i, j))
            {
                printf("i = %d; j = %d; l = %d\nk = %d;\n", i, j, l, k);
                printf("Popal\n");
                return 1;                
            }
            
            printf("i = %d j = %d l = %d\n", i, j, l);

            i = i_increase(i, j, k, l);
            j = j_increase(j, i, k, l);
            l = l_increase(l, i, j);
            
            k++;
        }

        printf("i = %d; j = %d; l = %d\nk = %d;\n", i, j, l, k);
        printf("NE Popal\n");
        return 0;
    
    
    
}


int main()
{   
    int i = 12;
    int j =  4;
    int l = 3;
    
    lab9(i, j, l);

    return 0;
}