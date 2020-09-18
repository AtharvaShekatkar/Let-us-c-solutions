//Ten numbers are entered from the keyboard into an array. Write a program to find out how many of them are positive, how many are negative, how many are even and how many odd.
#include<stdio.h>
#include<conio.h>
int main(){
    int arr[10], num, i, count_eve, count_odd, count_pos, count_neg;
    count_eve = count_odd = count_pos = count_neg = 0;
    printf("Filling array now:\n");
    for(i = 0; i <= 9; i++){
        printf("Enter a number: ");
        scanf("%d", arr + i);
    }
    printf("Array filled!\n");
    for(i = 0; i <= 9; i++){
        if (arr[i] > 0)
            count_pos += 1;
        else    
            count_neg += 1;
        if(arr[i] % 2 == 0)
            count_eve += 1;
        else
            count_odd += 1;
    }
    printf("Positive numbers in array = %d\n", count_pos);
    printf("Negative numbers in array = %d\n", count_neg);
    printf("Even numbers in array = %d\n", count_eve);
    printf("Odd numbers in array = %d\n", count_odd);
}
