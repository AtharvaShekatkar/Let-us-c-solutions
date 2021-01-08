//Write a recursive function to obtain the running sum of first 25 natural numbers.
#include<stdio.h>
#include<conio.h>
#include<math.h>
int calsum(int);
int main(){
	int sum, i = 1;
	sum = calsum(i);
	printf("Sum = %d", sum);
	return 0;
}
calsum(int i){
	int sum;
	if(i == 26)
		return 0;               //returns 0 since we don't want any additions after first 25 numbers
	sum = i + calsum(i + 1);    //calls function again until i reaches 26
	return sum;
}
