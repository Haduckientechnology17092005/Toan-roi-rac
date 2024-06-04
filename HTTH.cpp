#include <stdio.h>
#define MAX 45

int a(int n)
{
  if (n<2) return n;
  else return 5*a(n-1)-6*a(n-2);
}

main () 
{
  int n;
  
  for (n=0; n<MAX; n++) printf("\na%d=%d ",n,a(n));
}
