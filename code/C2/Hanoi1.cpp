#include <stdio.h>

int Hanoi(int,int,int,int),dem=0;

main()
{
	int n;
	
	printf("n="); scanf("%d",&n);
	Hanoi(n,'A','B','C');
	//printf("\nH%d = %d",n,dem);
}

int Hanoi(int n,int A,int B,int C)
{
	if (n==1) printf("\n%-7d: %c-->%c",++dem,A,C);
	else {
		Hanoi(n-1,A,C,B);
		Hanoi(1,A,B,C);
		Hanoi(n-1,B,A,C);
	}
}
