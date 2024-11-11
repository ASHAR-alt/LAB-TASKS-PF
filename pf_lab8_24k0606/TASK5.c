#include <stdio.h>

void sort_column(int matrix[][4], int col) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (matrix[j][col] < matrix[i][col]) {
                int temp = matrix[i][col];
                matrix[i][col] = matrix[j][col];
                matrix[j][col] = temp;
            }
        }
    }
}

int main() {
    int matrix[4][4];

    printf("Enter the scores for 4 teams across 3 rounds:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal Score:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++) {
        sort_column(matrix, i);
    }

    printf("\nScore sorted in ascending order:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
