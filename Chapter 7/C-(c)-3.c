//Write down macro definitions for the following: To convert a uppercase alphabet to lowercase.
#include<math.h>
#include<stdio.h>
#include<conio.h>
#define UPPERTOLOWER(ch) (ch = (ch - 65) + 97)    //using ascii values of upper case and smaller case letters 
int main(){
    char c;
    printf("Enter an uppercase letter: ");
    scanf("%c", &c);
    UPPERTOLOWER(c);
    printf("%c\n", c);
    getch();
    return 0;
}
