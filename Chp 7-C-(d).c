Write macro definitions with arguments for calculation of Simple Interest and Amount. Store these macro definitions in a file called “interest.h”. Include this file in your program, and use the macro definitions for calculating simple interest and amount.
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<interest.h>    //custom made .h file as required, is uploaded on github under the main branch
int main(){
    float p, n, r, si, amt;
    printf("Enter Principal Amount: ");
    scanf("%f", &p);
    printf("Enter Number of Years: ");
    scanf("%f", &n);
    printf("Enter Rate of Interest: ");
    scanf("%f", &r);
    si = INTEREST(p, n, r);     
    amt = AMOUNT(p, si);        
    printf("Simple Inetrest = %f\tAmount = %f", si, amt); 
}
