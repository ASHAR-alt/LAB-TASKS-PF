#include <stdio.h>
#include <stdlib.h>
int main() {
    int capacity = 4, size = 0;
    float *arr = (float *)malloc(capacity * sizeof(float));
    while (1) {
        char choice;
        printf("Enter a number (a to add, d to display, r to remove, q to quit): ");
        scanf(" %c", &choice);
        if (choice == 'a') {
            if (size == capacity) {
                capacity *= 2;
                arr = (float *)realloc(arr, capacity * sizeof(float)); }
            printf("Enter a number: ");
            scanf("%f", &arr[size]);
            size++;
        } else if (choice == 'd') {
            printf("Array: ");
            for (int i = 0; i < size; i++) {
                printf("%.2f ", arr[i]);
            }
            printf("\n");
        } else if (choice == 'r' && size > 0) {
            size--;
        } else if (choice == 'q') {
            break;
        }
    }
    free(arr);
    return 0; }

