//Write down macro definitions for the following: To test whether a character is an alphabet or not. Make use of the macros you defined in (1) and (2) above.
#include<math.h>
#include<stdio.h>
#include<conio.h>
#define TESTUPPERCASE (c >= 65 && c <= 90)
#define TESTSMALLCASE (c >= 97 && c <= 122)
int main(){
    char c;
    printf("Enter a letter: ");
    scanf("%c", &c);
    if(TESTUPPERCASE || TESTSMALLCASE)
        printf("It's a letter from the english alphabet!");
    else
        printf("It's not a letter from the english alphabet.");
    getch();
    return 0;
}
