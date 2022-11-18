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

    int statusFirst = 0;
    int statusMinus = 0;
    
    int i = 0;
    while (symb != EOF) {        
        //printf("\nsymb == %c\n", symb);
        
        if ((i == 1 && isdigit(symb)) || symb == '-' || symb == ' ' || (symbLast == ' ' && isdigit(symb))) {        
            //printf("\nsymb_if == %c\n", symb);
            if (isdigit(symb) || symb == '-') {
                if (statusFirst == 0) {
                    if (symb == '-')
                        ++statusMinus;
                    
                    if (isdigit(symb))
                        firstNum = symb - '0';
                    
                    symb = getchar();

                    while (true) {
                        //printf("\nsymb_in_first == %c\n", symb);
                        
                        if (isdigit(symb)) {    
                            firstNum = firstNum * 10 + (symb - '0');
                        } else {                         
                            //printf("\nsymb_first == %c\n", symb);
                            
                            if (symb == EOF) {
                                ++statusFirst;
                                break;
                            }
                            
                            if (symb != ' ') {
                                firstNum = 0;
                                break;
                            }
                            
                            ++statusFirst;
                            break;
                        }

                        symb = getchar();        
                    }
                    //printf("\nsymb_out_first == %c\n", symb);
                    
                    if (statusMinus == 1) {
                        firstNum = -1 * firstNum; 
                        statusMinus = 0;
                    }
                } else {
                    if (symb == '-')
                        ++statusMinus;
                    
                    if (isdigit(symb))
                        tmpLastNum = symb - '0';
                    
                    symb = getchar();
                    
                    while (true) {
                        //printf("\nsymb_in_last== %c\n", symb);
                        if (isdigit(symb)) { 
                            tmpLastNum = tmpLastNum * 10 + (symb - '0');
                        } else {
                            //printf("\nsymb_last == %c\n", symb);

                            if (symb == EOF) {
                                lastNum = tmpLastNum;
                                break;
                            }

                            if (symb != ' ') {
                                if (lastNum == 0)    
                                    lastNum = firstNum;
                                break;
                            }
                            
                            lastNum = tmpLastNum;
                            tmpLastNum = 0;
                                
                            break;
                        }

                        symb = getchar();
                    }                
                    //printf("\nsymb_out_last== %c\n", symb);
                    
                    if (statusMinus == 1) {
                        lastNum = -1 * lastNum; 
                        statusMinus = 0;            
                    }
                }
            }   
        }
        
        symbLast = symb;
        
        symb = getchar();
        
        ++i;
    }
    
    printf("\n%d\n", firstNum);
    printf("%d\n", lastNum);
}

int main(void) {
    
    Lab11();

    return 0;
}
