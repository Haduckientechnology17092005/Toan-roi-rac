//8 hau hoa binh
#include <stdio.h>
#include <stdlib.h>

int S[8], a[8], b[15], c[15], sol=0;

void Try(int), print();

int main(){
  int i;

  system("COLOR F0");
  for (i=0; i<8; i++) a[i]=1;
  for (i=0; i<15; i++) b[i]=1;
  for (i=0; i<15; i++) c[i]=1;
  Try(0);
  return 0;
}

void Try(int i)
{
  int j;
  for (j=0; j<8; j++) if (a[j]&&b[i-j+7]&&c[i+j]){
    S[i]=j;
    a[j]=0; b[i-j+7]=0; c[i+j]=0;
    if (i==7) print(); else Try(i+1);
    a[j]=1; b[i-j+7]=1; c[i+j]=1;
  }
}

void print()
{
  int i;
  printf("\n\n%3d:",++sol);
  for (i=0; i<8; i++) printf("%d ", 1+S[i]);
}
