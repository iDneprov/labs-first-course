#include <stdio.h>
#include <ctype.h>

#define STATUS_SEARCH_FIRST_NUM 0
#define STATUS_SAVE_VALUE_FIRST_NUM 1
#define STATUS_SEARCH_LAST_NUM 2
#define STATUS_SAVE_VALUE_LAST_NUM 3

void Lab11(void) {     
    char symb = 'a';
    char symbLast = 'b';

    int firstNum = 0;
    int lastNum = 0;
    int tmpLastNum = 0;

    int status = STATUS_SEARCH_FIRST_NUM;
    int statusMinus = 0;
    
    int i = 0;
    while (symb != EOF) {        
        symbLast = symb;
        symb = getchar();
        
        if (status == STATUS_SEARCH_FIRST_NUM || status == STATUS_SEARCH_LAST_NUM) {
            if ((i == 0 && isdigit(symb)) || (i == 0 && symb == '-') || (symbLast == ' ' && symb == '-') || symb == ' ' || (symbLast == ' ' && isdigit(symb))) {        
                if (symb == '-') {
                    statusMinus = 1;
                    //printf("\nstatusMinus = %d\n", statusMinus);
                    
                    if (status == STATUS_SEARCH_FIRST_NUM)
                        status = STATUS_SAVE_VALUE_FIRST_NUM;
                    
                    if (status == STATUS_SEARCH_LAST_NUM)
                        status = STATUS_SAVE_VALUE_LAST_NUM;

                    symb = getchar();
                    
                    //printf("\nstatus = %d\n", status);
                }

                if (isdigit(symb)) {
                    if (status == STATUS_SEARCH_FIRST_NUM)
                        status = STATUS_SAVE_VALUE_FIRST_NUM;
                    
                    if (status == STATUS_SEARCH_LAST_NUM)
                        status = STATUS_SAVE_VALUE_LAST_NUM;

                    if (status == STATUS_SAVE_VALUE_FIRST_NUM)
                        firstNum = symb - '0';
                    
                    //printf("\nstatus = %d\n", status);
                    
                    tmpLastNum = symb - '0';

                    symb = getchar();
                    //printf("tmpNumFirst = %d\n", tmpLastNum);
                }

                //if (symb == '-')
                    //statusMinus = 1;
            }
        }
        
        if (status == STATUS_SAVE_VALUE_FIRST_NUM || status == STATUS_SAVE_VALUE_LAST_NUM) {
            if (isdigit(symb)) {
                if (status == STATUS_SAVE_VALUE_FIRST_NUM)
                    firstNum = firstNum * 10 + (symb - '0');

                //printf("tmpNumNow = %d\n", tmpLastNum);    
                tmpLastNum = tmpLastNum * 10 + (symb - '0');
                //printf("tmpNumNow_late = %d\n", tmpLastNum);
            } else {
                //printf("in\n");
                //printf("tmplastNumEnd = %d\n", tmpLastNum);
                if (symb == EOF) {
                    lastNum = tmpLastNum;
                    
                    if (statusMinus == 1) {
                        //printf("in_minus\n");
                        if (status == STATUS_SAVE_VALUE_FIRST_NUM) 
                            firstNum = -1 * firstNum; 
                    
                        lastNum = -1 * lastNum;
                        //printf("lastNum_End = %d\n", lastNum);
                        statusMinus = 0;
                    }
                    
                    break;
                }

                if (symb != ' ') {
                    if (status == STATUS_SAVE_VALUE_FIRST_NUM) {
                        firstNum = 0;
                        status = STATUS_SEARCH_FIRST_NUM;
                    }
                    if (status == STATUS_SAVE_VALUE_LAST_NUM)
                        status = STATUS_SEARCH_LAST_NUM;

                    statusMinus = 0;
                }
            
                //printf("\n firstNum_End = %d\n", firstNum);
                //printf("lastNum_End = %d\n", lastNum);

                if (status == STATUS_SAVE_VALUE_FIRST_NUM || status == STATUS_SAVE_VALUE_LAST_NUM) {
                    //printf("tmplastNumEnd_leter = %d\n", tmpLastNum);
                    lastNum = tmpLastNum;
                    //printf("lastNumEnd = %d\n", lastNum);

                    if (statusMinus == 1) {
                        //printf("in_minus\n");
                        if (status == STATUS_SAVE_VALUE_FIRST_NUM) 
                            firstNum = -1 * firstNum; 
                    
                        lastNum = -1 * lastNum;
                        //printf("---lastNumEnd = %d\n", lastNum);
                        statusMinus = 0;
                    }
                    
                    status = STATUS_SEARCH_LAST_NUM;
                }
                
                tmpLastNum = 0;
                //printf("tmplastNumEnd_0 = %d\n", tmpLastNum);
                //printf("lastNumEnd_0 = %d\n", lastNum);
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
