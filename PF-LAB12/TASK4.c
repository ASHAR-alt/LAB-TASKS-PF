#include <stdio.h>
#include <stdlib.h>
int findHighestFrequency(int *arr, int size) {
    int *freq = (int *)calloc(10001, sizeof(int));

    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }
    int maxFreq = 0, numWithMaxFreq = 0;
    for (int i = 1; i <= 10000; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            numWithMaxFreq = i;
        }    }
    free(freq);
    return numWithMaxFreq;
}
int main() {
    int T;
    printf("Enter number of test cases: ");
    scanf("%d", &T);
    while (T--) {
        int N;
        printf("Enter number of elements: ");
        scanf("%d", &N);
        int *arr = (int *)malloc(N * sizeof(int));
        printf("Enter the sequence: ");
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        printf("Number with highest frequency: %d\n", findHighestFrequency(arr, N));
        free(arr);
    }
    return 0;}
    
