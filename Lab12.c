#include "T2.h"

int LenNum(int num) {
    int len = 0;
    while (num >= 1) {
        num = num / 2;

        ++len;    
    }

    return len;
}

bool TestLenNum(void) {
    if (LenNum(2) != 2)
        return false;
    
    if (LenNum(5) != 3)
        return false;

    return true;
}

void Lab12(int num) {
    assert(num >= 0);
    
    if (TestLenNum()) {
        int len = LenNum(num);
        
        int result[len];
        MassivInit(result, len, 0);

        int tmpMas[len];
        MassivInit(tmpMas, len, 0);

        int iExternal = 0;
        while (true) {
            if (num == 0) {
                int j = len - 1; 

                for(int iInterior = 0; iInterior < len; ++iInterior) {
                    result[iInterior] = tmpMas[j];

                    //printf("tmpMas[%d] = %d\n", j, tmpMas[j]);
                    //printf("result[%d] = %d\n", iInterior, result[iInterior]);
                    
                    --j;
                }
                
                break;
            }
        
            tmpMas[iExternal] = num % 2;
            num = num / 2;

            //printf("num = %d\n", num);
            //printf("tmpMas[%d] = %d\n", iExternal, tmpMas[iExternal]);
            
            ++iExternal;      
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
