//Write a C function to evaluate the series: sin(x) = x - (x^3 / 3!) + (x^5 / 5!) - (x^7 / 7!) ..... upto five significant figures.
#include<stdio.h>
#include<conio.h>
#include<math.h>
double series(double);		//prototype declaration
double factorial(double);	//use double as the powers and factorial values will get bigger than limit for int
int main(){
	double x, radian;
	printf("Enter x (in degrees): ");
	scanf("%lf", &x);
	radian = x * (3.14159 / 180);		//converting degrees to radians
	series(radian);
	return 0;
}
double series(double x){
	int i;
	double sum = 0, j;
	for(i = 0, j = 1; i < 10; i++, j += 2){
		sum = sum + (pow(-1, i) * (pow(x, j)/ factorial(j)));
		printf("%lf\n", sum);
	}
	printf("sin(x) = %lf", sum);
}
double factorial(double j){
	double f = 1;
	for(; j != 0; j--){
		f *= j; 
	}
	return f;
}
