#include <stdio.h>
#include <string.h>

typedef struct {
char name[15];
char password[15];
int id;
} User; 

int main(){

User user1 = {"ali", "pass1234", 562817};
User user2 = {"mamad","pass23",552266};


printf("%s ", user1 .name);
printf("%s ", user1.password);
printf("%d ", user1.id);
printf("\n");
printf("%s ", user2.name);
printf("%s ", user2.password);
printf("%d ", user2.id);
}