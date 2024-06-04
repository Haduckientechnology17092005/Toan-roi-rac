#include <stdio.h>
#include <stdlib.h>

int C(int,int);

main () 
{
    int n, k;
	
	system("COLOR F0");    
	printf("n= "); scanf("%d",&n);
	printf("k= "); scanf("%d",&k);
	printf("C(%d,%d)= %d",n,k,C(n,k));
}

int C(int n,int k)
{
  if (k==0||k==n) return 1;
  else return C(n-1,k-1)+C(n-1,k);
}
