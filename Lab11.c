#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

void Lab11(void) {     
    char symb = 'a';
    char symbLast = 'b';

    int firstNum = 0;
    int lastNum = 0;
    int tmpLastNum = 0;

    int status = 0;
    int statusMinus = 0;
    
    int i = 0;
    while (symb != EOF) {        
        symbLast = symb;
        symb = getchar();
        
        if (status == 0 || status == 2) {
            if ((i == 0 && isdigit(symb)) || symb == '-' || symb == ' ' || (symbLast == ' ' && isdigit(symb))) {        
                if (status == 0)
                    status = 1;
                if (status == 2)
                    status = 3;
                //printf("\nstatus = %d\n", status);
                
                if (symb == '-')
                    statusMinus = 1;

                if (isdigit(symb)) {
                    if (status == 1)
                        firstNum = symb - '0';
                    
                    tmpLastNum = symb - '0';
                    //printf("tmpNumFirst = %d\n", tmpLastNum);
                }

                symb = getchar();
            }
        }
        
        if (status == 1 || status == 3) {
            if (isdigit(symb)) {
                if (status == 1)
                    firstNum = firstNum * 10 + (symb - '0');

                printf("tmpNumNow = %d\n", tmpLastNum);    
                tmpLastNum = tmpLastNum * 10 + (symb - '0');
                printf("tmpNumNow_late = %d\n", tmpLastNum);
            } else {
                //printf("in\n");
                //printf("tmplastNumEnd = %d\n", tmpLastNum);
                if (symb == EOF) {
                    lastNum = tmpLastNum;
                    
                    if (statusMinus == 1) {
                        if (status == 1) 
                            firstNum = -1 * firstNum; 
                    
                        lastNum = -1 * lastNum;

                        statusMinus = 0;
                    }
                    
                    break;
                }

                if (symb != ' ') {
                    if (status == 1) {
                        firstNum = 0;
                        status = 0;
                    }
                    if (status == 3)
                        status = 2;

                    statusMinus = 0;
                }
            
                //printf("\n firstNum_End = %d\n", firstNum);
                //printf("lastNum_End = %d\n", lastNum);

                if (status == 1 || status == 3) {
                    //printf("tmplastNumEnd_leter = %d\n", tmpLastNum);
                    lastNum = tmpLastNum;
                    //printf("lastNumEnd = %d\n", lastNum);
                    
                    status = 2;
                }
                
                tmpLastNum = 0;
                //printf("tmplastNumEnd_0 = %d\n", tmpLastNum);
                //printf("lastNumEnd_0 = %d\n", lastNum);


                if (statusMinus == 1) {
                    if (status == 1) 
                        firstNum = -1 * firstNum; 
                    
                    lastNum = -1 * lastNum;

                    statusMinus = 0;
                }
                //printf("\n firstNum = %d\n", firstNum);
                //printf("lasttNum = %d\n", lastNum);
            }   
        }
        
        ++i;
    } 
    
    printf("\n%d\n", firstNum);
    printf("%d\n", lastNum);
}

int main(void) {
    
    Lab11();

    return 0;
}
