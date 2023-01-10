#include <stdio.h>

int main() {
    int c = 'a';
    int ans = 0;
    int fl = 0;
    
    while (1)
    {
        c = getchar();
        if ((c == ' ' || c == '\n') && fl == 1) {
            ans++;
        } else {
            if (c == 'I' || c == 'V' || c == 'X' || c == 'L' || c == 'C' || c == 'D' || c == 'M') {
                fl = 1;
            } else {
                fl = 0;
            }
        }

        if (c == EOF)
        {
            printf("%d\n", ans);
            break;
        }
    }

    return 0;
}


