#include <stdio.h>
#include <stdlib.h>

typedef struct Box {
    int weight;
    struct Box *nestedBoxes;
    int nestedCount;
} Box;

int calculateTotalWeight(Box *box) {
    int totalWeight = box->weight;
    for (int i = 0; i < box->nestedCount; i++) {
        totalWeight += calculateTotalWeight(&box->nestedBoxes[i]);
    }
    return totalWeight;
}

void freeBox(Box *box) {
    for (int i = 0; i < box->nestedCount; i++) {
        freeBox(&box->nestedBoxes[i]);
    }
    if (box->nestedBoxes != NULL) {
        free(box->nestedBoxes);
    }
}

Box createBox() {
    Box box;
    printf("\nEnter the weight of this box (0 if it doesn't contain an item): ");
    scanf("%d", &box.weight);

    printf("Enter the number of nested boxes inside this box: ");
    scanf("%d", &box.nestedCount);

    if (box.nestedCount > 0) {
        box.nestedBoxes = (Box *)malloc(box.nestedCount * sizeof(Box));
        for (int i = 0; i < box.nestedCount; i++) {
            printf("\n--- Enter details for nested box %d ---\n", i + 1);
            box.nestedBoxes[i] = createBox();
        }
    } else {
        box.nestedBoxes = NULL;
    }

    return box;
}

int main() {
    printf("Create the main box:\n");
    Box mainBox = createBox();
    int totalWeight = calculateTotalWeight(&mainBox);
    printf("\nTotal weight of the box is: %d\n", totalWeight);
    freeBox(&mainBox);
    return 0;
}

