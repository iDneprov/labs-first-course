#include <stdio.h>

#define MAX_N 7

int main(void) {
  int mas[MAX_N][MAX_N];
  int dir[4] = {0, 1, 0, -1};
  int n;

  scanf("%i",&n);

  for (int i = 0; i != n; ++i) {
    for (int j = 0; j != n; ++j) {
        scanf("%d", &mas[i][j]);
    }
  }

  int l = n, p = 0, i = 0, j = n;
  while (l != 0) {
    for (int k = 0; k != l; ++k) {
          i += dir[p % 4];
          j += dir[(p + 3) % 4];
        printf("%d ", mas[i][j]);
    }
    ++p;
    l -= p % 2;
  }
  putchar('\n');
  return 0;
}
