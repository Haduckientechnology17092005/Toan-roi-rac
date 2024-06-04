#include <stdio.h>
#define MAX 1000

int a(int n)
{
  int x=0,y=1,z,i;
  
  if (n<2) return n;
  for(i=2;i<=n;i++){
    z=5*y-6*x;
	x=y;
	y=z;
  }
  return z;
}

main () 
{
  int n;
  
  for (n=0; n<MAX; n++) printf("\na%d=%d ",n,a(n));
}
