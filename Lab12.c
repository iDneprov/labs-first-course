//#include "T2.h"
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

int len_num(int num) {
    int len = 0;
    while(num >= 1) {
        num = num / 2;

        ++len;    
    }

    return len;
}

bool test_len_num(void) {
    if (len_num(2) != 2)
        return false;
    
    if (len_num(5) != 3)
        return false;

    return true;
}

void massiv_init(int massiv[], int n, double d)
{
  assert(massiv != 0);
  
  for (int i = 0; i < n; i++)
  {
    assert(i < n);
    
    massiv[i] = d*i;
  }
}

void Lab12(int num) {
    assert(num >= 0);
    
    if (test_len_num()) {
        int len = len_num(num);
        
        int result[len];
        massiv_init(result, len, 0);

        int tmp_mas[len];
        massiv_init(tmp_mas, len, 0);

        int i_external = 0;
        while (true) {
            if (num == 0) {
                int j = len - 1; 

                for(int i_interior = 0; i_interior < len; ++i_interior) {
                    result[i_interior] = tmp_mas[j];

                    //printf("tmp_mas[%d] = %d\n", j, tmp_mas[j]);
                    //printf("result[%d] = %d\n", i_interior, result[i_interior]);
                    
                    --j;
                }
                
                break;
            }
        
            tmp_mas[i_external] = num % 2;
            num = num / 2;

            //printf("num = %d\n", num);
            //printf("tmp_mas[%d] = %d\n", i_external, tmp_mas[i_external]);
            
            ++i_external;      
        }
    
        
        for (int i = 0; i < len; ++i) {
            printf("%d", result[i]);
        }    
        printf("\n");
    }
    else
        printf("Жопа");
}

int main(void) {    
    Lab12(2);
    Lab12(5);
    Lab12(100);
    //Lab12(-2);
    
    return 0;
}
