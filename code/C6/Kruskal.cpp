#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define V 30
int parent[V];
int rank[V];

// Find set of vertex i (with path compression)
int find(int i) {
    if (parent[i] != i) {
        parent[i] = find(parent[i]);
    }
    return parent[i];
}

// Does union of i and j using union by rank
void union1(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);

    if (root_i != root_j) {
        if (rank[root_i] < rank[root_j]) {
            parent[root_i] = root_j;
        } else if (rank[root_i] > rank[root_j]) {
            parent[root_j] = root_i;
        } else {
            parent[root_j] = root_i;
            rank[root_i]++;
        }
    }
}

// Finds MST using Kruskal's algorithm
void kruskalMST(int cost[][V], int n) {
    int mincost = 0; // Cost of min MST.

    // Initialize sets of disjoint sets.
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Include minimum weight edges one by one
    int edge_count = 0;
    while (edge_count < n - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);
        printf("Edge %d: (%d, %d) cost: %d\n", ++edge_count, a, b, min);
        mincost += min;
    }
    printf("\nMinimum cost spanning tree = %d\n", mincost);
}

// driver program to test above function
int main() {
    int i, j, n;
    int Graph[V][V];
    char fn[101];

    printf("Enter the file name (*.INP): ");
    if (fgets(fn, sizeof(fn), stdin) != NULL) {
        size_t len = strlen(fn);
        if (len > 0 && fn[len - 1] == '\n') {
            fn[len - 1] = '\0';
        }
    }

    if (!strchr(fn, '.')) {
        strcat(fn, ".INP");
    }

    FILE *file = fopen(fn, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    fscanf(file, "%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fscanf(file, "%d", &Graph[i][j]);
            if (Graph[i][j] == 0) {
                Graph[i][j] = INT_MAX;
            }
        }
    }
    fclose(file);

    printf("n = %d\n", n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (Graph[i][j] != INT_MAX) {
                printf("%d\t", Graph[i][j]);
            } else {
                printf("INF\t");
            }
        }
        printf("\n");
    }

    // Print the solution
    kruskalMST(Graph, n);

    return 0;
}
