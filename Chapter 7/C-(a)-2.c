//Write down macro definitions for the following: To test whether a character entered is a upper case letter or not.
#include<math.h>
#include<stdio.h>
#include<conio.h>
#define TESTUPPERCASE (c >= 65 && c <= 90)
int main(){
    char c;
    printf("Enter a letter from the english alphabet: ");
    scanf("%c", &c);
    if(TESTUPPERCASE)
        printf("It's a uppercase letter!");
    else
        printf("It's not a uppercase letter.");
    getch();
    return 0;
}
