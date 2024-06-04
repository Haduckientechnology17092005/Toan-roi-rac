#include <stdio.h>
#define MAX 50

int Fib(int n);

int main()
{
    int n,c=0;
    
    for (n=0; n<MAX; n++) printf("\n%10d: %d",++c,Fib(n));
}

int Fib(int n)
{
    if (n<2) return 1;
	return Fib(n-1)+Fib(n-2);
}
