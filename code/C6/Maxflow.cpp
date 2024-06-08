#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 9999
#define MAX 100

typedef int GRAPH[MAX][MAX];

GRAPH C, F = {0}, D; // Initialize flow to 0, D for marking reverse edges
int pr[MAX]; // Predecessor array for each vertex
int Fmax, n, s, t;

void readfile();
void writefile();
int CoDuongtang();
int TimLuong();

int main() {
    readfile();
    printf("Number of vertices: %d\n", n);
    printf("Source vertex: %d\n", s + 1);
    printf("Sink vertex: %d\n", t + 1);

    Fmax = TimLuong();
    printf("\nThe maximum flow = %d\n", Fmax);
    
    writefile();
    return 0;
}

void readfile() {
    char fn[20]; 
    FILE *f; 
    int i, j;

    printf("File (*.INP): "); 
    fgets(fn, sizeof(fn), stdin);
    fn[strcspn(fn, "\n")] = 0; // Remove newline character if present
    if (!strchr(fn, '.')) strcat(fn, ".INP");
    
    f = fopen(fn, "r");
    if (f == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    fscanf(f, "%d%d%d", &n, &s, &t);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fscanf(f, "%d", &C[i][j]);
        }
    }
    fclose(f);
}

void writefile() {
    char fn[20]; 
    FILE *f; 
    int i, j;

    printf("Out File (*.OUT): "); 
    fgets(fn, sizeof(fn), stdin);
    fn[strcspn(fn, "\n")] = 0; // Remove newline character if present
    if (!strchr(fn, '.')) strcat(fn, ".OUT");
    
    f = fopen(fn, "w");
    if (f == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(f, "%d-->%d, Maxflow = %d\n", s + 1, t + 1, Fmax);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fprintf(f, "%d ", F[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

int CoDuongtang() {
    int i, j, sQ, eQ;
    int T[MAX] = {0}, Q[MAX]; // T array to mark visited nodes

    memset(D, 0, sizeof(D)); // Reset D array
    sQ = 0; eQ = 0; Q[sQ] = s;

    while (sQ <= eQ && !T[t]) {
        i = Q[sQ++];
        T[i] = 1; // Mark node i as visited
        if (C[i][t] - F[i][t] > 0) {
            T[t] = 1; pr[t] = i;
        } else {
            for (j = 0; j < n; j++) {
                if (!T[j]) {
                    if (C[i][j] - F[i][j] > 0) { 
                        Q[++eQ] = j; pr[j] = i; 
                    } else if (C[j][i] && F[j][i] > 0) { 
                        Q[++eQ] = j; pr[j] = i; D[i][j] = -1;
                    }
                }
            }
        }
    }
    return T[t];
}

int TimLuong() {
    int i, j, max, delta;

    while (CoDuongtang()) {
        // Calculate the adjustment flow delta
        delta = INF; 
        for (j = t; j != s; j = pr[j]) {
            i = pr[j]; 
            if (D[i][j] < 0 && F[j][i] < delta) delta = F[j][i];
            else if (C[i][j] - F[i][j] < delta) delta = C[i][j] - F[i][j];
        }
        // Increase flow along the augmenting path in pr
        for (j = t; j != s; j = pr[j]) {
            i = pr[j];
            if (D[i][j] < 0) F[j][i] -= delta; else F[i][j] += delta;
        }
        printf("With delta = %d\n", delta);
    }
    
    printf("\nNo more augmenting path...\n");
    for (max = 0, j = 0; j < n; j++) max += F[s][j];
    return max;
}
