//program to find the prime factors of a given number
#include<stdio.h>
#include<conio.h>
#include<math.h>
int primeno(int);
int primefactor(int);
int main(){
	int number;
	printf("Enter a number: ");
	scanf("%d", &number);
	primefactor(number);
	return 0;
}
primefactor(int num){
	int i, j;
	printf("Prime factors of %d are: \n", num);
	for(i = 2; i <= num;){
		j = primeno(i);		//confirms if i is prime or not
		if(j && num % i == 0){
			printf("%d\n", i);
			num /= i;
		}
		else{
			i++;	//cannot be in for loop as a prime factor can be repeated more than once
			continue;
		}
	}
}
primeno(int i){
	int x, j;
	for(x = 2; x < i; x++){
		if(i % x == 0)
			break;
	}
	if(x == i)
		j = 1;
	else
		j = 0;
	return j;
}
