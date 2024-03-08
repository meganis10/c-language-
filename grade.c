 #include<stdio.h>
#include<stdlib.h>
int main(){
    char grade;
    printf("Your score: ");
    scanf("%c", &grade);

    if (grade == 'A'){
        printf("You did great! ");
    }else if(grade == 'B'){
        printf("You did it alright! ");
    }else if(grade == 'C'){
        printf("You did it good! ");
    }else if(grade == 'D'){
        printf("You did it poor! ");
    }else if(grade == 'E'){
        printf("You did it ver poor! ");
    }else if(grade == 'F'){
        printf("You did it Fuck! ");
    }else{
        printf("Invalid Score!!! ");
    }
    
    return 0;











}
