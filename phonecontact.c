#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTERIES 12
#define MAX_LENGTH_NAME 20
#define MAX_LENGTH_PHONE 23

void addentry();            
void exactsearch();
void approximatesearch();
void printinglist();

struct entry 
{
    char name[MAX_LENGTH_NAME];
    char phone[MAX_LENGTH_PHONE];
};

struct entry contact[MAX_ENTERIES];
int num_entries = 0;

int main(void){
    int choice;
    do {
    printf("the menu\n");
    printf("1)add entry.\n");
    printf("2)exact search.\n");
    printf("3)approximate search.\n");
    printf("4)print list\n");
    printf("0)exit the menu\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        addentry();
        break;
    case 2:
        exactsearch();
         break;
    case 3:
        approximatesearch();
         break;
    case 4:
        printinglist();
         break;
    case 0:
        printf("exiting .......\n");
        exit(EXIT_SUCCESS);
    default:
        printf("invalid number.\n");
        break;
    }getchar();
}while (choice != 0);
return 0;
}

void addentry(){
if (num_entries >= MAX_ENTERIES )
{
    printf("list is full.\n");
    return;
} 
printf("Enter your name :");
scanf(" %[^\n]", contact[num_entries].name);

for(int i = 0 ; i < num_entries ; ++i){
if(strcmp(contact[num_entries].name , contact[i].name)==0){
    printf("Entery with same name exits.\n");
    return;
    } 
    }
printf("enter number of phone :");
scanf(" %[^\n]" , contact[num_entries].phone);
printf("you added successfuly");
num_entries++;
}

void exactsearch(){
char search_name[MAX_LENGTH_NAME];
printf("enter name :\n");
scanf(" %[^\n]", search_name);

for(int i = 0 ; i < num_entries; i++){
    if (strcmp(contact[num_entries].name ,search_name)!= 0)
    {
        printf(" name : %s , phone : %s\n",contact[i].name,contact[i].phone );
         return;
    } 
   }
 printf("no matching.\n");
}

void approximatesearch(){
char search_name [MAX_LENGTH_NAME];
printf("enter name :\n");
scanf(" %[^\n]", search_name );

int found = 0;
for(int i = 0 ; i < num_entries ; ++i ){
    if(strstr(contact[i].name ,search_name)!=NULL){
    printf("name : %s , phone : %s \n",contact[i].name,contact[i].phone);
found = 1;
}
}
if(!found){
    printf("no match!\n");
}
}
void printinglist(){
if(num_entries == 0){
    printf("it's empety.\n");
    return;

} printf("contact list:\n");

for (int i = 0; i < num_entries; i++)
{
    printf("%d)name : %s , phone : %s \n",i+1 ,contact[i].name,contact[i].phone);  
}
}