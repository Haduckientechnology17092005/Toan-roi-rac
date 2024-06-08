#include <stdio.h>

#define MAX 20
#define INF 1000000

typedef int MATRIX[MAX][MAX];
typedef MATRIX GRAPH;
typedef int VECTOR[MAX];
typedef VECTOR ARRAY;
typedef VECTOR SET;

int Dijkstra(int u, int v, ARRAY p, GRAPH a, int n) {
    int i, j;
    ARRAY D;
    SET T;
    
    for (i = 0; i < n; i++) D[i] = INF; // Kh?i t?o kho?ng cách ban d?u là vô h?n
    D[u] = 0; // Kho?ng cách t? u d?n chính nó là 0
    for (i = 0; i < n; i++) T[i] = 1; // Kh?i t?o t?t c? các d?nh chua du?c xét

    while (T[v]) {
        i = 0;
        while (!T[i]) i++; // Tìm d?nh d?u tiên chua du?c xét
        for (j = i + 1; j < n; j++) {
            if (T[j] && D[j] < D[i]) i = j; // Tìm d?nh có kho?ng cách ng?n nh?t trong các d?nh chua du?c xét
        }
        T[i] = 0; // Ðánh d?u d?nh i dã du?c xét
        
        for (j = 0; j < n; j++) {
            if (T[j] && a[i][j]) { // V?i m?i d?nh k? j c?a i
                if (D[i] + a[i][j] < D[j]) { // N?u kho?ng cách t? u d?n j qua i nh? hon kho?ng cách hi?n t?i
                    D[j] = D[i] + a[i][j]; // C?p nh?t kho?ng cách m?i
                    p[j] = i; // Luu d?nh tru?c j trên du?ng di ng?n nh?t
                }
            }
        }
    }
    return D[v]; // Tr? v? kho?ng cách ng?n nh?t t? u d?n v
}

void printPath(int u, int v, ARRAY p) {
    if (u == v) {
        printf("%d", u + 1); // In ra d?nh b?t d?u, chuy?n d?i ch? s? m?ng v? d?nh th?t (1-based)
    } else if (p[v] == -1) {
        printf("No path from %d to %d", u + 1, v + 1); // Chuy?n d?i ch? s? m?ng v? d?nh th?t (1-based)
    } else {
        printPath(u, p[v], p);
        printf(" -> %d", v + 1); // In ra các d?nh trên du?ng di, chuy?n d?i ch? s? m?ng v? d?nh th?t (1-based)
    }
}

int main() {
    GRAPH a = {
        {0, 13, 2, INF, INF, INF},
        {13, 0, INF, INF, 5, INF},
        {2, INF, 0, 5, INF, 12},
        {4, 7, INF, 0, 3, 6},
        {INF, INF, INF, 3, 0, 2},
        {INF, INF, 12, INF, 2, 0},
    };
    int n = 6;
    int u = 0; // Ð?nh b?t d?u (1 trong ch? s? th?c)
    int v = 3; // Ð?nh k?t thúc (5 trong ch? s? th?c)
    ARRAY p;
    
    // Kh?i t?o m?ng p
    for (int i = 0; i < n; i++) p[i] = -1;

    int distance = Dijkstra(u, v, p, a, n);
    printf("Khoang cach ngan nhat tu dinh %d den dinh %d la: %d\n", u + 1, v + 1, distance);

    printf("Duong di ngan nhat tu dinh %d den dinh %d la: ", u + 1, v + 1);
    printPath(u, v, p);
    printf("\n");

    return 0;
}

