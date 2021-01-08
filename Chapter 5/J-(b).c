#include<stdio.h>
#include<conio.h>
#include<math.h>
int primeno(int);
int primefactor(int, int);
int main(){
	int num, i = 2;
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("\nPrime factors of %d are: ", num);
	primefactor(num, i);
	return 0;
}
primefactor(int num, int i){
	int j;
	j = primeno(i);
	if(num == 0)
		return 0;
	else if(j && num % i == 0){
		printf("\n%d", i);
		primefactor(num / i, i);
	}
	else{
		i++;
		primefactor(num, i);
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
