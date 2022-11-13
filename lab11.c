// 18 вариант
#include <stdio.h>

int Check(char a) {
    int i;
    char q;
    for (i = 0; i <= 9; ++i) {
        q = i + '0';
        if (a == q)
            return i;   
    }
    if (a == '.') 
        return 10;
    return -1;
}

double Pow(int k) {
    int i;
    double s = 1;
    for (i = 0; i < k; ++i) 
        s = s / 10;  
    return s;
}

void Fahrenheit(double s) {
    s = s * 9 / 5 + 32;
    printf("%g", s);
    printf("F");
}

int main() {
    short int bool1 = 0, bool2 = 0, printCheck = 0, arithmeticSign = 0, zerro = 0;
    char a, previous = ' ';
    int i, symbol, k = 0, k0 = 0;
    double s = 0;

    while (1) {
        a = getchar ();
        if (zerro) { 
            if (a != 'C') {
                if (a != '.') {
                    if (arithmeticSign)
                        putchar('-'); 
                    putchar('0');
                    if (a != EOF) {
                        putchar(a);
                        previous = a;
                        if (previous == '\n')
                            previous = ' ';
                    }
                    arithmeticSign = printCheck = bool1 = bool2 = s = k = 0;
                } else {
                    bool1 = 1;
                    bool2 = 1;
                    previous = a;
                }
            } else {
                if (arithmeticSign) {
                    putchar('-');
                    putchar('0');
                    putchar('C');
                    arithmeticSign = printCheck = bool1 = bool2 = s = k = 0;
                    previous = a;
                } else
                    printCheck = 1;
            }
            zerro = 0;
            continue;
        } 

        if (a == EOF) {
            if (printCheck) {
                if (arithmeticSign) {
                    Fahrenheit(-s);
                } else
                    Fahrenheit(s);
            } else {
                if (!bool1) {
                    if (arithmeticSign) {
                        putchar('-');
                        arithmeticSign = 0;
                    }         
                } 
                if (bool1) { 
                    if (!arithmeticSign) {
                        printf("%g", s);
                    } else 
                        printf("%g", -s);
                    if(previous == '.')
                        putchar('.');
                    if (k0 != 0) {
                        if (bool2) 
                            putchar('.');                        
                        for (i = 0; i < k0; ++i)
                            putchar('0');
                    }  
                }
            }                
            break;
        }

        if (a == '-' && previous == ' ') {
            if (!arithmeticSign) {
                arithmeticSign = 1;
                continue;
            } else 
                previous = a;  
        }

        if (printCheck && (a == ' ' || a == '\n')) {
            if (arithmeticSign) {
                Fahrenheit(-s);
            } else
                Fahrenheit(s);
            putchar(a);
            previous = a;
            if (previous == '\n') {
                previous = ' ';
            }
            arithmeticSign = printCheck = bool1 = bool2 = s = k = 0;
            continue;
        } 

        if (printCheck) {
            if (!arithmeticSign) {
                printf("%g", s);
            } else 
                printf("%g", -s);                
            putchar('C');
            putchar(a);
            previous = a;
            printCheck = arithmeticSign = bool1 = bool2 = s = k = 0;
            continue;
        }
             
        symbol = Check (a);

        if (symbol == -1) {
            if (!bool1) {
                if (arithmeticSign) {
                    putchar('-');
                    arithmeticSign = 0;
                }
                putchar(a);
                previous = a;
                if (previous == '\n') 
                    previous = ' ';            
                continue;
            } 
            if (bool1) {
                if (a == 'C' && k0 == 0 && previous != '.') {
                    printCheck = 1;                    
                } else {
                    if (!arithmeticSign) {
                        printf("%g", s);
                    } else {
                        printf("%g", -s);
                    }       
                    if(previous == '.')
                        putchar('.');
                    if (k0 != 0) {
                        if (bool2) {
                            putchar('.');
                        }
                        for (i = 0; i < k0; ++i)
                            putchar('0');
                        k0 = 0;
                    }
                    putchar(a);
                    previous = a;
                    if ( previous == '\n') 
                        previous = ' ';               
                    arithmeticSign = 0;
                    bool1 = bool2 = s = k = 0;
                }
            }
        
        } else {
            if (previous == ' ' && symbol != 10)
                bool1 = 1;

            if (symbol == 0 && s == 0 && previous == ' ') {
                zerro = 1;
                previous = '0';
                continue;
            }

            if (!bool1) {
                if(arithmeticSign) {
                    putchar('-');
                    arithmeticSign = 0;
                }
                putchar(a);
            } 
            if (bool1) {
                if (symbol != 10) {
                    if (bool2 == 0) {
                        s *= 10;
                        s += symbol;
                    } else {
                        if (a == '0') {
                            ++k0;
                        } else  
                            k0 = 0;     
                        ++k;
                        s += symbol * Pow(k);
                    }
                } else {
                    if (bool2) {
                        if (arithmeticSign == 1) {
                            putchar('-');
                            arithmeticSign = 0;
                        }
                        printf("%g", s);
                        if (previous == '.')
                            putchar('.');
                        if (k0 != 0) {
                            putchar('.');
                            for (i = 0; i < k0; ++i) 
                                putchar('0');
                            k0 = 0;
                        }
                        putchar(a);
                        bool1 = bool2 = s = k = 0;
                        previous = a;
                        if (previous == '\n') {
                            previous = ' ';
                        }
                        continue;
                    }
                    bool2 = 1;
                }
            }
        }
        previous = a;
        if (previous == '\n') 
            previous = ' ';
    }
    return 0;
}
