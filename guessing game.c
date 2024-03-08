/*#include <stdio.h>
#include <stdlib.h>

int main (){
int secretnumber = 5; 
int guess;
while (guess != secretnumber)
{
printf("enter a number:");
scanf("%d",&guess);
}
printf("you win!");
return 0;
}*/
#include <stdio.h>
#include <stdlib.h>

int main (){
int secretnumber = 5; 
int guess;
int guesscount = 0;
int guesslimit=3;
int outofguesses=0;
while(guess != secretnumber && outofguesses == 0)
{
    if (guesscount < guesslimit)
{
    printf("enter a number:");
scanf("%d",&guess);
guesscount++;
if (guess == secretnumber) {
                printf("Congratulations! You guessed the secret number.\n");
            }
        } else {
            outofguesses = 1;
        }
    }

    if (outofguesses == 1) {
        printf("Out of guesses. You lose!\n");
    }return 0;
}