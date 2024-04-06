#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_MESSAGES 100
#define MAX_SENDER_LEN 50
#define MAX_MESSAGE_LEN 100

struct Message {
    char sender[MAX_SENDER_LEN];
    char message[MAX_MESSAGE_LEN];
    time_t timestamp;
};

struct Message sentMessages[MAX_MESSAGES];
int messageCount = 0;

void displayMenu();
void sendMessage();
void viewMessagesBySender(); 

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice:");
        scanf("%d", &choice);
        while (getchar() != '\n'); 

        switch (choice) {
            case 1:
                sendMessage();
                break;
            case 2:
                viewMessagesBySender(); 
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again. \n");
        }
    } while (choice != 3);

    return 0;
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Send message\n");
    printf("2. View Messages by sender\n");
    printf("3. Exit\n");
}

void sendMessage() {
    char sender[MAX_SENDER_LEN];
    char message[MAX_MESSAGE_LEN];

    printf("Enter sender: ");
    scanf(" %[^\n]", sender);
    while (getchar() != '\n'); 

    printf("Enter message: ");
    scanf(" %[^\n]", message);
    while (getchar() != '\n'); 

    time_t now;
    time(&now);

    strcpy(sentMessages[messageCount].sender, sender);
    strcpy(sentMessages[messageCount].message, message);
    sentMessages[messageCount].timestamp = now;
    messageCount++;

    printf("Message sent successfully.\n");
}

void viewMessagesBySender() {
    char sender[MAX_SENDER_LEN];

    printf("Enter sender: ");
    scanf(" %[^\n]", sender);
    while (getchar() != '\n'); 

    printf("Messages sent to %s:\n", sender);
    int found = 0;
    for (int i = 0; i < messageCount; i++) {
        if (strcmp(sentMessages[i].sender, sender) == 0) {
            found = 1;
            printf("Message: %s\n", sentMessages[i].message);
            printf("Sent at: %s", ctime(&sentMessages[i].timestamp));
        }
    }
    if (!found) {
        printf("No messages found for %s.\n", sender);
    }
}