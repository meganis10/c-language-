#include <stdio.h>
/*int max (int num1 , int num2){
int result ;
if ( num1 > num2){
    result = num1;
}else {
    result = num2;
}
return result;

}

int main(){
    printf("%d",max(4,10));
return 0;
}*/


int max (int num1 , int num2 , int num3 ){
int result;
if( num1>= num2 && num1>=num3){
result = num1;
}else if (num2 >= num1 && num2 >= num3){
result = num2;} 
else {
    result = num3 ;
} return result;}
int main()
{
/*printf("%d",max(1,2,3));*/
int num1, num2, num3, result;
    
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter third number: ");
    scanf("%d", &num3);

    result = max(num1, num2, num3);

    printf("The biggest number is %d.", result);

    return 0;
return 0;
}
