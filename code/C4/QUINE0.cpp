// Phuong phap Quine-McCluskey
// Doc tu file

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "console.h"
#include "console.cpp"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#define MAX 65

typedef int VT[MAX];
typedef VT MT[MAX];
MT a,b,c,var;
int n,k,kb,kc,pow2n,nv;
VT f,s;
void generate(),printMT(MT,int,int),printMINTERM(VT),printEXP(MT,int),
sort(MT,int),step1(),readfile(),step2(),
calf(MT,MT,int,int), Try(int),savevar();
int funcval(MT,VT,int,int);

main()
{
  
  readfile();
  pow2n=(int)pow(2,n);
  nv=0; Try(0);
  printMT(a,k,n);
  printEXP(a,k);
  sort(b,kb);
  printf("Sap xep:\n");
  printMT(b,kb,n);
  printEXP(b,kb);

  step1();
  printf("Bieu thuc goc:\n");
  printEXP(a,k);
  printf("Gia tri BT goc:\n");
  calf(a,var,k,n);
  printMT(var,pow2n,n);
  printf("Bieu thuc rut gon:\n");
  printEXP(b,kb);
  printf("Gia tri BT rut gon:\n");
  calf(b,var,kb,n);
  printMT(var ,pow2n,n);

  step2();
  printf("Bieu thuc goc:\n");
  printEXP(a,k);
  printf("Gia tri BT goc:\n");
  calf(a,var,k,n);
  printMT(var,pow2n,n);
  printf("Bieu thuc toi thieu:\n");
  printEXP(b,kb);
  printf("Gia tri BT toi thieu:\n");
  calf(b,var,kb,n);
  printMT(var,pow2n,n);
}

void generate()
{
  int i,j,ii,ok,exist,kmax;

  srand(time (NULL));
  n=2+rand()%5;
  kmax=(int)pow(2,n);
  k=n+rand()%(kmax-n-1); kb=k;
  printf("n=%d, k=%d:\n",n,k); getch();
  for (i=0; i<k; i++){
    a[i][n]=0;
    for (j=0; j<n; j++){
      a[i][j]=(rand()%MAX)%2;
      a[i][n]+=a[i][j];
    }
    ok=1;
    for (ii=0; ok && ii<i; ii++)
      if (a[ii][n]==a[i][n]){
		exist=1;
		for (j=0; exist&&j<n; j++)
	  	  if (a[ii][j]!=a[i][j]) exist=0;
		if (exist) ok=0;
      }
    if (i>0 && !ok) i--;
  }
  for (i=0; i<k; i++)
    for (j=0; j<=n; j++) b[i][j]=a[i][j];
}

void printMT(MT x, int k,int n)
{
  int i,j;

  for (i=0; i<k;i++){
    for (j=0; j<n;j++)
      if (x[i][j]<2) printf("%d ",x[i][j]); else printf("- ");
    printf("| %d |\n",x[i][n]);
  }
  getch();
}

void printMINTERM(VT v)
{
  int j;

  for (j=0; j<n;j++)
    if (v[j]<2){
      if (!v[j]) TextColor(7*16+4);
      printf("%c",'z'-n+1+j);
      TextColor(15*16);
    }
}

void printEXP(MT x,int k)
{
  int i,j;

  for (i=0; i<k-1;i++){
    printMINTERM(x[i]);
   	printf("+");
  }
  printMINTERM(x[i]);
  printf("\n");
  getch();
}

void sort(MT x,int k)
{
  int i,j,ii,temp;

  for (i=0; i<k-1;i++)
    for (ii=i+1; ii<k;ii++)
      if (x[ii][n]<x[i][n])
		for (j=0; j<=n;j++){
	  		temp=x[i][j]; x[i][j]=x[ii][j]; x[ii][j]=temp;
		}
}

void step1()
{
  int i,j,ii,jj,diff,ns,ghep;
  VT v;

  for (ns=0; ns<n-1; ns++){
    printMT(b,kb,n);
    kc=0; for (i=0; i<kb;i++) v[i]=0;
    for (i=0; i<kb;i++){
      printf("Xet (%d):\n",i+1);
      ghep=0;
      for (ii=i+1; ii<kb;ii++)
		if (b[ii][n]==b[i][n]+1){
	  		for (diff=0,j=0; j<n;j++)
	    		if (b[ii][j]!=b[i][j]) {diff++; jj=j;}
	  		if (diff==1) {
	    		v[ii]=1; ghep=1;
	    		for (j=0; j<=n;j++) c[kc][j]=b[i][j];
	    		c[kc][jj]=2;
	    		if (b[i][jj]) c[kc][n]--;
	    		printf("(%d,%d):\n",i+1,ii+1);
	    		kc++;
	    		printMT(c,kc,n);
	  		}
		}
      	if (!v[i]&&!ghep){
			printf("Khong ghep duoc (%d):\n",i+1);
			for (j=0; j<=n;j++) c[kc][j]=b[i][j];
			kc++;
			printMT(c,kc,n);
      	}
    }

    //xoa cac tieu hang trung nhau
    for (i=0; i<kc-1;i++){
      for (ii=i+1; ii<kc;){
		for (diff=0,j=0; j<=n;j++)
	    	if (c[ii][j]!=c[i][j]) diff++;
		if (diff==0){
	    	for (j=0; j<=n;j++) c[ii][j]=c[kc-1][j];
	    	kc--;
	    	sort(c,kc);
		} else ii++;
      }
    }
    sort(c,kc);
    for (i=0; i<kc;i++)
      for (j=0; j<=n;j++) b[i][j]=c[i][j];
    kb=kc;
  }
}

void step2()
{
  int ia,i,ii,j,cover,nc,done;
  VT va={0},vb={0},sa,sb;

  printf("\nOptimize:\n");
  for (i=0; i<kb;i++)
    for (j=0; j<k;j++) c[i][j]=0;
  for (j=0; j<n;j++) printf(" "); printf(" | ");
  for (i=0; i<k;i++) {printMINTERM(a[i]); printf(" | ");}  printf("\n");
  for (i=0; i<kb;i++){
    for (nc=0,j=0; j<n;j++) nc+=b[i][j]<2;
    printMINTERM(b[i]);
    for (j=0; j<n-nc;j++) printf(" ");  printf(" | ");
    for (ia=0; ia<k; ia++){
      cover=1;
      for (j=0; j<n; j++)
		if (b[i][j]<2 && b[i][j]!=a[ia][j]) cover=0;
      if (!cover) printf(" "); else {printf("X");c[i][ia]=1;}
      for (j=0; j<n;j++) printf(" "); printf("| ");
    }
    printf("\n");
  }
  printMT(c,kb,k); // c gom kb hang va k cot

  // Toi thieu hoa
  done=0; cover=0;
  while (!done){
    for (j=0;j<k;j++) if (!va[j]){
      sa[j]=0;
      for (i=0; i<kb; i++) sa[j]+=c[i][j];
    }
    j=0; while (j<k && (va[j]||sa[j]!=1)) j++;
    if (j==k) done=1;
    else{
      i=0; while (!c[i][j]) i++;// tim hoi so cap i la can thiet phai dua vao bieu thuc toi thieu
      printf("cot %d=>hang can thiet %d:\n",j+1,i+1);
      vb[i]=1; //danh dau hoi so cap i phai dua vao bieu thuc toi thieu
      for (j=0;j<k;j++) if (c[i][j]) {
		va[j]=1; cover++;
		for (ii=0; ii<kb; ii++) c[ii][j]=0;
      }
      printf("So cot da phu=%d:\n",cover);
      printMT(c,kb,k);
    }
  }
  // Phu tiep theo bang thuat toan tham lam
  printf("Da het cot can thiet...\n");
  while (cover<k){
    for (i=0; i<kb; i++) if (!vb[i]){
      sb[i]=0;
      for (j=0; j<k; j++) sb[i]+=c[i][j];
    }
    i=0; while (i<kb && vb[i]) i++;
    for (ii=i+1; ii<kb; ii++)
      if (!vb[ii] && sb[ii]>sb[i]) i=ii; //thuat toan tham lam tim hoi so cap i phu duoc nhieu cot nhat
    vb[i]=1; //danh dau hoi so cap i phai dua vao bieu thuc toi thieu
    for (j=0;j<k;j++) if (c[i][j]) {
      va[j]=1; cover++;
      for (ii=0; ii<kb; ii++) c[ii][j]=0;
    }
    printf("So cot da phu=%d:\n",cover);
    printMT(c,kb,k);
  }
  for (i=0; i<kb;)
    if (vb[i]) i++;
    else{
      kb--;
      for (j=0; j<k;j++) b[i][j]=b[kb][j];
      vb[i]=vb[kb];
    }
}

void readfile()
{
  FILE *f;
  int i,j;
  char fn[30];

  printf("File(*.TXT):"); gets(fn); strcat(fn,".TXT");
  f=fopen(fn,"rt");
  fscanf(f,"%d%d\n",&n,&k); kb=k;
  for (i=0; i<k; i++){
    a[i][n]=0;
    for (j=0; j<n; j++) {
      fscanf(f,"%d",&a[i][j]);
      if (a[i][j]<2) a[i][n]+=a[i][j];
      b[i][j]=a[i][j];
    }
    b[i][n]=a[i][n];
    fscanf(f,"\n");
  }
  fclose(f);
}

void savevar()
{
  int j;
  for (j=0; j<n; j++) var[nv][j]=s[j];
  nv++;
}

void Try(int i)
{
  int j;
  for (j=0; j<=1; j++){
    s[i]=j;
    if (i==n-1) savevar(); else Try(i+1);
  }
}

int funcval(MT a, VT v, int k, int n)
{
  int i,j;

  for (i=0; i<k; i++){
    for (j=0; j<n; j++)
      if (a[i][j]<2 && v[j]!=a[i][j]) break;
    if (j==n) return 1;
  }
  return 0;
}

void calf(MT a, MT x, int k, int n)
{
  int i;

  for (i=0;i<pow2n;i++) x[i][n]=funcval(a,x[i],k,n);
}
