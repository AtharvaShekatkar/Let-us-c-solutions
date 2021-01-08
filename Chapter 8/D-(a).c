//Twenty-five numbers are entered from the keyboard into an array. The number to be searched is entered through the keyboard by the user. Write a program to find if the number to be searched is present in the array and if it is present, display the number of times it appears in the array.
#include<stdio.h>
#include<conio.h>
int main(){
    int arr[25], num, i, count = 0;
    printf("Filling array now:\n");
    for(i = 0; i <= 9; i++){
        printf("Enter a number: ");
        scanf("%d", arr + i);
    }
    printf("Enter a number to be searched: ");
    scanf("%d", &num);
    for(i = 0; i <= 24; i++){
        if (num == arr[i])
        count += 1;
    }
    if(count == 0)
        printf("Entered number not present in array!\n");
    else
        printf("Entered number occurs %d times in array!\n", count);
}
