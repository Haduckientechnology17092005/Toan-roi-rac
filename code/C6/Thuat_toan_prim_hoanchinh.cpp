#include <stdio.h>

#define MAX 20
#define INF 1000000

typedef int MATRIX[MAX][MAX];
typedef MATRIX GRAPH;
typedef int VECTOR[MAX];
typedef VECTOR SET;

int Prim(GRAPH T, GRAPH a, int n) {
    int i, j, k, i0, j0, min, w = 0;
    SET VT = {0};
    
    VT[0] = 1; // B?t d?u t? d?nh d?u ti�n
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            T[i][j] = 0; // Kh?i t?o c�y khung r?ng
    
    for (k = 0; k < n - 1; k++) {
        min = INF;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (VT[i] && !VT[j] && a[i][j] < min) {
                    min = a[i][j];
                    i0 = i;
                    j0 = j;
                }
        VT[j0] = 1; // Th�m d?nh j0 v�o c�y khung
        T[i0][j0] = T[j0][i0] = a[i0][j0]; // C?p nh?t c�y khung
        w += a[i0][j0]; // C?ng tr?ng s? c?nh v�o t?ng tr?ng s?
    }  
    return w; // Tr? v? t?ng tr?ng s? c?a c�y khung nh? nh?t
}

int main() {
    GRAPH a = {
        {0, 33, 17, INF, INF, INF},
        {33, 0, 18, 20, INF, INF},
        {17, 18, 0, 16, 4, INF},
        {INF, 20, 16, 0, 9, 8},
        {INF, INF, 4, 9, 0, 14},
        {INF, INF, INF, 8, 14, 0},
    };
    GRAPH T;
    int n = 6;

    int weight = Prim(T, a, n);
    printf("Trong so cua cay khung nho nhat la: %d\n", weight);

    printf("Cay khung nho nhat (ma tran ke):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }

    return 0;
}

