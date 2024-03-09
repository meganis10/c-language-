#include <stdio.h>
int main(){
int a;
int *p;
a = 5;
p = &a;
printf("%d\n",a);
*p = 8;
printf("%d\n",*p);
printf("%d\n",&p);
printf("%d\n",p);
printf("%d\n",p+1);
printf("size of integer is %d \n",sizeof(int));

return 0;
}