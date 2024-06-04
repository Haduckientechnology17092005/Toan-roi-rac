#include <stdio.h>
#include <string.h>
#include "dothi.h"

GRAPH C,F={0},D; //khoi dau luong 0, D de danh dau cung nghich
int pr[MAX];//dinh truoc moi dinh tren duong di
int Fmax,n,s,t;
void readfile(), writefile(), PrintGraph(GRAPH a);
int CoDuongtang(), TimLuong();

int main()
{
    readfile();
    printf("So dinh cua mang da cho:");printf("%d", n);
    printf("\nDinh phat:");printf("%d", s+1);
    printf("\nDinh thu:");printf("%d", t+1);
	printf("\nMa tran trong so bieu dien mang:\n\n"); 
    PrintGraph(C);
    Fmax=TimLuong();
    printf("\nThe maximum of flow = %d\n",Fmax);
    PrintGraph(F);
    //writefile();
    return 0;
}
void readfile()
{
	char fn[20]; FILE *f; int i,j;

	printf("File (*.INP): "); gets(fn);
	if (!strchr(fn,'.')) strcat(fn,".INP");
	f=fopen(fn,"rt");
	fscanf(f,"%d%d%d",&n,&s,&t);
	for (i=0; i<n;i++){
	  for (j=0;j<n;j++) fscanf(f,"%d",&C[i][j]);
	  fscanf(f,"\n");
   }
   fclose(f);
}

void writefile()
{
	char fn[20]; FILE *f; int i,j;

	printf("Out File (*.OUT): "); gets(fn);
	if (!strchr(fn,'.')) strcat(fn,".OUT");
	f=fopen(fn,"wt");
	fprintf(f,"%d-->%d, Maxflow = %d\n",s+1,t+1,Fmax);
	for (i=0; i<n;i++){
	  for (j=0;j<n;j++) fprintf(f,"%d ",F[i][j]);
	  fprintf(f,"\n");
   }
   fclose(f);
}
void PrintGraph(GRAPH a)
{
    int i, j;
    
    printf("\n");
    for(i=0; i<n; ++i){
      	for(j=0; j<n; ++j) printf(" %3d", a[i][j]);
    	printf("\n");
    }
}

int CoDuongtang()
{
  	int i,j,sQ,eQ;
	SET T={0},Q; //dau va cuoi hang doi
   	  
	for(i=0; i<n; i++)	
		for(j=0; j<n; ++j) D[i][j]=0;
	sQ=0;eQ=0;Q[sQ]=s;
    while (sQ<=eQ && !T[t]){
       	i=Q[sQ]; sQ++; T[i]=1; //lay ra khoi Q dinh i va danh dau i da duyet
        if (C[i][t]-F[i][t]>0){
        	T[t]=1; pr[t]=i;
		}//ket thuc som neu gap dinh t
		else 
		for(j=0; j<n; ++j){
		    if (!T[j])
			  if (C[i][j]-F[i][j]>0){ 
			  	eQ++; Q[eQ]=j; pr[j]=i; 
	    	  }
	    	  else
	    	  if (C[j][i] && F[j][i]>0){ 
			  	eQ++; Q[eQ]=j; pr[j]=i; D[i][j]=-1;
	    	  }
       }
    }
    if (T[t]){
	    printf("Duong tang luong:\n");
    	j=t;
    	while (j!=s){
    		i=pr[j];
	    	if (D[i][j]<0) printf("%d-->",j+1);else printf("%d<--",j+1);
			j=i;
    	}
    	printf("%d\n",j+1); 
	}
    return T[t];
  }

int TimLuong()
{
  int  i,j,max,delta;
  
  while (CoDuongtang()){
        // Tinh luong dieu chinh delta
		delta=INF; 
		j=t; 
        while (j!=s){
		    i=pr[j]; 
		    if (D[i][j]<0 && F[j][i]<delta) delta=F[j][i];
            else if (C[i][j]-F[i][j]<delta)
			 		delta=C[i][j]-F[i][j];
            j=i;
        }
        // Tang luong doc theo P trong pr
        j=t;
        while (j!=s){
		    i=pr[j];
            if (D[i][j]<0) F[j][i]-=delta; else F[i][j]+=delta;
            j=i;
        }
        printf("Voi delta = %d\n",delta); getchar();
  }
  printf("\nHet duong tang luong...\n");
  for(max=0,j=0; j<n; ++j) max+=F[s][j];
  return max;
}
