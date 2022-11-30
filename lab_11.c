#include <stdio.h>

int main(void) {
    char pres, prev;
    long long int c = 0;
    int flag = 1;
    long long int cnt = 0;
    int i;
    int m = 0;


    pres = getchar();
    c = c * 10 + (pres - '0');
    while (pres != EOF) {
        prev = pres;
        pres = getchar();

        if ((pres == '-') && (c == 0)) {
            m = 1;
            continue;
        }
        
        if ((pres != ' ') && (pres != ',') && (pres != '\n') && (pres != EOF) && (pres != '\t') && (pres != '\v')) {
            if ((prev == ' ') && (prev == ',') && (prev == '\n') && (prev == '\t') && (prev == '\v') && (prev == '-')) {
                c = c * 10 + (pres - '0');
                continue;
            }
            if ((pres - '0' < 0) || ((pres - '0' > 9) && (pres != 'A'))) {
                flag = 0;
            }
            if (pres == 'A') {
                ++cnt;
            } else if (pres >= prev) {
                c = c * 10 + (pres - '0');
            } else {
                flag = 0;
            }
        } else if ((prev == ' ') || (prev == ',') || (prev == '\n') || (prev == '\t') || (prev == '\v') || (prev == '-')) {
            continue;
        } else {
            if (flag == 1) {
                if (m == 1) {
                    printf("-");
                    m = 0;
                }
                if (((c != 0) && (cnt != 0)) || (cnt == 0)) {
                    printf("%lld", c);
                };
                for (i = 1; i <= cnt; ++i) {
                    printf("A");
                };
                if (pres != EOF) {
                    printf("%c", pres);
                };
                c = 0;
                cnt = 0;
            } else {
                flag = 1;
                c = 0;
                cnt = 0;
            }
        }
    }

    return 0;

}
