#define MAX 20
#define INF 1000000

typedef int MATRIX[MAX][MAX];
typedef MATRIX GRAPH;
typedef int VECTOR[MAX];
typedef VECTOR ARRAY;
typedef VECTOR SET;

int LThong(GRAPH a, int n)
{
  int i,j,k;
  GRAPH b;
  
  for (i=0; i<n; i++)
	 for (j=0; j<n; j++) b[i][j]=a[i][j];
  
  for (i=0; i<n; i++) b[i][i]=1;
  
  for (k=0; k<n-1; k++)
    for (i=0; i<n; i++)
      for (j=0; j<n; j++)      
        b[i][j]=b[i][j]||b[i][k]&&b[k][j];
       
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)      
       if (!b[i][j]) return 0;
  return 1;    
}

int VoHuong(GRAPH a, int n)
{
  int i,j;
       
  for (i=0; i<n-1; i++)
    for (j=i+1; j<n; j++)      
       if (a[i][j]!=a[j][i]) return 0;
  return 1;    
}

int Euler(GRAPH a, int n) //Do thi khong co khuyen
{
  int i,j;
  ARRAY x={0};
       
  if (!VoHuong(a,n)) return 0;
  if (!LThong(a,n)) return 0;
  for (i=0; i<n-1; i++)
    for (j=i+1; j<n; j++) x[i]+=a[i][j];     
  for (i=0; i<n; i++)  
       if (x[i]%2) return 0;
  return 1;    
}

int Dijkstra(int u, int v, ARRAY p, GRAPH a, int n)//Duong di tra ve trong mang p, voi moi i: a[i][i]=0
{
  int i,j;
  ARRAY D;
  SET T;
       
  for (i=0; i<n; i++) D[i]=INF; D[u]=0;
  for (i=0; i<n; i++) T[i]=1; 
  while (T[v]){
  	i=0; while (!T[i]) i++;
  	for (j=i+1; j<n; j++) 
	  if (T[j] && D[j]<D[i]) i=j;
  	T[i]=0;
  	for (j=0; j<n; j++) if (T[j]&&a[i][j]) // moi j ke i
  	  if (D[i]+a[i][j]<D[j]){
  	  	D[j]=D[i]+a[i][j]; 
  	  	p[j]=i;
	  }
  }
  return D[v];
}

void BellmanFord(int u, ARRAY p, ARRAY D, GRAPH a, int n)
//Tim ddnn tu dinh u den moi dinh khac
//p[j] la dinh truoc j tren ddnn
{
  int i,j,k,done;
       
  for (i=0; i<n; i++) D[i]=INF; D[u]=0;
  for (i=0; i<n; i++) p[i]=i; 
  
  for (k=0; k<n; k++){
  	done=1;
  	for (i=0; i<n; i++) if (D[i]<INF)
  	  for (j=0; j<n; j++) if (a[i][j])
  	  	if (D[i]+a[i][j]<D[j]){
  	  	  D[j]=D[i]+a[i][j]; 
  	  	  p[j]=i;
  	  	  done=0;
	  }
	if (done)  break;
  }
}

void Floyd(GRAPH a, MATRIX p, int n)
//Dinh trung gian tra ve trong ma tran p, voi moi i: a[i][i]=0
{
  int i,j,k;
         
  for (i=0; i<n; i++) 
    for (j=0; j<n; j++)
	  p[i][j]=-1; // khong co dinh trung gian

  for (k=0; k<n; k++)
  	for (i=0; i<n; i++) 
  	  for (j=0; j<n; j++)
   	  	if (a[i][k]+a[k][j]<a[i][j]){
  	  	  a[i][j]=a[i][k]+a[k][j];
  	  	  p[i][j]=k;
	    }
  // Ham nay thay doi tren chinh ma tran a
}
int Prim(GRAPH T, GRAPH a, int n)
{
	int i,j,k,i0,j0,min,w=0;
	SET VT={0};
	
	VT[0]=1;
	for (i=0; i<n; i++)
	  for (j=0; j<n; j++) T[i][j]=0;
	
	for (k=0; k<n-1; k++){
		min=INF; 
		for (i=0; i<n; i++)
	  		for (j=0; j<n; j++)
	  		  	if (VT[i] && !VT[j] && a[i][j]<min){ 
	  		  	  		min=a[i][j];
						i0=i;
	  		  	  		j0=j;
					}
		VT[j0]=1;
		T[i0][j0]=T[j0][i0]=a[i0][j0];
		w+=a[i0][j0];
	}  
	return w;
}
