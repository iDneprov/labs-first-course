#include<stdio.h>
#include<stdbool.h>

int main(){
  int a = 10, k = 0, maxn = 214748364, minn = -214748364, n;
  scanf("%d", &n);
  bool f = true;
  int s = n;
  while (n != 0){
    n = n / 10;
    k++;
  }
	
  while (k < a){
    if (s >= minn && s <= maxn) s = s * 10;
    else f = !f;
    k++;
  }
  if (f) printf("number = %d\n", s);
  else printf("Вышел за рамки\n");
  return 0;
}
