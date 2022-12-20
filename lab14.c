#include <stdio.h>
#include <stdlib.h>

struct index{
     int x;
     int x1;
     int y;
     int y1;
}index;
int func(int x, int g){
     if ((x<g) && (x>=0)) return 1;
     else return 0;
}
int main() {
     FILE *f;
     f = fopen("input.txt", "r");
     int g,l=0;
    char n[1000];
    fscanf(f,"%s",n);
    g = atoi(n);
    int kv[g][g];
    for(int i = 0; i < g; i++){
          for(int j = 0; j < g; j++){
               fscanf(f,"%s",n);
               kv[i][j] = atoi(n);
         }
    }
      for(int i = 0; i < g; i++){
          for(int j = 0; j < g; j++){
               printf("%d ", kv[i][j]);
         }
         printf("\n");
    }
     printf("\n");
     printf("\n");
    int k=1,k1 = 0;
     while(l!= g*g){
               if(l<g){
                    printf("%d ", kv[k1][g-k]);
                    k++;
                    k1++;
                    l++;
                    if(l==g){
                         index.x = k1-1;
                         index.x1 = g-k+1;
                         index.y = k1-1;
                         index.y1 = g-k+1;
                    }
               }
               else {

                    for(int i = 0; i<4;++i){
                         if((i%4)==0){
                                   index.x -=1;
                                   while(func(index.x, g) && func(index.x1,g)){
                                             if(l==g*g) return 0;
                                             else{
                                        printf("%d ", kv[index.x][index.x1]);
                                            l+=1;
                                            index.x-=1;
                                            index.x1+=1;
                                   }

                                   }
                                   index.x+=1;
                                   index.x1-=1;
                         }
                         else if((i%4)==1){
                                   index.y1 +=1;
                              while(func(index.y,g) && func(index.y1,g)){
                                        if(l==g*g) return 0;
                              else{
                                  printf("%d ", kv[index.y][index.y1]);
                                   l+=1;
                                   index.y1+=1;
                                   index.y-=1;
                              }

                              }
                              index.y1-=1;
                              index.y+=1;
                         }
                         else if((i%4)==2){
                                   index.y +=1;
                                   while(func(index.y,g) && func(index.y1,g)){
                                             if(l==g*g) return 0;
                                   else{
                                          printf("%d ", kv[index.y][index.y1]);
                                   l+=1;
                                   index.y1-=1;
                                   index.y+=1;
                                   }

                              }
                              index.y1+=1;
                              index.y-=1;

                         }
                         else if((i%4)==3){
                                   index.x1 -=1;
                                   while(func(index.x,g) && func(index.x1,g)){
                                             if(l==g*g) return 0;
                                   else{
                                       printf("%d ", kv[index.x][index.x1]);
                                   l+=1;
                                   index.x1-=1;
                                   index.x+=1;
                                   }

                              }
                              index.x1+=1;
                              index.x-=1;
                         }
                    }
               }
     }
}
