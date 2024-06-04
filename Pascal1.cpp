#include <stdio.h>
#define MAX 20

main () 
{
    int A[MAX][MAX]={0};
	int i, n, k;
    
    for (i=0; i<MAX; i++) A[i][0]=1;
    for (i=1; i<MAX; i++) A[i][i]=1;
	for (n=2; n<MAX; n++)
		for (k=1; k<n; k++) A[n][k]=A[n-1][k-1]+A[n-1][k];
    
    printf("Tam giac Pascal\n");
	for (n=0; n<MAX; n++){
		for (k=0; k<=n; k++) printf("%8d",A[n][k]);
		printf("\n");
	}
}
