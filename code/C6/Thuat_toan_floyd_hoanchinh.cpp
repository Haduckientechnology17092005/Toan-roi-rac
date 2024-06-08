#include <stdio.h>

#define MAX 20
#define INF 1000000

typedef int MATRIX[MAX][MAX];
typedef MATRIX GRAPH;

void Floyd(GRAPH a, MATRIX p, int n) {
    int i, j, k;
    
    // Kh?i t?o ma tr?n �?nh trung gian p v� ma tr?n kho?ng c�ch a
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++)
            p[i][j] = -1; // Kh�ng c� �?nh trung gian
            // Kh?i t?o ma tr?n kho?ng c�ch, l?y tr?ng s? t? ma tr?n tr?ng s? ban �?u
            // Trong tr�?ng h?p kh�ng c� c?nh, kho?ng c�ch l� INF
            if (i != j && a[i][j] == 0)
                a[i][j] = INF;

    // Thu?t to�n Floyd-Warshall
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (a[i][k] + a[k][j] < a[i][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    p[i][j] = k; // L�u �?nh trung gian tr�n ��?ng �i ng?n nh?t t? i �?n j
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

