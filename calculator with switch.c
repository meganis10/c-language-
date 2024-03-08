#include <stdio.h>
#include <stdlib.h>

int main(){

char operator;
printf("choose an operator ['+','-','*','/']:");
scanf("%c", &operator);

double num1 , num2;
printf("enter first number:");
scanf ("%lf", &num1 );
printf("enter your second number");
scanf("%lf", &num2 );

double result;

switch(operator){
case '+':
result = num1 + num2 ;
break ; 
case '-':
result = num1 - num2;
break;
case '*':
result = num1 * num2;
break;
case '/':
result = num1 / num2;
break;
}
printf ("your answer is:%.2f",result);
return 0;
}