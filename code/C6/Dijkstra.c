#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 20
#define INF 100000

// Biến toàn cục
int n;
int a[MAX][MAX];// Ma trận kề
int D[MAX][MAX];// Bảng kết quả tính toán
int smin[MAX];// Lưu quãng đường ngắn nhất


void make_D();
void display_D();
void display_D2();
void display_Graph();
void min_road(int v);

int main() {
    // Đọc file
    char filename[20] = "test3";
    //printf("Nhap ten file (.inp): ");
    //scanf("%s", filename);
    strcat(filename, ".inp");
    FILE *file;
    file = fopen(filename, "r");
    if(file != NULL) {
        fscanf(file, "%d", &n);
        // a[i][j] = 0 nếu không có cạnh (i, j)
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                fscanf(file, "%d", &a[i][j]);
            }
        }
    }

    // Đặt lại a[i][j] = INF nếu không có cạnh (i,j)
	for (int i = 1; i <= n; i++)
	  for (int j = 1; j <= n; j++) 
	    if (!a[i][j]) a[i][j] = INF;
    printf("Do thi:\n");
    display_Graph();
    printf("\n");

    make_D();
    printf("Bang ket qua:\n");
    display_D();

    int v;// Đỉnh cuối v
    printf("Nhap dinh muon di chuyen den: ");
    scanf("%d", &v);
    min_road(v);
    fclose(file);
    return 0;
}

void make_D() {
    bool T[MAX];// Nhãn cố định
    // Ban đầu các đỉnh chưa được dán nhãn
    for(int i = 1; i <= n; i++) T[i] = 0;

    // Cài mặc định
    D[0][0] = 0;
    for(int i = 2; i <= n; i++) {
        D[0][i] = INF;
    }
    int k = 0;// Số nhãn cố định
    int current = 1;// Đỉnh đang xét hiện tại
    smin[current] = 0;// Cập nhật đường đi ngắn nhất từ đỉnh đầu tới đỉnh current

    // Bước lặp tiếp theo
    T[1] = 1;// Đánh dấu Đỉnh 1
    while(++k != n) {
        int min = INF;// Quãng đường ngắn nhất
        int idx;// Đỉnh có quãng đường ngắn nhất
        // Cập nhật đường đi tối ưu bước hiện tại
        for(int i = 1; i <= n; i++) {
            if(T[i] == 0) {// T[i] = 0: tức là đỉnh i chưa dán nhãn cố định
                D[k][i] = D[k - 1][i];
                if(D[k][i] > D[k - 1][current] + a[current][i]) {
                    D[k][i] = D[k - 1][current] + a[current][i];
                }
                // Tìm đỉnh quãng đường ngắn nhất bước hiện tại
                if(min > D[k][i]) {
                    min = D[k][i];
                    idx = i;
                }
            }
        }
        current = idx;// Cập nhật đỉnh xét tiếp theo
        T[current] = 1;// Dán nhãn cố định đỉnh current
        smin[current] = min;// Cập nhật đường đi ngắn nhất từ đỉnh đầu tới đỉnh current
    }
}

void display_D() {
    bool T[MAX];
    // Bảng mặc định ban đầu
    for(int i = 1; i <= n; i++) if(D[0][i] == INF) printf("%c\t", 236);
    else printf("%d\t", D[0][i]);
    printf("\n");

    // Bảng được cập nhật
    for(int i = 1; i <= n; i++) {// 
        for(int j = 1; j <= n; j++) {
            if(D[i][j] == 0) {
                if(T[j] == 0) {
                    printf("%d*\t", D[i - 1][j]);
                    T[j] = 1;
                }
                else printf("-\t");
            }
            else if(D[i][j] == INF)printf("%c\t", 236);
            else printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
}

void display_D2() {
    for(int i = 1; i <= n; i++) {// 
        for(int j = 1; j <= n; j++) {
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
}

void display_Graph() {
    for (int i = 1; i <= n; i++){
	    for (int j = 1; j <= n; j++) {
	        if (a[i][j] < INF) printf("%d\t", a[i][j]); 
            else printf("%c\t",236);
        }
	    printf("\n");
    }
}

void min_road(int v) {
    int i = v;
    int idx = v;
    printf("%d", v);
    while(i != 1) {
        if(D[i][idx] != 0 && (D[i][idx] != D[i - 1][idx])) {
            idx = 1;
            while(true) {
                if(D[i][idx] != 0 || (D[i][idx] == D[i - 1][idx])) idx++;
                else break;
            }
            printf("<--%d", idx);
        }
        i--;
    }
    printf("<--1\n");
    printf("Quang duong di ngan nhat: %d", smin[v]);
}