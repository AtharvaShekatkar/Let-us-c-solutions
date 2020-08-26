Given three variables x, y, z write a function to circularly shift their values to right. In other words if x = 5, y = 8, z = 10 after circular shift y = 5, z = 8, x =10. Call the function with variables a, b, c to circularly shift values.
#include<stdio.h>
#include<conio.h>
#include<math.h>
int circularshift(int *, int *, int *);   //prototype declaration
int main(){
	int x, y, z;
	printf("Enter first number: ");
	scanf("%d", &x);
	printf("Enter second number: ");
	scanf("%d", &y);
	printf("Enter third number: ");
	scanf("%d", &z);
	printf("Before circular shift:\n");
	printf("x = %d\ty = %d\tz = %d\n", x, y, z);
	circularshift(&x, &y, &z);
	printf("After circular shift:\n");
	printf("x = %d\ty = %d\tz = %d\n", x, y, z);
	return 0;
}
int circularshift(int *a,int *b, int *c){     //shifts values to right
	int i;      
	i = *b;     
	*b = *a;
	*a = *c;
	*c = i;
}
