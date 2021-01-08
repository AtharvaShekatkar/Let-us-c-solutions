A 5-digit positive integer is entered through the keyboard, write a function to calculate sum of digits of the 5-digit number: using recursions
#include<stdio.h>
#include<conio.h>
#include<math.h>
int sumofdigits(int);
int main(){
	int num, sum;
	printf("Enter a 5 digit number: ");
	scanf("%d", &num);
	sum = sumofdigits(num);
	printf("Sum = %d", sum);
	return 0;
}
sumofdigits(int num){
	int sum;
	if(num == 0)	
		return 0;	//returns 0 after all digits are processed
	else
		sum = num % 10 + sumofdigits(num / 10); 	//calls function after shifting digits one place to the right
	return sum;
}
