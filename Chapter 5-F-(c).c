//Write a function that receives marks received by a student in 3 subjects and returns the average and percentage of these marks. Call this function from main( ) and print the results in main( ).
#include<stdio.h>
#include<conio.h>
#include<math.h>
int calc(int, int, int, float *, float *);    //prototype declaration
int main(){
	int sub1, sub2, sub3;
	float avg, perc;
	printf("Enter marks received in subject 1 out of 100: ");
	scanf("%d", &sub1);
	printf("Enter marks received in subject 2 out of 100: ");
	scanf("%d", &sub2);
	printf("Enter marks received in subject 3 out of 100: ");
	scanf("%d", &sub3);
	calc(sub1, sub2, sub3, &avg, &perc);
	printf("Average marks = %f\n", avg);
	printf("Percentage = %f%\n", perc);
	return 0;
}
int calc(int sub1, int sub2, int sub3, float *avg, float *perc){    //using pointers to return more than one value
	*avg = (sub1 + sub2 + sub3) / 3.0;  
	*perc = ((sub1 + sub2 + sub3) / 300.0) * 100;
}
