/*Tìm chu trinh Euler tren don do thi*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef int GRAPH[MAX][MAX];

GRAPH a, b;
int Euler, n, ne, Cn=0, C1n=0, C[MAX], C1[MAX], All(GRAPH), Intersec(), EdgeNum();
void KTLThong(GRAPH, GRAPH), FindEulerCycle(), Append(), SortC(int), FindCycle(int v),
	 PrintCycle(int C[], int Cn), PrintMatrix(GRAPH a, int n);

main()
{
	int k,h,i,j,x[MAX],LT;
	FILE *f;
	char fn[20];
	
	printf("File(*.INP): "); gets(fn);
	if (strchr(fn,'.')==NULL) strcat(fn,".INP");
	f=fopen(fn,"rt");
	fscanf(f,"%d",&n);
	for (i=0; i<n; i++)
	  for (j=0; j<n; j++) fscanf(f,"%d",&a[i][j]);
	fclose(f);
	PrintMatrix(a, n);
	KTLThong(a,b);
	PrintMatrix(b, n);	
	LT=All(b);
	if (LT) printf("Do thi lien thong...\n"); 
	else{
		printf("Do thi khong lien thong...\n");
		exit(0);	
	} 
	//Tat ca bac chan
	for (i=0; i<n; i++){
	  x[i]=0;
	  for (j=0; j<n; j++)x[i]+=a[i][j];
	} 
	i=0; while (i<n && x[i]%2==0) i++;
	if (i<n) Euler=0;
	else Euler=1;
	
	if (!Euler) {
		printf("Do thi co dinh bac le...");
		exit(0);
	}
	printf("Do thi Euler...\n\n");
	FindEulerCycle();
	printf("Chu trinh Euler C:\n");
  	PrintCycle(C, Cn);
}

void KTLThong(GRAPH a, GRAPH b)
{
  int i,j,k;
  
  for (i=0; i<n; i++)
	 for (j=0; j<n; j++) b[i][j]=a[i][j]!=0;
  for (i=0; i<n; i++) b[i][i]=1;
  
  for (k=0; k<n-1; k++)
    for (i=0; i<n; i++)
      for (j=0; j<n; j++)      
        b[i][j]=b[i][j]||b[i][k]&&b[k][j];
}

int All(GRAPH a)
{
  int i,j;
  
  for (i=0; i<n; i++)
	 for (j=0; j<n; j++) 
	   if (i!=j && !a[i][j]) return 0;
  return 1;
}

int EdgeNum() // dem so canh cua G
{
  	int i, j, ne;

  	ne=0;
	for (i=0; i<n-1; i++)
      for (j=i+1; j<n; j++)
        ne+=a[i][j];
    return ne;    
}

void FindCycle(int v) // Tim chu trinh bat dau tu dinh v
{
  	int i, j;;
    
	C1n=0; C1[C1n]=v; C1n++;
    i=v;
    do{	
      j=0;
      while (a[i][j]==0) j++;
      a[i][j]-=1;
      a[j][i]-=1;
      if (j!=v){
	    C1[C1n]=j; 
        C1n++;
      }  
      i=j;
    } while(i!=v);
}

void SortC(int i) // sap xep C bat dau tu dinh thu i cua C
{
  	int j;

    for (j=0; j<i; j++) C[Cn+j]=C[j];
    for (j=0; j<Cn; j++) C[j]=C[j+i];
}

int Intersec() // Dinh chung la dinh thu i tren C
{
	int i, j;

	for (i=0; i<Cn; i++){
		for (j=0; j<n; j++)
		  if (a[C[i]][j]!=0) return i;	
	}
}
  
void Append()
{
	int i;
	
	for (i=0; i<C1n; i++) C[Cn+i]=C1[i];
	Cn+=C1n;
}

void PrintCycle(int C[], int Cn)
{
	int i;
	
	for (i=0; i<Cn; i++) printf("%d-->", C[i]+1); 
	printf("%d\n", C[0]+1);
}

void PrintMatrix(GRAPH a, int n)
{
	int i, j;
	
	for (i=0; i<n; i++){
	  for (j=0; j<n; j++) printf("%5d",a[i][j]);
	  printf("\n");
	}
	getchar();

}

void FindEulerCycle()
{
	int i;
	
	ne=EdgeNum(); 
	FindCycle(0); 
	Cn=0; Append(); 
	printf("C: ");PrintCycle(C, Cn); 
	PrintMatrix(a, n);
	while (Cn<ne){
      	i=Intersec(); printf("Dinh chung C[%d]=%d\n", i+1, C[i]+1); 
      	FindCycle(C[i]); printf("C1: "); PrintCycle(C1, C1n); 
      	SortC(i); printf("Sap xep C: "); PrintCycle(C, Cn);
      	Append(); printf("C+C1:"); PrintCycle(C, Cn);
      	PrintMatrix(a, n);
	}
}
