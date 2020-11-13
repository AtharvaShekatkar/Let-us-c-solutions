//program to find product of int and float using a function
#include<stdio.h>
#include<conio.h>
#include<math.h>
float product(float, int); //prototype declaration
int main(){
	float num1, prod;
	int num2;
	printf("Enter a number: ");
	scanf("%f", &num1);
	printf("Enter another number: ");
	scanf("%d", &num2);
	prod = product(num1, num2);
	printf("product of %f and %d is = %f", num1, num2, prod);
	return 0;
}
float product(float a, int b){
	float prod;
	prod = a * b;
	return prod;
}
