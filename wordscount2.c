#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_LINE_LENGTH 1000

void countLines(FILE *file);
void countCharacters(FILE *file);
void countWords(FILE *file);
void countVowelsConsonants(FILE *file, int *vowels, int *consonants);
void countPunctuation(FILE *file);
void checkIsUpperLower(FILE *file);

int main() {
    char filename[100];
    FILE *file;
    int choice;
    int vowels = 0, consonants = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    do {
        printf("\nMenu:\n");
        printf("1. Count lines\n");
        printf("2. Count characters\n");
        printf("3. Count words\n");
        printf("4. Count vowels and consonants\n");
        printf("5. Count punctuation symbols\n");
        printf("6. Check for uppercase and lowercase letters\n");
        printf("7. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
       
        switch (choice) {
            case 1:
                countLines(file);
                break;
            case 2:
                countCharacters(file);
                break;
            case 3:
                countWords(file);
                break;
            case 4:
                countVowelsConsonants(file, &vowels, &consonants);
                printf("Number of vowels: %d\n", vowels);
                printf("Number of consonants: %d\n", consonants);
                break;
            case 5:
                countPunctuation(file);
                break;
            case 6:
                checkIsUpperLower(file);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 7);

    fclose(file);
    return 0;
}

void countLines(FILE *file) {
    int count = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (c == '\n')
            count++;
    }

    fseek(file, 0, SEEK_SET);
    printf("Number of lines: %d\n", count); 
}

void countCharacters(FILE *file) {
    int count = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        count++;
    }

    fseek(file, 0, SEEK_SET);
    printf("Number of characters: %d\n", count);
 
}

void countWords(FILE *file) {
    int count = 0;
    char word[1000];

    while (fscanf(file, "%s", word) == 1)
        count++;

    fseek(file, 0, SEEK_SET);
    printf("Number of words: %d\n", count);

   
}

void countVowelsConsonants(FILE *file, int *vowels, int *consonants) {
    char c;

    *vowels = *consonants = 0;

    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                (*vowels)++;
            else
                (*consonants)++;
        }
    }

    fseek(file, 0, SEEK_SET);
    
}

void countPunctuation(FILE *file) {
    int count = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (ispunct(c))
            count++;
    }

    fseek(file, 0, SEEK_SET);
    printf("Number of punctuation symbols: %d\n", count);
    
}

void checkIsUpperLower(FILE *file) {
    int upper_count = 0, lower_count = 0;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (isupper(c))
            upper_count++;
        else if (islower(c))
            lower_count++;
    }

    fseek(file, 0, SEEK_SET);

    printf("Number of uppercase letters: %d\n", upper_count);
    printf("Number of lowercase letters: %d\n", lower_count);
}