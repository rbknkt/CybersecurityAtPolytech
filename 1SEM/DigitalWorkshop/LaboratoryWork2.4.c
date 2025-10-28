#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int** matrix = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int*)malloc(N * sizeof(int));
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &matrix[0][i]);
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j + 1];
        }
        for (int j = N - i; j < N; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}