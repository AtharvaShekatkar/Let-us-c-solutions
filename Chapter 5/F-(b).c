//Write a function that receives 5 integers and returns the sum, average and standard deviation of these numbers. Call this function from main( ) and print the results in main( ).
#include<stdio.h>
#include<conio.h>
#include<math.h>
int stat(int, int, int, int, int, int *, float *, float *);
int main(){
	int num1, num2, num3, num4, num5, sum;
	float avg, std_dev;
	printf("Enter a number: ");
	scanf("%d", &num1);
	printf("Enter another number: ");
	scanf("%d", &num2);
	printf("Enter another number: ");
	scanf("%d", &num3);
	printf("Enter another number: ");
	scanf("%d", &num4);
	printf("Enter another number: ");
	scanf("%d", &num5);
	stat(num1, num2, num3, num4, num5, &sum, &avg, &std_dev);
	printf("Sum = %d\nAverage = %f\nStandard Deviation = %f", sum, avg, std_dev);
	return 0;
}
int stat(int num1, int num2, int num3, int num4, int num5, int *sum, float *avg, float *std_dev){
	*sum = num1 + num2 + num3 + num4 + num5;
	*avg = *sum/5.0;
	*std_dev = sqrt((((num1 - *avg)*(num1 - *avg))/5) + (((num2 - *avg)*(num2 - *avg))/5) + (((num3 - *avg)*(num3 - *avg))/5) + (((num4 - *avg)*(num4 - *avg))/5) + (((num5 - *avg)*(num5 - *avg))/5));
}
