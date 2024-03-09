#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 10
#define MAX_NOME 15

struct product {
    char nome[MAX_NOME];
    float prizzo;
    int quantita;
};

struct product products[MAX_PRODUCTS]; 
int num_products = 0;


void add_product();
void edit_product();
void search_by_name();
void print_list();
void display_remaining_quantity();


int main(){
    int choice;

    do{
        printf("\n*******The menu*******\n");
        printf("1) Add product\n");
        printf("2) Edit product\n");
        printf("3) Search by name\n");
        printf("4) Print list\n");
        printf("5) Display remaining quantity after order\n");
        printf("0) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                edit_product();
                break;
            case 3:
                search_by_name();
                break;
            case 4:
                print_list();
                break;
            case 5:
                display_remaining_quantity();
                break;
            case 0:
                printf("Exiting Program...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        getchar();
    }while(choice != 0);

    return 0;
}


void add_product(){
    if (num_products >= MAX_PRODUCTS) {
        printf("Maximum number of products reached.\n");
        return;
    }

    printf("Enter product name: ");
    scanf(" %[^\n]", products[num_products].nome);
    
    for( int i = 0; i < num_products ; ++i){
        if(strcmp(products[num_products].nome, products[i].nome) == 0){
            printf("This name already exists in the List.\n");
            return;
        }
    }

    printf("Enter product price: ");
    scanf("%f", &products[num_products].prizzo);
    printf("Enter quantity: ");
    scanf("%d", &products[num_products].quantita);

    printf("Product added successfully.\n");
    num_products++;
    return;
}

void edit_product(){
    char search_name[MAX_NOME];
    printf("Enter the name of the product you want to change: ");
    scanf(" %[^\n]", search_name);

    int found = 0;
    for (int i = 0; i < num_products; ++i) {
        if (strcmp(products[i].nome, search_name) == 0) {
            printf("Enter new name: ");
            scanf(" %[^\n]", products[i].nome);
            printf("Enter new price: ");
            scanf("%f", &products[i].prizzo);
            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantita);
            printf("Product Updated Successfully.\n");
            found = 1;
            break; 
        }
    }
    if (!found) {
        printf("Product Doesn't Found.\n");
        return;
    }
}

void search_by_name(){
    char search_name[MAX_NOME];
    printf("Enter the name of the product you want to search for: ");
    scanf(" %[^\n]", search_name);
    
    for(int i = 0; i < num_products; ++i){
        if(strcmp(products[i].nome , search_name) == 0){
            printf("Name : %s , Price : %f , Quality: %d\n", products[i].nome , products[i].prizzo , products[i].quantita);
            return;
        }
    }
    printf ("Product not Found! ");
}

void print_list(){
    printf("Product list: \n");
    for (int i = 0; i < num_products; ++i) {
        printf("%d Name: %s, Price: %.2f, Quantity: %d\n", i+1, products[i].nome, products[i].prizzo, products[i].quantita);
    }
}

void display_remaining_quantity(){
    char search_name[MAX_NOME];

    printf("Enter the name of the product you've ordered: ");
    scanf(" %[^\n]", search_name);
    
    
    int ordered_quantity;
    printf("Enter the quantity you've ordered: ");
    scanf("%d", &ordered_quantity);


int found = 0;
    for (int i = 0; i < num_products; ++i) {
        if (strcmp(products[i].nome, search_name) == 0) {
            if (products[i].quantita >= ordered_quantity) {
                products[i].quantita -= ordered_quantity;
                printf("Remaining quantity of %s after order: %d\n", search_name, products[i].quantita);
            } else {
                printf("Ordered quantity exceeds available quantity.\n");
            }
            found = 1;
            break; 
        }

        if (!found)
        {
            printf("Produce not Found! \n");
        }
        
    }
}