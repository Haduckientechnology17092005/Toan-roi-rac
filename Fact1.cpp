#include <stdio.h>
#include <stdlib.h>

int Fact(int n)
{
	int p, k;
	
	for (p=1, k=2; k<=n; k++) p*=k;
	return p;
}

main()
{
    int  n;

	system("COLOR F0");
    printf("n= "); scanf("%d", &n);
	printf("%d! = %d", n, Fact(n));
}
