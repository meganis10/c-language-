#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_name 20
#define max_phone 12
#define max_input 10

struct entry {
 char name[max_name];
 char phone[max_phone];
};

struct entry contact[max_input];
int num_entries = 0;

void addentry();
void exactsearch();
void approximatesearch();
void editcontact();
void printinglist();

int main(){
    int choice;

    do {
    printf("\nthe menu\n");
    printf("1)add entry.\n");
    printf("2)editing contact.\n");
    printf("3)approximate search.\n");
    printf("4)exact search.\n");
    printf("5)print list.\n");
    printf("0)exit the menu.\n");
    scanf("%d", &choice);
    
    switch(choice){
    case 1:
    addentry();
    break;
    case 2:
    editcontact();
    break;
    case 3:
    approximatesearch();
    break;
    case 4:
    exactsearch();
    break;
    case 5:
    printinglist();
    break;
    case 0:
    printf("exiting......\n");
    exit(EXIT_SUCCESS);
}
}while(choice != 0);

return 0;
}

void addentry(){
    if (num_entries > max_input){
        printf("it's full.\n");
    }
    printf("enter name : ");
    scanf(" %[^\n]", contact[num_entries].name);
    for( int i = 0 ; i < num_entries ; ++i){
        if(strcmp(contact[num_entries].name , contact[i].name) == 0){
            printf("this name exists in list.\n");
            
            return;
        }
    }
    printf("enter number of phone :");
    scanf(" %[^\n]", contact[num_entries].phone);
    printf("you added successfuly\n");
    num_entries++;
}

void editcontact(){
    char search_name[max_name];
    printf("enter your name :\n");
    scanf(" %[^\n]", search_name);
        int found = 0;  
        for(int i = 0 ; i < num_entries ; ++i){
            if(strcmp(contact[i].name , search_name) ==0){
                printf("enter new name : ");
                scanf(" %[^\n]", contact[i].name);
                printf("enter new phone number : ");
                scanf(" %[^\n]", contact[i].phone);
                found =1 ; 
                break;
            }
            }
            if(!found) {
                printf("Entery not found.\n");

}
}
void exactsearch(){
    char search_name[max_name];
    printf("enter name :");
    scanf(" %[^\n]" , search_name);
    for(int i = 0; i < num_entries ; ++i){
        if(strcmp(contact[i].name , search_name)== 0){
            printf("name : %s , phone : %s", contact[i].name , contact[i].phone);
            return;
        }
    }printf ("no amtching!");
}

void approximatesearch(){
    char search_name[max_name];
    printf("enter name :");
    scanf(" %[^\n]" , search_name);
    int found = 0;
    for(int i = 0; i < num_entries ; ++i){
        if(strstr( contact[i].name , search_name)!=NULL){
            printf("name : %s , phone : %s", contact[i].name , contact[i].phone);
            found = 1;
            return;
        }
    }if(!found)
    {printf ("no amtching!");
}
}
void printinglist(){
    if(num_entries == 0){
        printf("it's empety\n");
        return;

    } printf("contact listis here.\n"); 
    for(int i = 0 ; i < num_entries ; i++){
        printf("%d) name: %s , phone: %s\n ", i+1 , contact[i].name , contact[i].phone);
    }
}