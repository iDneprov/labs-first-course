#include <stdio.h>
int main(){
printf("Insert matrix size...");
printf("\n");
int a;
scanf("%d", &a);
int A[a][a];
int B[a][a];
int C[a][a];
int k,j,i;
printf("Insert matrix elements...");
printf("\n");
for (i = 1; i <= a; i++){
	for (j = 1; j <= a; j++){
		scanf ("%d", &A[i][j]);
	}
}
printf("Transponded matrix:");
printf("\n");
for (i = 1; i <= a; i++){
	for (j = 1; j <= a; j++){
		B[i][j] = A[j][i];
		printf("%d ", B[i][j]);
	}
		printf("\n");

}
printf("The answer is:");
printf("\n");
for(i = 1; i <= a; i++)
    for(j = 1; j <= a; j++){
        C[i][j] = 0;
        for(k = 1; k <= a; k++)
        C[i][j] = C[i][j] + A[i][k] * B[k][j];
    }
i = 1;
for (i = 1; i <= a; i++){
	for (j = 1; j <= a; j++){
		printf ("%d " , C[i][j]);
	}
		printf("\n");
	}
}