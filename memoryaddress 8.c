#include <stdio.h>
#include <stdlib.h>
int main(){
  int age = 30;
  double gpa = 19.5;
  printf ("age :%p\ngpa :%p\n",&age,&gpa);
int *pAge = &age;
printf("age:%p\n ", pAge);
printf("%d\n",*&age);
printf("%d",&age);
  return 0;
}
