/*Thuat toan Floyd*/
#include <stdio.h>
#include <string.h>

#define MAX 20

typedef int GRAPH[MAX][MAX];

int n;
void Floyd(GRAPH,GRAPH);
void Path(int,int);
GRAPH a,b,p={0};

main()
{
	int i,j,u,v;
	FILE *f;
	char fn[20];
	
	printf("File: "); gets(fn);
    f=fopen(fn,"rt");
	fscanf(f,"%d\n",&n);
	for (i=0; i<n; i++){
	  for (j=0; j<n; j++) fscanf(f,"%d",&a[i][j]);
	  fscanf(f,"\n");
	}
	fclose(f);
	// in ma tran A
	for (i=0; i<n; i++){
	  for (j=0; j<n; j++) printf("%5d",a[i][j]);
	  printf("\n");
	}
	getchar();
	
	Floyd(a,b);
	
	// in ma tran B
	for (i=0; i<n; i++){
	  for (j=0; j<n; j++) printf("%5d",b[i][j]);
	  printf("\n");
	}
	printf("\nu-->v: "); scanf("%d%d",&u,&v);
	printf("%d-->%d:\n%d",u,v,u); Path(u,v);printf("-->%d",v);
	printf("\nDo dai = %d ",b[u][v]);
	getchar();	
}

void Floyd(GRAPH a, GRAPH b)
{
  int i,j,k;
  
  for (i=0; i<n; i++)
	 for (j=0; j<n; j++) b[i][j]=a[i][j];
  
  for (k=0; k<n; k++)
    for (i=0; i<n; i++)
      for (j=0; j<n; j++)      
        if (b[i][k]+b[k][j]<b[i][j]){
			b[i][j]=b[i][k]+b[k][j];
			p[i][j]=k+1;
		}
}
void Path(int i,int j)
{
  int k;
  if (p[i][j]){
  	k=p[i][j]-1;
  	Path(i,k);
  	printf("-->%d",k);
  	Path(k,j);
  }
}
