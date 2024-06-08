#include <stdio.h>


#define MAX 20
int S[MAX]={0},a[MAX]={0},c=0, n=0; 

void print();

main(){
  int i,j,k,tam,dem;
  
  printf("nhap k= "); scanf("%d", &k);
  for (i=0; i<k; i++){
  	printf("So chu %c = ",i+'A'); scanf("%d",&a[i]);
  	n+=a[i];
  }
  dem=0;
  for (i=0; i<k; i++){
  	for (j=0; j<a[i]; dem++,j++) S[dem]=i;
  } 
  print();
  
  while (1){
    i=n-2; while (i>=0 && S[i]>=S[i+1]) i--;
    if (i<0) break;
    j=n-1; while (S[j]<=S[i]) j--;
    tam=S[i]; S[i]=S[j]; S[j]=tam;
    j=i+1; k=n-1;
    while (j<k){
      tam=S[j]; S[j]=S[k]; S[k]=tam;
      j++; k--;
	}
    print();
  } 
}

void print()
{
  int i;
  printf("\n%3d: ",++c);
  for (i=0; i<n; i++) printf("%c", S[i]+'A');
}
