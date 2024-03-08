#include <stdio.h>
int main()
{
    int n , triangular;
triangular = 0 ;
for(n=1 ; n<=200; n++ ){
triangular += n;}
printf("the 200th triangular is %d", triangular);
return 0;
}