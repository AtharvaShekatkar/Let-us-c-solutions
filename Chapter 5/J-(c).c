//Write a recursive function to obtain the first 25 numbers of a Fibonacci sequence. In a Fibonacci sequence the sum of two successive terms gives the third term.Following are the first few terms of the Fibonacci sequence: 1 1 2 3 5 8 13 21 34 55 89....
#include<stdio.h>
#include<conio.h>
#include<math.h>
int fibonacci(int, int, int);
int main(){
	int i = 1, j = 1, k = 1;  
	fibonacci(i, j, k);
	return 0;
}
fibonacci(int i, int j, int k){
	if(k % 2 == 0 && k <= 25){    //prints i if k is odd and j if k is even
		k++;
		printf("%d  ", j);
		j = j + i;    //j gets incremented to next required value
		fibonacci(i, j, k);
	}
	else if(k % 2 != 0 && k <= 25){
		k++;
		printf("%d  ", i);
		i = i + j;    //i gets incremented to next required value
		fibonacci(i, j, k);
	}
	else
		return 0;
}
