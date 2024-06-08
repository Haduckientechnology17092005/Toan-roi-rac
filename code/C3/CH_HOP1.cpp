#include <stdio.h>

#define MAX 20
int S[MAX], a[MAX]={0}, c=0, n, k; //bo qua S[0].

void print();

int main()
{

  int i,j,x,ok;
  
  printf("nhap n>=k:"); scanf("%d%d", &n,&k);
  for (i=1; i<=k; i++){S[i]=i; a[i]=1;}
  print(); 
  while (1){
  	//Tim S[i] ben phai nhat co the tang
  	i=k; ok=0;
	while (i>0 && !ok){
		for (j=i+1; j<=k; j++) a[S[j]]=0;
		if (S[i]==n) i--;
		else{
			x=S[i]+1; while (x<=n && a[x]) x++;
		if (x>n) i--; else ok=1;	
		}
	} 
	if (i==0) break;
	// tang S[i]=x nho nhat khong co trong S[1..i-1]
	a[S[i]]=0; S[i]=x; a[x]=1; 
	// Ha S[i+1..k] xuong nho nhat
	for (j=i+1; j<=k; j++){
		x=1; while (a[x]) x++;
		S[j]=x; a[x]=1;
	}
	print(); 
  }
  return 0;
}

void print()
{
  int i;
  
  printf("\n%3d:",++c);
  for (i=1; i<=k; i++) printf(" %d", S[i]); 
}
