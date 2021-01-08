//Write a program to pick up the largest number from any 5 row by 5 column matrix.
#include <stdio.h>
#include <conio.h>
int findlargest(int (*)[5]);
int main()
{
    int a[5][5] = {           //initializing 5x5 matrix
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 32, 185, 25}
    };
    int largest = findlargest(a);
    printf("Largest element is = %d", largest);
}
int findlargest(int (*p)[5]){
    int largest = 0, i;
    int *ptr;
    ptr = p[0];       //pointer to  first array in p
    for(i = 0; i < 25; i++){
       if(largest < *ptr){
           largest = *ptr;
       }
       ptr++;
    }
    return largest;
}
