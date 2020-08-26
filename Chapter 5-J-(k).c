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
		divisor = rem;
	}
	printf("The greatest common divisor is = %d", dividend);	//printing dividend because dividend becomes divisorin every iteration. in the final iteration, divisor becomes 0
}
