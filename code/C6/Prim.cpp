//Thuat toan Prim tim cay phu nho nhat 
//  Doc do thi tu file *.INP
#include <stdio.h>
#include <string.h>
#include "Dothi.h"

main()
{
	int n,i,j,w;
	GRAPH a,T;
	FILE *f;
	char fn[20];
	
	printf("File (*.INP): "); gets(fn);
	if (!strchr(fn,'.')) strcat(fn,".INP");
	f=fopen(fn,"rt");
	fscanf(f,"%d",&n);
	for (i=0; i<n; i++){
	  for (j=0; j<n; j++) fscanf(f,"%d",&a[i][j]);
	}
	fclose(f);
	// Nhap a[i][j]=0 neu khong co canh (i,j)
	
	//Dat lai a[i][j]=INF neu khong co canh (i,j)
	for (i=0; i<n; i++)
	  for (j=0; j<n; j++) 
	    if (!a[i][j]) a[i][j]=INF;
	    
	// in ma tran A
	printf("\nDo thi G:\n");
	printf("\n");
	for (i=0; i<n; i++){
	  for (j=0; j<n; j++) 
	    if (a[i][j]<INF) printf("%5d",a[i][j]); else printf("%5c",236);
	  printf("\n");
	}
	w=Prim(T,a,n);
	// in ma tran A
	printf("\nCay T:\n");
	for (i=0; i<n; i++){
	  for (j=0; j<n; j++) 
	    printf("%5d",T[i][j]);
	  printf("\n");
	}
	printf("Trong so T = %d\n",w);
}

