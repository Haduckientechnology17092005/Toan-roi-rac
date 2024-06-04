#include <stdio.h>
#include <stdlib.h>

int H(int n), Hanoi(int n);

main()
{
	int n;
	
	system("COLOR F0");
	printf("n="); scanf("%d",&n);
	printf("\nHanoi%d = %d",n,Hanoi(n));
	printf("\nH%d = %d",n,H(n));
}

int H(int n)
{
	if (n==1) return 1;
	return 2*H(n-1)+1;
}
int Hanoi(int n)
{
	int x,i;
	
	for (x=1, i=0; i<n; i++) x*=2;
	return x-1;
}
