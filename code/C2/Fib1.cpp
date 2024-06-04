#include <stdio.h>

#define MAX 10000

int Fib(int n);


int main()
{
    int n,c=0;
    
    for (n=0; n<MAX; n++) printf("\n%10d: %d",++c,Fib(n));

}

int Fib(int n)
{
    int i,x=1,y=1,z=1;
	
	for (i=2; i<=n;i++){
    	z=x+y;
    	x=y;
    	y=z;
	}
	return z;
}
