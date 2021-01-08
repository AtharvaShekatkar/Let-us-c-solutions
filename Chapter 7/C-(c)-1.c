//Write down macro definitions for the following: To find arithmetic mean of two numbers.
#include<math.h>
#include<stdio.h>
#include<conio.h>
#define ARMEAN(x, y) ((x + y) / 2.0)
int main(){
    int num1, num2;
    float mean;
    printf("Enter a number: ");
    scanf("%d", &num1);
    printf("Enter another number: ");
    scanf("%d", &num2);
    mean = ARMEAN(num1, num2);
    printf("Arithmetic Mean of %d and %d = %f", num1, num2, mean);
    getch();
    return 0;
}
