#include <stdio.h>
#include <stdlib.h>

int *S, *a, *b, *c, sol = 0;
int N;

void Try(int), print();

int main() {
    int i;
    printf("Nhap N (so luong hau): ");
    scanf("%d", &N);
    S = (int *)malloc(N * sizeof(int));
    a = (int *)malloc(N * sizeof(int));
    b = (int *)malloc((2 * N - 1) * sizeof(int));
    c = (int *)malloc((2 * N - 1) * sizeof(int));
    for (i = 0; i < N; i++) a[i] = 1;
    for (i = 0; i < 2 * N - 1; i++) b[i] = 1;
    for (i = 0; i < 2 * N - 1; i++) c[i] = 1;
    Try(0);
    free(S);
    free(a);
    free(b);
    free(c);
    printf("\nSo luong cau hinh: %d\n", sol);
    return 0;
}

void Try(int i) {
    int j;
    for (j = 0; j < N; j++) {
        if (a[j] && b[i - j + N - 1] && c[i + j]) {
            S[i] = j;
            a[j] = 0;
            b[i - j + N - 1] = 0;
            c[i + j] = 0;
            if (i == N - 1) print();
            else Try(i + 1);
            a[j] = 1;
            b[i - j + N - 1] = 1;
            c[i + j] = 1;
        }
    }
}

void print() {
    int i;
    printf("\n\n%3d:", ++sol);
    for (i = 0; i < N; i++) printf("%d ", 1 + S[i]);
}
