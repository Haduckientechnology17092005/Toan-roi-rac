#include <stdio.h>
#include <stdlib.h>

#define MAX 20
int S[MAX], a[MAX], c=0, n, k;

void Try(int), print();

int main(){
  printf("nhap n>=k:"); scanf("%d%d", &n,&k);
  for (int j=1; j<=n; j++) a[j]=1;
  Try(1);
  return 0;
}

void Try(int i)
{
  int j;
  for (j=1; j<=n; j++) if (a[j]){
    S[i]=j;
    a[j]=0;
    if (i==k) print(); 
    else Try(i+1);
    a[j]=1;
  }
}

void print()
{
  int i;
  printf("\n%3d:",++c);
  for (i=1; i<=k; i++) printf(" %d", S[i]); 
}
