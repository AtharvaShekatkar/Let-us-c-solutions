//A positive integer is entered through the keyboard, write a function to find the binary equivalent of this number using recursion.
#include<stdio.h>
#include<conio.h>
#include<math.h>
int binary(int);
int main(){
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("Binary equivalent of %d = ", num);
	binary(num);
	return 0;
}
binary(int num){
	if(num == 0)    
		return 0;
	else{
		binary(num / 2);          //since binary equivalent is printed in the reverse order of obtained remainders, we must complete the total required divisons before printing anything
		printf("%d", num % 2);
	}
}
