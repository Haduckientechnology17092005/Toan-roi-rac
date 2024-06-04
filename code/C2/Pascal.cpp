#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int C(int,int);

main () 
{
    int n, k;
    
    system("COLOR F0");
	printf("Tam giac Pascal\n");
	for (n=0; n<MAX; n++){
		for (k=0; k<=n; k++) printf("%8d",C(n,k));
		printf("\n");
	}
}

int C(int n,int k)
{
  if (k==0||k==n) return 1;
  else return C(n-1,k-1)+C(n-1,k);
}
