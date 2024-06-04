#include <stdio.h>

#define MAX 20
int S[MAX]={0}, c=0, n, k, a, b; //cho S[0]=0.

void Try(int), print();

main()
{
  printf("nhap loai n= "); scanf("%d", &a);
  printf("nhap so phan tu k= "); scanf("%d", &b);
  n=b+a-1; k=a-1;
  Try(1);
  getchar();
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
  for (i=1; i<=k; i++) printf("%d, ", S[i]-S[i-1]-1);
  printf("%d", n-S[k]);
}
