#include <stdio.h>
int main(void)
{
char color[20];
char puluralNoun[20];
char celeberityf [20];
char celeberityl [20];
printf("enter a color:\n");
scanf("%s", color );

printf("enter a puluralNoun:\n");
scanf("%s",puluralNoun);

printf("enter celebrity:\n");
scanf("%s %s",celeberityf,celeberityl);

printf("girls like %s\n",color);
printf(" %s are interesting.\n",puluralNoun);
printf("i love %s and %s.",celeberityf ,celeberityl);

return 0;
}






