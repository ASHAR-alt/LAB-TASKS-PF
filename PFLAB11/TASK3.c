#include <stdio.h>
int main() {
    FILE *sourceFile, *destFile;
    char sourceFileName[100], destFileName[100];
    char ch;
    printf("Enter the name of the source file: ");
    scanf("%s", sourceFileName);
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error: Could not open the source file.\n");
        return 1;
    }
    printf("Enter the name of the destination file: ");
    scanf("%s", destFileName);
    destFile = fopen(destFileName, "w");
    if (destFile == NULL) {
        printf("Error: Could not open the destination file.\n");
        fclose(sourceFile);
        return 1;
    }
    while ((ch = fgetc(sourceFile)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - ('a' - 'A');
        }
        fputc(ch, destFile);
    }
    printf("File copied successfully with lowercase converted to uppercase.\n");
    fclose(sourceFile);
    fclose(destFile);
    return 0;}

