#include <stdio.h>

int Hanoi(int,int,int,int),dem=0;

main()
{
	int n;
	
	printf("n="); scanf("%d",&n);
	Hanoi(n,'A','B','C');
}

int Hanoi(int n,int A,int B,int C)
{
	if (n>0){
		Hanoi(n-1,A,C,B);
		printf("\n%-7d: %c-->%c",++dem,A,C);
		Hanoi(n-1,B,A,C);
	}
}
