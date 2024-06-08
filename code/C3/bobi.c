#include <stdio.h>
#include <stdlib.h>

void liet_ke_bi_vao_hop(int n, int k, int pos, int remaining_balls, int current[], int **result, int *result_count) {
    if (pos == n) {
        if (remaining_balls == 0) {
            for (int i = 0; i < n; i++) {
                result[*result_count][i] = current[i];
            }
            (*result_count)++;
        }
        return;
    }

    for (int i = 0; i <= remaining_balls; i++) {
        current[pos] = i;
        liet_ke_bi_vao_hop(n, k, pos + 1, remaining_balls - i, current, result, result_count);
    }
}

int main() {
    int n = 10;  // Số hộp
    int k = 7;   // Số viên bi

    // Tính số lượng cách phân phối tối đa: (k+n-1) choose (n-1)
    int max_results = 1;
    for (int i = 1; i <= n - 1; i++) {
        max_results *= (k + i);
        max_results /= i;
    }

    // Cấp phát bộ nhớ cho result
    int **result = (int **)malloc(max_results * sizeof(int *));
    for (int i = 0; i < max_results; i++) {
        result[i] = (int *)malloc(n * sizeof(int));
    }

    int *current = (int *)calloc(n, sizeof(int));
    int result_count = 0;

    liet_ke_bi_vao_hop(n, k, 0, k, current, result, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("Combination %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < max_results; i++) {
        free(result[i]);
    }
    free(result);
    free(current);

    return 0;
}
