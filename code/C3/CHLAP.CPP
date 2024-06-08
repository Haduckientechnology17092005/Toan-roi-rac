#include <stdio.h>

#define MAX 20
int S[MAX], c=0, n, k; //bo qua S[0].

void Try(int), Print();

int main(){

  printf("nhap n, k:"); scanf("%d%d", &n,&k);
  Try(1);

  return 0;
}

void Try(int i)
{
  int j;
  
  for (j=1; j<=n; j++){
    S[i]=j;
    if (i==k) Print(); else Try(i+1);
  }
}

void Print()
{
  int i;
  printf("\n%3d:",++c);
  for (i=1; i<=k; i++) printf(" %d", S[i]); //delay(50);
}
