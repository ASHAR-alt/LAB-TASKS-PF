#include <stdio.h>
#include <stdlib.h>

void insert(int **arr, int *size, int pos, int value) {
    if (*size == 0) {
        *arr = (int *)malloc(sizeof(int));
        (*arr)[0] = value;
        (*size)++;
        return;
    }

    *arr = (int *)realloc(*arr, (*size + 1) * sizeof(int));

    for (int i = *size; i > pos; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[pos] = value;
    (*size)++;
}

void delete(int **arr, int *size, int pos) {
    for (int i = pos; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    (*size)--;
}

int main() {
    int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int choice, pos, value;
    printf("Enter operation (1 for insert, 2 for delete): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter position and value to insert: ");
        scanf("%d %d", &pos, &value);
        insert(&arr, &size, pos, value);
    } else if (choice == 2) {
        printf("Enter position to delete: ");
        scanf("%d", &pos);
        delete(&arr, &size, pos);
    }

    printf("Updated array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

