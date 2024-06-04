//Thuat toan Dijkstra/Floyd tim duong di ngan nhat 
//  Doc do thi tu file *.INP
#include <stdio.h>
#include <string.h>
#include "Dothi.h"
#define MAX 20

void Path(GRAPH p, int u, int v) // in ra cac dinh trung gian giua u va v
{
	int k;
	k=p[u][v];
	if (k>=0){
		Path(p,u,k);
		printf("-->%d",k+1);
		Path(p,k,v);
	}
}

main()
{
	int n,i,j,k,s,e,Distance;
	GRAPH a,pp;
	ARRAY p,d;
	FILE *f;
	char fn[20];
	
	printf("File (*.INP): "); gets(fn);
	if (!strchr(fn,'.')) strcat(fn,".INP");
	f=fopen(fn,"rt");
	fscanf(f,"%d\n",&n);
	for (i=0; i<n; i++){
	  for (j=0; j<n; j++) fscanf(f,"%d",&a[i][j]);
	  fscanf(f,"\n");
	}
	fclose(f);
	// in ma tran A
	printf("\nn=%d\n",n);
	for (i=0; i<n; i++){
	  for (j=0; j<n; j++) printf("%5d",a[i][j]);
	  printf("\n");
	}
	printf("Thuat toan Distra:\n");
	printf("Dinh dau  (1..%d): ",n); scanf("%d",&s); s--;
	printf("Dinh cuoi (1..%d): ",n); scanf("%d",&e); e--;
	
	Distance=Dijkstra(s,e,p,a,n);
	printf("\nDo dai duong di =%d\n",Distance);	
	i=e; printf("\n%d<--",1+i);
	while (p[i]!=s){
		i=p[i];printf("%d<--",1+i);
	}
	printf("%d\n",1+s);
	getchar();	

	printf("Thuat toan Bellman-Ford:\n");
	printf("Dinh xuat phat  (1..%d): ",n); scanf("%d",&s); s--;
	BellmanFord(s,p,d,a,n);
	printf("\nCac duong di:\n");
	for (k=0; k<n; k++) if (k!=s){
		i=k; printf("\n%d<--",i+1);
		while (p[i]!=s){
		i=p[i];printf("%d<--",i+1);
		}
		printf("%d:  %d\n",s+1,d[k]);	
	}	
	getchar();	
	
	printf("Thuat toan Floyd:\n");
	for (i=0; i<n; i++)
	  for (j=0; j<n; j++)
	    if (i!=j && !a[i][j]) a[i][j]=INF;
	Floyd(a,pp,n);
	printf("\n");
	for (i=0; i<n; i++){
	  for (j=0; j<n; j++) printf("%5d",a[i][j]<INF?a[i][j]:0);
	  printf("\n");
	}
	printf("\n");
	for (i=0; i<n; i++){
	  for (j=0; j<n; j++) printf("%5d",pp[i][j]);
	  printf("\n");
	}   
	printf("%d",s+1);
    Path(pp, s, e);
	printf("-->%d",e+1);	
}
