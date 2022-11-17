//18 вариант
#include <stdio.h>

long long Pow(short int k) {
    long long s = 1;
    int i;
    for (i = 0; i < k; ++i) 
        s *= 10;
    return s;
}

void ResultСalculate(long long sum, short int k) {
    long long a, b;
    if (k >= 3) {
        b = sum / Pow(k - 2);
        b = b % 10;    
        sum -= b * Pow(k - 2);     
        a = sum / 100;
        a = a % 10;     
        sum += (b - a) * 100;
        sum += a * Pow(k - 2);
        printf("%lld", sum);
    } else
        printf("%lld", sum);    
}

int main() {
    short int a, k = 0, bool1 = 0;
    long long sum = 0;
    while (1) {
        a = getchar(); 
        if (a == '-') {
            putchar('-');
            bool1 = 0;
            continue;
        }
        if (a == '\n' || a == ' ' || a == EOF) {
            if (bool1) {
                ResultСalculate(sum, k);
                bool1 = 0;
            }
            sum = 0;
            k = 0;
            if (a == '\n')
                putchar('\n');
            if (a == ' ')
                putchar(' ');
            if (a == EOF)
                break;      
            continue;  
        } else {
            bool1 = 1;
            ++k;
            sum *= 10;
            sum += (a - '0');
        }
    }
    return 0;
}
