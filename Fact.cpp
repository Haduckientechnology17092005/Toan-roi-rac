#include <stdio.h>
#include <stdlib.h>

int Fact(int n)
{
	if (n == 0)	return 1;
	return Fact(n-1)*n;
}

main()
{
    int  n;

	system("COLOR F0");
    printf("n= "); scanf("%d", &n);
	printf("%d! = %d", n, Fact(n));
}
