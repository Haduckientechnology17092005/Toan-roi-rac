#include <stdio.h>

#define MAX 20
int S[MAX]={0}, c=0, n, k; //cho S[0]=0.

void Try(int), print();

main()
{
  printf("nhap n>=k:"); scanf("%d%d", &n,&k);
  Try(1);
}

void Try(int i)
{
  int j;
  for (j=1+S[i-1]; j<=n-k+i; j++){
    S[i]=j;
    if (i==k) print(); else Try(i+1);
  }
}

void print()
{
  int i;
  printf("\n%3d:",++c);
  for (i=1; i<=k; i++) printf(" %d", S[i]); //delay(50);
}
