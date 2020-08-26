Write a function to compute the greatest common divisor given by Euclid’s algorithm
#include<stdio.h>
#include<conio.h>
#include<math.h>
int greatestdiv(int, int);
int main(){
	int num1, num2;
	printf("Enter first number: ");
	scanf("%d", &num1);
	printf("Enter second number: ");
	scanf("%d", &num2);
	greatestdiv(num1, num2);
	return 0;
}
int greatestdiv(int num1, int num2){
	int quo, rem, dividend, divisor;
	if(num1 > num2){                      //since here, dividend cannot be smaller than divisor
		dividend = num1;
		divisor = num2;
	}
	else{
		dividend = num2;
		divisor = num1;
	}
	for(; divisor != 0 ;){
		quo = dividend / divisor;
		rem = dividend - quo * divisor; 
		dividend = divisor;
		if(rem == 0)                      
			break;
		else
			divisor = rem;              //updates divisor only if rem != 0 since otherwise greatest common divisor will always be printed 0
	}
	printf("The greatest common divisor is = %d", divisor);
}
