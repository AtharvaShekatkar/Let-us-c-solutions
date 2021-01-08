//Write macro definitions for the following: To obtain the bigger of two numbers.
#include<math.h>
#include<stdio.h>
#include<conio.h>
#define BIGGER(a, b) (a > b)      //can have a macro without arguments as well
int main(){
    int num1, num2;
    printf("Enter a number: ");
    scanf("%d", &num1);
    printf("Enter another number: ");
    scanf("%d", &num2);
    if(BIGGER(num1, num2))
        printf("%d is bigger", num1);
    else
        printf("%d is bigger", num2);
    getch();
    return 0;
}
