#include <stdio.h>
#define n 7

int main(void){
int values [n];
int index;
for (index = 0 ; index < n ; ++index)
{
    printf("enter the value of element #%d\n", index);
    scanf("%d",&values[index]);
}
for(index=0 ; index < n ; ++index){
    printf("values[%d]=%d\t", index , values[index]);
}
return 0;
}