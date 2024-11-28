#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILE_NAME "books.txt"
typedef struct {
    int id;
    char title[50];
    char author[50];
    int quantity;
    float price;
} Book;
void addBook();
void viewBooks();
void searchBook();
void updateBook();
void deleteBook();
void calculateInventoryValue();
int checkDuplicateID(int id);
int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add New Book\n");
        printf("2. View All Books\n");
        printf("3. Search for a Book\n");
        printf("4. Update Book Details\n");
        printf("5. Delete a Book Record\n");
        printf("6. Calculate Total Inventory Value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                updateBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                calculateInventoryValue();
                break;
            case 7:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
void addBook() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    Book book;
    printf("Enter Book ID: ");
    scanf("%d", &book.id);
    if (checkDuplicateID(book.id)) {
        printf("Error: Duplicate Book ID.\n");
        fclose(file);
        return;
    }
    printf("Enter Title: ");
    scanf(" %[^\n]", book.title);
    printf("Enter Author: ");
    scanf(" %[^\n]", book.author);
    printf("Enter Quantity: ");
    scanf("%d", &book.quantity);
    printf("Enter Price: ");
    scanf("%f", &book.price);

    if (book.quantity < 0 || book.price < 0) {
        printf("Error: Quantity and price must be non-negative.\n");
        fclose(file);
        return;
    }

    fprintf(file, "%d|%s|%s|%d|%.2f\n", book.id, book.title, book.author, book.quantity, book.price);
    fclose(file);
    printf("Book added successfully.\n");
}
void viewBooks() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error: No records found.\n");
        return;
    }
    Book book;
    printf("\n%-5s %-30s %-30s %-10s %-10s\n", "ID", "Title", "Author", "Quantity", "Price");
    printf("-----------------------------------------------------------------------------\n");

    while (fscanf(file, "%d|%49[^|]|%49[^|]|%d|%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
        printf("%-5d %-30s %-30s %-10d %-10.2f\n", book.id, book.title, book.author, book.quantity, book.price);
    }
    fclose(file);
}
void searchBook() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error: No records found.\n");
        return;
    }

    int searchID;
    char searchTitle[50];
    int choice, found = 0;

    printf("Search by:\n1. ID\n2. Title\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Book ID: ");
        scanf("%d", &searchID);
        Book book;
        while (fscanf(file, "%d|%49[^|]|%49[^|]|%d|%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
            if (book.id == searchID) {
                printf("\nBook Found:\n");
                printf("ID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\nPrice: %.2f\n", book.id, book.title, book.author, book.quantity, book.price);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        printf("Enter Book Title: ");
        scanf(" %[^\n]", searchTitle);
        Book book;
        while (fscanf(file, "%d|%49[^|]|%49[^|]|%d|%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
            if (strcmp(book.title, searchTitle) == 0) {
                printf("\nBook Found:\n");
                printf("ID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\nPrice: %.2f\n", book.id, book.title, book.author, book.quantity, book.price);
                found = 1;
                break;
            }
        }
    } else {
        printf("Invalid choice.\n");
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(file);
}

void updateBook() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error: No records found.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error opening temporary file.\n");
        fclose(file);
        return;
    }

    int updateID, found = 0;
    printf("Enter Book ID to update: ");
    scanf("%d", &updateID);

    Book book;
    while (fscanf(file, "%d|%49[^|]|%49[^|]|%d|%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
        if (book.id == updateID) {
            printf("Enter new Quantity: ");
            scanf("%d", &book.quantity);
            printf("Enter new Price: ");
            scanf("%f", &book.price);

            if (book.quantity < 0 || book.price < 0) {
                printf("Error: Quantity and price must be non-negative.\n");
                fclose(file);
                fclose(tempFile);
                remove("temp.txt");
                return;
            }

            found = 1;
        }
        fprintf(tempFile, "%d|%s|%s|%d|%.2f\n", book.id, book.title, book.author, book.quantity, book.price);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("Book updated successfully.\n");
    } else {
        printf("Book ID not found.\n");
        remove("temp.txt");
    }
}

void deleteBook() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error: No records found.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error opening temporary file.\n");
        fclose(file);
        return;
    }

    int deleteID, found = 0;
    printf("Enter Book ID to delete: ");
    scanf("%d", &deleteID);

    Book book;
    while (fscanf(file, "%d|%49[^|]|%49[^|]|%d|%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
        if (book.id != deleteID) {
            fprintf(tempFile, "%d|%s|%s|%d|%.2f\n", book.id, book.title, book.author, book.quantity, book.price);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("Book deleted successfully.\n");
    } else {
        printf("Book ID not found.\n");
        remove("temp.txt");
    }
}
void calculateInventoryValue() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Error: No records found.\n");
        return;
    }
    Book book;
    float totalValue = 0;
    while (fscanf(file, "%d|%49[^|]|%49[^|]|%d|%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
        totalValue += book.quantity * book.price;
    }

    fclose(file);
    printf("Total Inventory Value: %.2f\n", totalValue);
}

int checkDuplicateID(int id) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        return 0;
    }

    Book book;
    while (fscanf(file, "%d|%49[^|]|%49[^|]|%d|%f\n", &book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
        if (book.id == id) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

