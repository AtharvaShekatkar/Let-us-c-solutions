Write down macro definitions for the following: To find absolute value of a number.
#include<math.h>
#include<stdio.h>
#include<conio.h>
#define ABSOLUTEVAL(num) if(num < 0)\
num = -num;-6
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    ABSOLUTEVAL(num);
    printf("%d\n", num);
    getch();
    return 0;
}
