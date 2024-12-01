#include <stdio.h>
#include <stdlib.h>

int main() {
    int numStudents;

    printf("Enter number of students: ");
    scanf("%d", &numStudents);
    int **grades = (int **)malloc(numStudents * sizeof(int *));
    for (int i = 0; i < numStudents; i++) {
        int numGrades;
        printf("Enter number of grades for student %d: ", i + 1);
        scanf("%d", &numGrades);
        grades[i] = (int *)malloc(numGrades * sizeof(int));

        printf("Enter the grades for student %d: ", i + 1);
        for (int j = 0; j < numGrades; j++) {
            scanf("%d", &grades[i][j]);
        }
    }
    for (int i = 0; i < numStudents; i++) {
        printf("\nGrades for student %d: ", i + 1);
        for (int j = 0; j < sizeof(grades[i]) / sizeof(grades[i][0]); j++) {
            printf("%d ", grades[i][j]);
        }
    }
    for (int i = 0; i < numStudents; i++) {
        free(grades[i]);
    }
    free(grades);

    return 0;
}

