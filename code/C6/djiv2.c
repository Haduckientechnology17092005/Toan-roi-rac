#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int V;
    int **adj;
} Graph;

Graph* createGraph(int V) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->adj = (int**) malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = (int*) malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = INF;
        }
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v, int weight) {
    graph->adj[u][v] = weight;
    graph->adj[v][u] = weight;
}

int minDistance(int dist[], int sptSet[], int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(Graph* graph, int src, int dist[], int parent[]) {
    int V = graph->V;
    int sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph->adj[u][v] != INF && dist[u] + graph->adj[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->adj[u][v];
                parent[v] = u;
            }
        }
    }
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}

void printSolution(int dist[], int parent[], int V, int src, int dest) {
    printf("Vertex\t Distance\tPath");
    printf("\n%d -> %d \t\t %d\t\t%d ", src, dest, dist[dest], src);
    printPath(parent, dest);
    printf("\n");
}
void findShortestPathWithEdge(Graph* graph, int src, int dest, int u, int v) {
    int V = graph->V;
    int dist1[V], dist2[V];
    int parent1[V], parent2[V];

    // Bước 1: Tìm đường đi ngắn nhất từ src đến u
    dijkstra(graph, src, dist1, parent1);
    
    // Bước 2: Tìm đường đi ngắn nhất từ v đến dest
    dijkstra(graph, v, dist2, parent2);
    
    // Tổng khoảng cách
    int total_distance = dist1[u] + graph->adj[u][v] + dist2[dest];
    
    printf("Shortest path from %d to %d containing edge %d-%d:\n", src, dest, u, v);
    printf("Total distance: %d\n", total_distance);
    printf("Path: ");
    
    // In đường đi từ src đến u
    printPath(parent1, u);
    printf("%d ", u);
    
    // In cạnh u-v
    printf("%d ", v);
    
    // In đường đi từ v đến dest
    printPath(parent2, dest);
    printf("%d\n", dest);
}
int main() {
    int V = 6;
    Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 5);
    addEdge(graph, 2, 3, 5);
    addEdge(graph, 2, 4, 9);
    addEdge(graph, 3, 4, 4);
    addEdge(graph, 3, 5, 6);
    addEdge(graph, 4, 5, 7);

    int src = 0, dest = 5, u = 0, v = 5;
    findShortestPathWithEdge(graph, src, dest, u, v);

    for (int i = 0; i < V; i++) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph);

    return 0;
}