//A 5-digit positive integer is entered through the keyboard, write a function to calculate sum of digits of the 5-digit number: without using recursion
int sumofdigits(int); //prototype declaration
int main(){
	int num, sum;
	printf("Enter a 5 digit number: ");
	scanf("%d", &num);
	sum = sumofdigits(num);
	printf("Sum = %d", sum);
	return 0;
}
sumofdigits(int num){
	int sum = 0, i;
	for(i = 1; i <= 5; i++){
		sum = sum + (num % 10);		//adds the units place digit
		num /= 10; 	//shifts digits to right	
	}
	return sum;
}
