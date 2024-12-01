#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of points: ");
    scanf("%d", &n);
    float *fees = (float *)malloc(n * sizeof(float));
    float totalProfit = 0;
    for (int i = 0; i < n; i++) {
        printf("Enter fee for point %d: ", i + 1);
        scanf("%f", &fees[i]);
        if (fees[i] < 0) {
            printf("Invalid fee. Fee cannot be negative.\n");
            i--;
        } else {
            totalProfit += fees[i];
        }
    }
    printf("Total profit: %.2f\n", totalProfit);
    free(fees);
    return 0;
}


