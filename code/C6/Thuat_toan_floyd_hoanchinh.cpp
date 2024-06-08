#include <stdio.h>

#define MAX 20
#define INF 1000000

typedef int MATRIX[MAX][MAX];
typedef MATRIX GRAPH;

void Floyd(GRAPH a, MATRIX p, int n) {
    int i, j, k;
    
    // Kh?i t?o ma tr?n ð?nh trung gian p và ma tr?n kho?ng cách a
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++)
            p[i][j] = -1; // Không có ð?nh trung gian
            // Kh?i t?o ma tr?n kho?ng cách, l?y tr?ng s? t? ma tr?n tr?ng s? ban ð?u
            // Trong trý?ng h?p không có c?nh, kho?ng cách là INF
            if (i != j && a[i][j] == 0)
                a[i][j] = INF;

    // Thu?t toán Floyd-Warshall
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (a[i][k] + a[k][j] < a[i][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    p[i][j] = k; // Lýu ð?nh trung gian trên ðý?ng ði ng?n nh?t t? i ð?n j
                }
}

void printMatrix(MATRIX mat, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (mat[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", mat[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    GRAPH a = {
        {0, 5, INF, INF},
        {50, 0, 15, 5},
        {30, INF, 0, 15},
        {15, INF, 5, 0},
    };
    MATRIX p;
    int n = 4;

    Floyd(a, p, n);

    printf("Ma tran khoang cach giua cac dinh:\n");
    printMatrix(a, n);

    return 0;
}

