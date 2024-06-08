#include <stdio.h>
#include <limits.h>

#define MAX 20
#define INF 1000000

typedef int MATRIX[MAX][MAX];
typedef MATRIX GRAPH;
typedef int ARRAY[MAX];
typedef int VECTOR[MAX];
typedef VECTOR SET;

int Dijkstra(int u, int v, ARRAY p, GRAPH a, int n, int forbidden_vertex, int forbidden_edge_u, int forbidden_edge_v) {
    int i, j;
    ARRAY D;
    SET T;
    
    for (i = 0; i < n; i++) D[i] = INF; // Khởi tạo khoảng cách ban đầu là vô hạn
    D[u] = 0; // Khoảng cách từ u đến chính nó là 0
    for (i = 0; i < n; i++) T[i] = 1; // Khởi tạo tất cả các đỉnh chưa được xét

    while (T[v]) {
        i = 0;
        while (!T[i]) i++; // Tìm đỉnh đầu tiên chưa được xét
        for (j = i + 1; j < n; j++) {
            if (T[j] && D[j] < D[i]) i = j; // Tìm đỉnh có khoảng cách ngắn nhất trong các đỉnh chưa được xét
        }
        T[i] = 0; // Đánh dấu đỉnh i đã được xét
        
        if (i == forbidden_vertex) continue; // Bỏ qua đỉnh bị cấm

        for (j = 0; j < n; j++) {
            if (T[j] && a[i][j] && !(i == forbidden_edge_u && j == forbidden_edge_v) && !(i == forbidden_edge_v && j == forbidden_edge_u)) { // Với mỗi đỉnh kề j của i
                if (D[i] + a[i][j] < D[j]) { // Nếu khoảng cách từ u đến j qua i nhỏ hơn khoảng cách hiện tại
                    D[j] = D[i] + a[i][j]; // Cập nhật khoảng cách mới
                    p[j] = i; // Lưu đỉnh trước j trên đường đi ngắn nhất
                }
            }
        }
    }
    return D[v]; // Trả về khoảng cách ngắn nhất từ u đến v
}

void printPath(int u, int v, ARRAY p) {
    if (u == v) {
        printf("%d", u + 1); // In ra đỉnh bắt đầu, chuyển đổi chỉ số mảng về đỉnh thật (1-based)
    } else if (p[v] == -1) {
        printf("No path from %d to %d", u + 1, v + 1); // Chuyển đổi chỉ số mảng về đỉnh thật (1-based)
    } else {
        printPath(u, p[v], p);
        printf(" -> %d", v + 1); // In ra các đỉnh trên đường đi, chuyển đổi chỉ số mảng về đỉnh thật (1-based)
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
    int u = 0; // Đỉnh bắt đầu (1 trong chỉ số thực)
    int v = 3; // Đỉnh kết thúc (5 trong chỉ số thực)
    int forbidden_vertex = 2; // Đỉnh bị cấm (chuyển đổi thành 0-based index)
    int forbidden_edge_u = 4; // Cạnh bị cấm (đỉnh u)
    int forbidden_edge_v = 5; // Cạnh bị cấm (đỉnh v)
    ARRAY p;
    
    // Khởi tạo mảng p
    for (int i = 0; i < n; i++) p[i] = -1;

    int distance = Dijkstra(u, v, p, a, n, forbidden_vertex, forbidden_edge_u, forbidden_edge_v);
    printf("Khoang cach ngan nhat tu dinh %d den dinh %d la: %d\n", u + 1, v + 1, distance);

    printf("Duong di ngan nhat tu dinh %d den dinh %d la: ", u + 1, v + 1);
    printPath(u, v, p);
    printf("\n");

    return 0;
}
