#include <stdio.h>
#include <dos.h>
#include <conio.h>

#define MAX 20

int S[MAX]={0},a[MAX]={0},c=0,n,k;

void Print(),Try(int);

main()
{
  int i,j,tam;
  
  printf("nhap k= "); scanf("%d", &k);
  for (i=0; i<k; i++){
  	printf("So chu %c = ",i+'A'); scanf("%d",&a[i]);
  	n+=a[i];
  }
  for (i=0; i<k; i++) printf("\na[%d]=%d",i+1,a[i]);
  printf("\nn = %d",n);
  Try(0);
}

void Try(int i)
{
	int j;
	
	for (j=0;j<k;j++) if (a[j]){
		S[i]=j; 
		a[j]-=1;
		if (i==n-1) Print(); else Try(i+1);
		a[j]+=1;
	}
}

void Print()
{
  int i;
  
  printf("\n%3d: ",++c);
  for (i=0; i<n; i++) printf("%c", S[i]+'A');
}
