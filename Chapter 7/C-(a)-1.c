//Write down macro definitions for the following: To test whether a character entered is a small case letter or not.
#include<math.h>
#include<stdio.h>
#include<conio.h>
#define TESTSMALLCASE (c >= 97 && c <= 122)
int main(){
    char c;
    printf("Enter a letter from the english alphabet: ");
    scanf("%c", &c);
    if(TESTSMALLCASE)
        printf("It's a smallcase letter!");
    else
        printf("It's not a smallcase letter.");
    getch();
    return 0;
}
