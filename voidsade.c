#include <stdio.h>

#include <math.h>
void sayHi( );
int main(){
sayHi ("ali", 23);
sayHi ("mike",66);
return 0;
}

void sayHi (char name [], int age ){
    printf("hello %s, you are %d old.\n", name, age );
}


