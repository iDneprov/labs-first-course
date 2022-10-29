#include <stdio.h>

#define maxn 100

int main() {
  int m[maxn][maxn];
  int dir[4] = {-1,0,1,0};
  int n;
  scanf("%i",&n);
  for (int i = 0; i != n ;++i){
    for (int j = 0; j != n ;++j){
        scanf("%d",&m[i][j]);
    }
  }

  int l = n, p = 0, i = n, j = n-1;
  while (l != 0) {
    for (int k = 0; k != l ;++k) {
      i+= dir[p%4];
      j+= dir[(p+3)%4];
      printf("%d ",m[i][j]);
    }
    ++p;
    l -= p%2;
  }
  putchar('\n');
}
