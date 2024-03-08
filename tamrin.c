/*#include <stdio.h>
int main (void){
double i , sum = 0;
scanf("%lf", &i);
while(i<=10){
sum += i ;
++i;
}
printf("sum = %.2lf\n",sum);*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILENAME "textfile.txt"
#define MAX_ROWS 30

void printFileContent();
void printFirstRow();
int countVowels();

int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1) Print the file's content\n");
        printf("2) Print the file's first row\n");
        printf("3) Count and print number of vowels in the text file\n");
        printf("0) Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printFileContent();
                break;
            case 2:
                printFirstRow();
                break;
            case 3:
                printf("Number of vowels in the file: %d\n", countVowels());
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 0 and 3.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

void printFileContent() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", FILENAME);
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
}

void printFirstRow() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", FILENAME);
        return;
    }
    char line[100];
    if (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
}

int countVowels() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", FILENAME);
        return -1; // Error code indicating failure
    }
    char c;
    int count = 0;
    while ((c = fgetc(file)) != EOF) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    fclose(file);
    return count;
}