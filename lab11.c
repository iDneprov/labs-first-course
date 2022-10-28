#include <stdio.h>

int mpow(int n,int a) {
  if (a == 0) {
    return 1;
  }
  else {
    return mpow(n,a-1)*n;
  }
}

int DesToVosm(int n) {
  int a = mpow(8,3),c = 0,res = 0;
  while (n != 0) {
    if (n-a > 0) {
      c = c + n/a;
      n = n%a;
    }
    a = a/8;
    res = res*10 + c;
    c = 0;
  }
  while (a != 0){
    res = res*10;
    a = a/8;
  }
  return res;
}

int main() {
  int x=0,y = 0,p = 0,res;
  p = getchar();
  while (p != '\n') {
    if (p > 57 || p < 48) {
      return 0;
    }
    x = x*10+(p-48);
    p = getchar();
  }
  p = getchar();
  while (p != '\n') {
    if (p > 57 || p < 48) {
      return 0;
    }
    y = y*10+(p-48);
    p = getchar();
  }
  x = DesToVosm(x);
  y = DesToVosm(y);
  if (x > y) {
    res = x-y;
  }
  else {
    res = y-x;
  }
  if (res == 0) {
    putchar('0');
    putchar('\n');
    return 0;
  }
  char a[10] = {'0','1','2','3','4','5','6','7','8','9',};
  int rasriadi[10];
  int i = 0;
  for (i;res>0;i++) {
    rasriadi[i] = res%10;
    res = res/10;
  }
  i--;
  for (i;i>=0;i--){
    putchar(a[rasriadi[i]]);
  }
  putchar('\n');
}
