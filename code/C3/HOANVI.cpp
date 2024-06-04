#include <stdio.h>

#define MAX 20
int S[MAX], a[MAX], c=0, n; //bo qua S[0].

void Try(int), print();

main()
{
  printf("nhap n= "); scanf("%d", &n);
  for (int j=1; j<=n; j++) a[j]=1;
  Try(1);
}

void Try(int i)
{
  int j;
  for (j=1; j<=n; j++) if (a[j]){
    S[i]=j;
    a[j]=0;
    if (i==n) print(); else Try(i+1);
    a[j]=1;
  }
}

void print()
{
  int i;
  printf("\n%3d:",++c);
  for (i=1; i<=n; i++) printf(" %d", S[i]); 
}
