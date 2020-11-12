//Write a function to find the norm of a matrix. The norm is defined as the square root of the sum of squares of all elements in the matrix.
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
    int n, i;
    printf("Enter length of array: ");
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++){
        printf("Enter element %d: ", i);
        scanf("%d", &a[i]);
    }

    int sum = 0;
    for(i = 0; i < n; i++){
        sum += pow(a[i], 2);
    }
    float norm;
    norm = sqrt(sum);
    printf("Norm of given array is: %f", norm);
}
